/* See LICENSE file for licence details. */
#ifndef __ISP_H__
#define __ISP_H__
#include <stdint.h>

struct isp;
struct isp_module;
uint32_t isp_read(struct isp *isp, uint32_t offset);
void isp_write(struct isp *isp, uint32_t offset, uint32_t value);
int isp_register_irq(struct isp *isp, struct isp_module *mod);
int isp_unregister_irq(struct isp *isp, struct isp_module *mod);

#endif /* __ISP_H__ */
