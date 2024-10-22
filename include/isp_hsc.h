/* See LICENSE file for licence details. */
#ifndef __ISP_HSC_H__
#define __ISP_HSC_H__
#include "isp_params.h"

// Hue/Saturation Control

struct isp_hsc_params {
    struct isp_params com;
    // TODO: add top parameters here
} __packed__;

struct isp;
struct isp_module;
int open_hsc(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_HSC_H__ */
