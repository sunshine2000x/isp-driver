// See LICENSE file for licence details.
#include "common.h"

#include "isp_ccm.h"

struct isp_ccm {
    struct isp *isp;
};

static int _ccm_config(struct isp_ccm *ccm, struct isp_ccm_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _ccm_enable(struct isp_ccm *ccm, struct isp_ccm_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _ccm_disable(struct isp_ccm *ccm, struct isp_ccm_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _ccm_reset(struct isp_ccm *ccm, struct isp_ccm_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

ISP_MODULE_DECLARATION(ccm)
