// See LICENSE file for licence details.
#include "common.h"

#include "isp_gc.h"

struct isp_gc {
    struct isp *isp;
};

static int _gc_config(struct isp_gc *gc, struct isp_gc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _gc_enable(struct isp_gc *gc, struct isp_gc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _gc_disable(struct isp_gc *gc, struct isp_gc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _gc_reset(struct isp_gc *gc, struct isp_gc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

ISP_MODULE_DECLARATION(gc)
