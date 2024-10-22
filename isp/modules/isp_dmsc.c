// See LICENSE file for licence details.
#include "common.h"

#include "isp_dmsc.h"

struct isp_dmsc {
    struct isp *isp;
};

static int _dmsc_config(struct isp_dmsc *dmsc, struct isp_dmsc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _dmsc_enable(struct isp_dmsc *dmsc, struct isp_dmsc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _dmsc_disable(struct isp_dmsc *dmsc, struct isp_dmsc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _dmsc_reset(struct isp_dmsc *dmsc, struct isp_dmsc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

ISP_MODULE_DECLARATION(dmsc)
