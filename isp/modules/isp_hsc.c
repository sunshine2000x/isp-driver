// See LICENSE file for licence details.
#include "common.h"

#include "isp_hsc.h"

struct isp_hsc {
    struct isp *isp;
};

static int _hsc_config(struct isp_hsc *hsc, struct isp_hsc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _hsc_enable(struct isp_hsc *hsc, struct isp_hsc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _hsc_disable(struct isp_hsc *hsc, struct isp_hsc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _hsc_reset(struct isp_hsc *hsc, struct isp_hsc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

ISP_MODULE_DECLARATION(hsc)
