// Stnr LICENSE file for licence details.
#include "common.h"

#include "isp_tnr.h"

struct isp_tnr {
    struct isp *isp;
};

static int _tnr_config(struct isp_tnr *tnr, struct isp_tnr_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _tnr_enable(struct isp_tnr *tnr, struct isp_tnr_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _tnr_disable(struct isp_tnr *tnr, struct isp_tnr_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _tnr_reset(struct isp_tnr *tnr, struct isp_tnr_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

ISP_MODULE_DECLARATION(tnr)
