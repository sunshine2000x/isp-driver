// See LICENSE file for licence details.
#include <stdbool.h>
#include <string.h>

#include "cam_errors.h"
#include "cam_osal.h"
#include "isp.h"
#include "isp_module.h"
#include "isp_params.h"
#include "log.h"

#include "isp_api.h"

struct isp_ctx {
    struct isp isp;
    struct cam_lock *lock;
    struct isp_module *push_module, *pop_module, *irq_module;
    struct isp_module **modules;
    uint32_t nr_modules;
    uint32_t id;
    bool initialized;
};

static int isp_close(struct isp **isp)
{
    struct isp_ctx *ctx;
    struct isp_module *module;
    const char *name;
    size_t i;
    int rc;

    if (!isp)
        return ERR_WRONG_ARGS;

    ctx = (struct isp_ctx *)*isp;
    cam_lock(ctx->lock);
    if (ctx->irq_module)
        isp_unregister_irq(*isp, ctx->irq_module);
    for (i = 0; i < ctx->nr_modules; i++) {
        module = ctx->modules[i];
        if (module && module->api->close) {
            name = module->name;
            rc = module->api->close(&ctx->modules[i]);
            if (rc < 0) {
                LOGE("failed to call %s's close (err=%d).\n", name, rc);
                cam_unlock(ctx->lock);
                return rc;
            }
        }
    }
    cam_free(ctx->modules);
    cam_unlock(ctx->lock);
    destroy_lock(&ctx->lock);
    cam_free(ctx);
    *isp = NULL;
    return 0;
}

static int isp_init(struct isp *isp)
{
    struct isp_ctx *ctx = (struct isp_ctx *)isp;
    size_t i, j;
    int rc = 0;

    if (!isp)
        return ERR_WRONG_ARGS;

    cam_lock(ctx->lock);
    if (ctx->initialized)
        goto _exit;

    if (!nr_modules) {
        LOGW("there's no module defined for isp.\n");
        goto _exit;
    }

    ctx->modules =
        (struct isp_module **)cam_alloc(nr_modules * sizeof(*ctx->modules));
    if (!ctx->modules) {
        LOGE("failed to alloc memory for modules.\n");
        rc = ERR_NO_MEM;
        goto _exit;
    }

    for (i = 0; i < nr_modules; i++) {
        if (!modules[i])
            continue;
        rc = modules[i](&ctx->isp, ctx->id, &ctx->modules[i]);
        if (rc < 0) {
            LOGE("failed to call modules[%d]'s open (err=%d).\n", i, rc);
            goto _exit1;
        }
        if (ctx->modules[i]->api->push)
            ctx->push_module = ctx->modules[i];
        if (ctx->modules[i]->api->pop)
            ctx->pop_module = ctx->modules[i];
        if (ctx->modules[i]->api->irq)
            ctx->irq_module = ctx->modules[i];
    }
    ctx->nr_modules = nr_modules;

    if (ctx->irq_module) {
        rc = isp_register_irq(isp, ctx->irq_module);
        if (rc < 0) {
            LOGE("failed to register irq (err=%d).\n", rc);
            goto _exit1;
        }
    } else {
        LOGW("no isp module to handle irq was found.\n");
    }

    ctx->initialized = true;
    cam_unlock(ctx->lock);
    return 0;

_exit1:
    for (j = 0; j < i; j++)
        if (ctx->modules[j] && ctx->modules[i]->api->close)
            ctx->modules[i]->api->close(&ctx->modules[i]);
    cam_free(ctx->modules);
_exit:
    cam_unlock(ctx->lock);
    return rc;
}

static int isp_config(struct isp *isp, struct isp_params *params)
{
    struct isp_ctx *ctx = (struct isp_ctx *)isp;
    struct isp_module *module;
    int rc = 0;

    if (!isp || !params)
        return ERR_WRONG_ARGS;

    cam_lock(ctx->lock);
    if (!ctx->initialized) {
        LOGE("isp had not been initialized yet.\n");
        rc = ERR_WRONG_STATE;
        goto _exit;
    }

    if (params->index >= ctx->nr_modules) {
        LOGE("module index (%d) in isp params is out of bounds (%d).\n",
             params->index, ctx->nr_modules);
        rc = ERR_OUT_OF_BOUNDS;
        goto _exit;
    }

    module = ctx->modules[params->index];
    if (module && module->api->config) {
        rc = module->api->config(module, params);
        if (rc < 0)
            LOGE("failed to call %s's config (err=%d).\n", module->name, rc);
    }
_exit:
    cam_unlock(ctx->lock);
    return rc;
}

static int isp_reset(struct isp *isp)
{
    struct isp_ctx *ctx = (struct isp_ctx *)isp;
    struct isp_module *module;
    size_t i;
    int rc = 0;

    if (!isp)
        return ERR_WRONG_ARGS;

    cam_lock(ctx->lock);
    if (!ctx->initialized) {
        LOGE("isp had not been initialized yet.\n");
        rc = ERR_WRONG_STATE;
        goto _exit;
    }

    for (i = 0; i < ctx->nr_modules; i++) {
        module = ctx->modules[i];
        if (module && module->api->reset) {
            rc = module->api->reset(module);
            if (rc < 0) {
                LOGE("failed to call %s's reset (err=%d).\n", module->name, rc);
                goto _exit;
            }
        }
    }
_exit:
    cam_unlock(ctx->lock);
    return rc;
}

static int isp_start(struct isp *isp)
{
    struct isp_ctx *ctx = (struct isp_ctx *)isp;
    struct isp_module *module;
    size_t i;
    int rc = 0;

    if (!isp)
        return ERR_WRONG_ARGS;

    cam_lock(ctx->lock);
    if (!ctx->initialized) {
        LOGE("isp had not been initialized yet.\n");
        rc = ERR_WRONG_STATE;
        goto _exit;
    }

    for (i = 0; i < ctx->nr_modules; i++) {
        module = ctx->modules[i];
        if (module && module->api->enable) {
            rc = module->api->enable(module);
            if (rc < 0) {
                LOGE("failed to call %s's enable (err=%d).\n", module->name,
                     rc);
                goto _exit;
            }
        }
    }
_exit:
    cam_unlock(ctx->lock);
    return rc;
}

static int isp_stop(struct isp *isp)
{
    struct isp_ctx *ctx = (struct isp_ctx *)isp;
    struct isp_module *module;
    int i, rc = 0;

    if (!isp)
        return ERR_WRONG_ARGS;

    cam_lock(ctx->lock);
    if (!ctx->initialized) {
        LOGE("isp had not been initialized yet.\n");
        rc = ERR_WRONG_STATE;
    }

    if (!ctx->nr_modules)
        goto _exit;

    for (i = ctx->nr_modules - 1; i >= 0; i--) {
        module = ctx->modules[i];
        if (module && module->api->disable) {
            rc = module->api->disable(module);
            if (rc < 0) {
                LOGE("failed to call %s's disable (err=%d).\n", module->name,
                     rc);
                goto _exit;
            }
        }
    }
_exit:
    cam_unlock(ctx->lock);
    return 0;
}

static int isp_push(struct isp *isp, const struct cam_framedesc *in,
                    const struct cam_framedesc *out)
{
    struct isp_ctx *ctx = (struct isp_ctx *)isp;
    int rc;

    if (!isp)
        return ERR_WRONG_ARGS;

    cam_lock(ctx->lock);
    if (!ctx->initialized) {
        LOGE("isp had not been initialized yet.\n");
        rc = ERR_WRONG_STATE;
        goto _exit;
    }

    if (!ctx->push_module) {
        LOGE("no isp module to push was found.\n");
        rc = ERR_WRONG_STATE;
        goto _exit;
    }

    rc = ctx->push_module->api->push(ctx->push_module, in, out);
    if (rc < 0)
        LOGE("failed to call %s's push (err=%d).\n", ctx->push_module->name,
             rc);
_exit:
    cam_unlock(ctx->lock);
    return rc;
}

static int isp_pop(struct isp *isp, struct cam_framedesc *in,
                   struct cam_framedesc *out)
{
    struct isp_ctx *ctx = (struct isp_ctx *)isp;
    int rc;

    if (!isp)
        return ERR_WRONG_ARGS;

    cam_lock(ctx->lock);
    if (!ctx->initialized) {
        LOGE("isp had not been initialized yet.\n");
        rc = ERR_WRONG_STATE;
        goto _exit;
    }

    if (!ctx->pop_module) {
        LOGE("no isp module to pop was found.\n");
        rc = ERR_WRONG_STATE;
        goto _exit;
    }

    rc = ctx->pop_module->api->pop(ctx->pop_module, in, out);
    if (rc < 0)
        LOGE("failed to call %s's pop (err=%d).\n", ctx->pop_module->name, rc);
_exit:
    cam_unlock(ctx->lock);
    return rc;
}

static int isp_subscribe(struct isp *isp, const struct subscriber *sub)
{
    struct isp_ctx *ctx = (struct isp_ctx *)isp;
    int rc;

    if (!isp)
        return ERR_WRONG_ARGS;

    cam_lock(ctx->lock);
    if (!ctx->initialized) {
        LOGE("isp had not been initialized yet.\n");
        rc = ERR_WRONG_STATE;
        goto _exit;
    }

    if (!ctx->irq_module) {
        LOGE("no isp module to subscribe was found.\n");
        rc = ERR_WRONG_STATE;
        goto _exit;
    }

    rc = ctx->irq_module->api->subscribe(ctx->irq_module, sub);
    if (rc < 0)
        LOGE("failed to call %s's subscribe (err=%d).\n", ctx->irq_module->name,
             rc);
_exit:
    cam_unlock(ctx->lock);
    return rc;
}

static int isp_unsubscribe(struct isp *isp, const struct subscriber *sub)
{
    struct isp_ctx *ctx = (struct isp_ctx *)isp;
    int rc;

    if (!isp)
        return ERR_WRONG_ARGS;

    cam_lock(ctx->lock);
    if (!ctx->initialized) {
        LOGE("isp had not been initialized yet.\n");
        rc = ERR_WRONG_STATE;
        goto _exit;
    }

    if (!ctx->irq_module) {
        LOGE("no isp module to unsubscribe was found.\n");
        rc = ERR_WRONG_STATE;
        goto _exit;
    }

    rc = ctx->irq_module->api->unsubscribe(ctx->irq_module, sub);
    if (rc < 0)
        LOGE("failed to call %s's subscribe (err=%d).\n", ctx->irq_module->name,
             rc);
_exit:
    cam_unlock(ctx->lock);
    return rc;
}

static const struct isp_api isp_api = {
    .reg.read = isp_read,
    .reg.write = isp_write,
    .close = isp_close,
    .init = isp_init,
    .config = isp_config,
    .reset = isp_reset,
    .start = isp_start,
    .stop = isp_stop,
    .push = isp_push,
    .pop = isp_pop,
    .subscribe = isp_subscribe,
    .unsubscribe = isp_unsubscribe,
};

int open_isp(uint32_t id, struct isp **isp)
{
    struct isp_ctx *ctx;
    int rc;

    if (!isp)
        return ERR_WRONG_ARGS;

    ctx = (struct isp_ctx *)cam_alloc(sizeof(*ctx));
    if (!ctx) {
        LOGE("failed to alloc memory for isp ctx.\n");
        return ERR_NO_MEM;
    }

    ctx->id = id;
    ctx->isp.api = &isp_api;
    rc = create_lock(&ctx->lock);
    if (rc < 0) {
        LOGE("failed to create lock (err=%d).\n", rc);
        cam_free(ctx);
        return rc;
    }
    *isp = &ctx->isp;
    return 0;
}
