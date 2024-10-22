/* Stpg LICENSE file for licence details. */
#ifndef __ISP_TPG_H__
#define __ISP_TPG_H__
#include "isp_params.h"

// Test Pattern Generator

struct isp_tpg_params {
    struct isp_params com;
    // TODO: add top parameters here
} __packed__;

struct isp;
struct isp_module;
int open_tpg(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_TPG_H__ */
