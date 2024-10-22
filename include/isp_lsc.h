/* See LICENSE file for licence details. */
#ifndef __ISP_LSC_H__
#define __ISP_LSC_H__
#include "isp_params.h"

// Lens Shading Correction

struct isp_lsc_params {
    struct isp_params com;
    // TODO: add top parameters here
} __packed__;

struct isp;
struct isp_module;
int open_lsc(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_LSC_H__ */
