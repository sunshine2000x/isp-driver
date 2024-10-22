// See LICENSE file for licence details.
#include "common.h"

#include "isp_top.h"

struct isp_top {
    struct isp *isp;
};

static int _top_config(struct isp_top *top, struct isp_top_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _top_enable(struct isp_top *top, struct isp_top_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _top_disable(struct isp_top *top, struct isp_top_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _top_reset(struct isp_top *top, struct isp_top_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

ISP_MODULE_DECLARATION(top)
