// See LICENSE file for licence details.
#include "common.h"

#include "isp_blc.h"

struct isp_blc {
    struct isp *isp;
};

static int _blc_config(struct isp_blc *blc, struct isp_blc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _blc_enable(struct isp_blc *blc, struct isp_blc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _blc_disable(struct isp_blc *blc, struct isp_blc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _blc_reset(struct isp_blc *blc, struct isp_blc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

ISP_MODULE_DECLARATION(blc)
