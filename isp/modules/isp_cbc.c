// See LICENSE file for licence details.
#include "common.h"

#include "isp_cbc.h"

struct isp_cbc {
    struct isp *isp;
};

static int _cbc_config(struct isp_cbc *cbc, struct isp_cbc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _cbc_enable(struct isp_cbc *cbc, struct isp_cbc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _cbc_disable(struct isp_cbc *cbc, struct isp_cbc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _cbc_reset(struct isp_cbc *cbc, struct isp_cbc_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

ISP_MODULE_DECLARATION(cbc)
