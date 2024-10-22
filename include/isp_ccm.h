/* See LICENSE file for licence details. */
#ifndef __ISP_CCM_H__
#define __ISP_CCM_H__
#include "isp_params.h"

// Color Correction Matrix

struct isp_ccm_params {
    struct isp_params com;
    // TODO: add top parameters here
} __packed__;

struct isp;
struct isp_module;
int open_ccm(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_CCM_H__ */
