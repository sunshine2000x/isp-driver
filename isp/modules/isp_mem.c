// See LICENSE file for licence details.
#include "common.h"

#include "isp_api.h"

#include "isp_mem.h"

struct isp_mem {
    struct isp *isp;
    const struct subscriber *subscriber;
};

static struct isp_mem *isp_module_to_isp_mem(struct isp_module *mod);

static int _mem_config(struct isp_mem *mem, struct isp_mem_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _mem_enable(struct isp_mem *mem, struct isp_mem_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _mem_disable(struct isp_mem *mem, struct isp_mem_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _mem_reset(struct isp_mem *mem, struct isp_mem_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int mem_push(struct isp_module *mod, const struct cam_framedesc *in,
                    const struct cam_framedesc *out)
{
    struct isp_mem *mem = isp_module_to_isp_mem(mod);

    if (!mem)
        return ERR_WRONG_ARGS;

    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int mem_pop(struct isp_module *mod, struct cam_framedesc *in,
                   struct cam_framedesc *out)
{
    struct isp_mem *mem = isp_module_to_isp_mem(mod);

    if (!mem)
        return ERR_WRONG_ARGS;

    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int mem_irq(struct isp_module *mod)
{
    struct isp_mem *mem = isp_module_to_isp_mem(mod);

    if (!mem)
        return ERR_WRONG_ARGS;

    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int mem_subscribe(struct isp_module *mod, const struct subscriber *sub)
{
    struct isp_mem *mem = isp_module_to_isp_mem(mod);

    if (!mem || !sub)
        return ERR_WRONG_ARGS;

    if (mem->subscriber)
        return ERR_WRONG_STATE;

    mem->subscriber = sub;
    return 0;
}

static int mem_unsubscribe(struct isp_module *mod, const struct subscriber *sub)
{
    struct isp_mem *mem = isp_module_to_isp_mem(mod);

    if (!mem || !sub)
        return ERR_WRONG_ARGS;

    if (mem->subscriber != sub)
        return ERR_WRONG_STATE;

    mem->subscriber = NULL;
    return 0;
}

ISP_MODULE_DECLARATION_FULL(mem, mem_push, mem_pop, mem_irq, mem_subscribe,
                            mem_unsubscribe)
