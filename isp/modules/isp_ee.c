// See LICENSE file for licence details.
#include "common.h"

#include "isp_ee.h"

struct isp_ee {
    struct isp *isp;
};

static int _ee_config(struct isp_ee *ee, struct isp_ee_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _ee_enable(struct isp_ee *ee, struct isp_ee_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _ee_disable(struct isp_ee *ee, struct isp_ee_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

static int _ee_reset(struct isp_ee *ee, struct isp_ee_params *params)
{
    // TODO: call isp_read/isp_write to add register configuration here.
    return 0;
}

ISP_MODULE_DECLARATION(ee)
