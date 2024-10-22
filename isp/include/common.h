/* See LICENSE file for licence details. */
#ifndef __COMMON_H__
#define __COMMON_H__
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "cam_errors.h"
#include "cam_osal.h"
#include "isp_module.h"
#include "log.h"

#define ISP_MODULE_DECLARATION_FULL(_mod, _push, _pop, _irq, _sub, _unsub)     \
    struct _mod##_ctx {                                                        \
        struct isp_module mod;                                                 \
        struct isp_##_mod _mod;                                                \
        struct isp_##_mod##_params params;                                     \
        bool initialized;                                                      \
    };                                                                         \
                                                                               \
    static __unused__ struct isp_##_mod *isp_module_to_isp_##_mod(             \
        struct isp_module *mod)                                                \
    {                                                                          \
        struct _mod##_ctx *ctx = (struct _mod##_ctx *)mod;                     \
                                                                               \
        if (mod)                                                               \
            return &ctx->_mod;                                                 \
        return NULL;                                                           \
    }                                                                          \
                                                                               \
    static int _mod##_close(struct isp_module **mod)                           \
    {                                                                          \
        struct _mod##_ctx *ctx;                                                \
                                                                               \
        ENTER();                                                               \
        if (!mod)                                                              \
            return ERR_WRONG_ARGS;                                             \
                                                                               \
        ctx = (struct _mod##_ctx *)*mod;                                       \
        cam_free(ctx);                                                         \
        *mod = NULL;                                                           \
        LEAVE();                                                               \
        return 0;                                                              \
    }                                                                          \
                                                                               \
    static int _mod##_config(struct isp_module *mod,                           \
                             struct isp_params *params)                        \
    {                                                                          \
        struct _mod##_ctx *ctx = (struct _mod##_ctx *)mod;                     \
        int rc;                                                                \
                                                                               \
        MENTER(mod);                                                           \
        if (!mod || !params)                                                   \
            return ERR_WRONG_ARGS;                                             \
                                                                               \
        if (ctx->initialized)                                                  \
            return 0;                                                          \
                                                                               \
        rc = _##_mod##_config(&ctx->_mod,                                      \
                              (struct isp_##_mod##_params *)params);           \
        if (rc < 0) {                                                          \
            MLOGE(mod, "failed to call _%s_config (err=%d).\n", #_mod, rc);    \
            return rc;                                                         \
        }                                                                      \
                                                                               \
        if (&ctx->params.com != params)                                        \
            memcpy(&ctx->params, params, sizeof(ctx->params));                 \
        ctx->initialized = true;                                               \
        MLEAVE(mod);                                                           \
        return 0;                                                              \
    }                                                                          \
                                                                               \
    static int _mod##_enable(struct isp_module *mod)                           \
    {                                                                          \
        struct _mod##_ctx *ctx = (struct _mod##_ctx *)mod;                     \
        int rc;                                                                \
                                                                               \
        MENTER(mod);                                                           \
        if (!mod)                                                              \
            return ERR_WRONG_ARGS;                                             \
                                                                               \
        /* the module will not be enabled if it's not initialized firstly */   \
        if (!ctx->initialized)                                                 \
            return 0;                                                          \
                                                                               \
        rc = _##_mod##_enable(&ctx->_mod, &ctx->params);                       \
        if (rc < 0)                                                            \
            MLOGE(mod, "failed to call _%s_enable (err=%d).\n", #_mod, rc);    \
        MLEAVE(mod);                                                           \
        return rc;                                                             \
    }                                                                          \
                                                                               \
    static int _mod##_disable(struct isp_module *mod)                          \
    {                                                                          \
        struct _mod##_ctx *ctx = (struct _mod##_ctx *)mod;                     \
        int rc;                                                                \
                                                                               \
        MENTER(mod);                                                           \
        if (!mod)                                                              \
            return ERR_WRONG_ARGS;                                             \
                                                                               \
        rc = _##_mod##_disable(&ctx->_mod, &ctx->params);                      \
        if (rc < 0)                                                            \
            MLOGE(mod, "failed to call _%s_disable (err=%d).\n", #_mod, rc);   \
        MLEAVE(mod);                                                           \
        return rc;                                                             \
    }                                                                          \
                                                                               \
    static int _mod##_reset(struct isp_module *mod)                            \
    {                                                                          \
        struct _mod##_ctx *ctx = (struct _mod##_ctx *)mod;                     \
        int rc;                                                                \
                                                                               \
        MENTER(mod);                                                           \
        if (!mod)                                                              \
            return ERR_WRONG_ARGS;                                             \
                                                                               \
        rc = _##_mod##_reset(&ctx->_mod, &ctx->params);                        \
        if (rc < 0) {                                                          \
            MLOGE(mod, "failed to call _%s_reset (err=%d).\n", #_mod, rc);     \
            return rc;                                                         \
        }                                                                      \
                                                                               \
        ctx->initialized = false;                                              \
        MLEAVE(mod);                                                           \
        return 0;                                                              \
    }                                                                          \
                                                                               \
    static const struct isp_module_api _mod##_api = {                          \
        .close = _mod##_close,                                                 \
        .config = _mod##_config,                                               \
        .enable = _mod##_enable,                                               \
        .disable = _mod##_disable,                                             \
        .reset = _mod##_reset,                                                 \
        .push = _push,                                                         \
        .pop = _pop,                                                           \
        .irq = _irq,                                                           \
        .subscribe = _sub,                                                     \
        .unsubscribe = _unsub,                                                 \
    };                                                                         \
                                                                               \
    int open_##_mod(struct isp *isp, uint32_t id, struct isp_module **mod)     \
    {                                                                          \
        struct _mod##_ctx *ctx;                                                \
                                                                               \
        ENTER();                                                               \
        if (!isp || !mod)                                                      \
            return ERR_WRONG_ARGS;                                             \
                                                                               \
        ctx = (struct _mod##_ctx *)cam_alloc(sizeof(*ctx));                    \
        if (!ctx) {                                                            \
            LOGE("failed to alloc memory for %s ctx.\n", #_mod);               \
            return ERR_NO_MEM;                                                 \
        }                                                                      \
                                                                               \
        ctx->_mod.isp = isp;                                                   \
        ctx->mod.name = #_mod;                                                 \
        ctx->mod.id = id;                                                      \
        ctx->mod.api = &_mod##_api;                                            \
        *mod = &ctx->mod;                                                      \
        LEAVE();                                                               \
        return 0;                                                              \
    }

#define ISP_MODULE_DECLARATION(_mod)                                           \
    ISP_MODULE_DECLARATION_FULL(_mod, NULL, NULL, NULL, NULL, NULL)

#endif /* __COMMON_H__ */
