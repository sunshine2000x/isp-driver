/* See LICENSE file for licence details. */
#ifndef __ISP_DMSC_H__
#define __ISP_DMSC_H__
#include "isp_params.h"

// Demosaic, CFA Interpolation

struct isp_dmsc_params {
    struct isp_params com;
    // TODO: add top parameters here
} __packed__;

struct isp;
struct isp_module;
int open_dmsc(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_DMSC_H__ */
