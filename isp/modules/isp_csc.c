// See LICENSE file for licence details.
#include "common.h"

#include "isp_csc.h"

struct isp_csc {
    struct isp *isp;
};

static int _csc_config(struct isp_csc *csc, struct isp_csc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _csc_enable(struct isp_csc *csc, struct isp_csc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _csc_disable(struct isp_csc *csc, struct isp_csc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _csc_reset(struct isp_csc *csc, struct isp_csc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

ISP_MODULE_DECLARATION(csc)
