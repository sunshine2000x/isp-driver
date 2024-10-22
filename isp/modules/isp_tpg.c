// Stpg LICENSE file for licence details.
#include "common.h"

#include "isp_tpg.h"

struct isp_tpg {
    struct isp *isp;
};

static int _tpg_config(struct isp_tpg *tpg, struct isp_tpg_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _tpg_enable(struct isp_tpg *tpg, struct isp_tpg_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _tpg_disable(struct isp_tpg *tpg, struct isp_tpg_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _tpg_reset(struct isp_tpg *tpg, struct isp_tpg_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

ISP_MODULE_DECLARATION(tpg)
