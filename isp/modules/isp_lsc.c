// See LICENSE file for licence details.
#include "common.h"

#include "isp_lsc.h"

struct isp_lsc {
    struct isp *isp;
};

static int _lsc_config(struct isp_lsc *lsc, struct isp_lsc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _lsc_enable(struct isp_lsc *lsc, struct isp_lsc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _lsc_disable(struct isp_lsc *lsc, struct isp_lsc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _lsc_reset(struct isp_lsc *lsc, struct isp_lsc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

ISP_MODULE_DECLARATION(lsc)
