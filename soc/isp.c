// See LICENSE file for licence details.
#include "isp.h"

uint32_t isp_read(struct isp *isp, uint32_t offset)
{
    return 0;
}

void isp_write(struct isp *isp, uint32_t offset, uint32_t value)
{
}

int isp_register_irq(struct isp *isp, struct isp_module *mod)
{
    return 0;
}

int isp_unregister_irq(struct isp *isp, struct isp_module *mod)
{
    return 0;
}
