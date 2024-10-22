/* See LICENSE file for licence details. */
#ifndef __ISP_CSC_H__
#define __ISP_CSC_H__
#include "isp_params.h"

// Color Space Conversion

struct isp_csc_params {
    struct isp_params com;
    // TODO: add top parameters here
} __packed__;

struct isp;
struct isp_module;
int open_csc(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_CSC_H__ */
