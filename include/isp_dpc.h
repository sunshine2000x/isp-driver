/* See LICENSE file for licence details. */
#ifndef __ISP_DPC_H__
#define __ISP_DPC_H__
#include "isp_params.h"

// Defective/Dead Pixel Correction

struct isp_dpc_params {
    struct isp_params com;
    // TODO: add top parameters here
} __packed__;

struct isp;
struct isp_module;
int open_dpc(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_DPC_H__ */
