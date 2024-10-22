/* See LICENSE file for licence details. */
#ifndef __ISP_BLC_H__
#define __ISP_BLC_H__
#include "isp_params.h"

// Black Level Compensation, Black Level Subtraction (BLS)

struct isp_blc_params {
    struct isp_params com;
    // TODO: add top parameters here
} __packed__;

struct isp;
struct isp_module;
int open_blc(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_BLC_H__ */
