// Ssnr LICENSE file for licence details.
#include "common.h"

#include "isp_snr.h"

struct isp_snr {
    struct isp *isp;
};

static int _snr_config(struct isp_snr *snr, struct isp_snr_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _snr_enable(struct isp_snr *snr, struct isp_snr_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _snr_disable(struct isp_snr *snr, struct isp_snr_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _snr_reset(struct isp_snr *snr, struct isp_snr_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

ISP_MODULE_DECLARATION(snr)
