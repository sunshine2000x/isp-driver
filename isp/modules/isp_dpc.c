// See LICENSE file for licence details.
#include "common.h"

#include "isp_dpc.h"

struct isp_dpc {
    struct isp *isp;
};

static int _dpc_config(struct isp_dpc *dpc, struct isp_dpc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _dpc_enable(struct isp_dpc *dpc, struct isp_dpc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _dpc_disable(struct isp_dpc *dpc, struct isp_dpc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _dpc_reset(struct isp_dpc *dpc, struct isp_dpc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

ISP_MODULE_DECLARATION(dpc)
