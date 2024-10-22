/* See LICENSE file for licence details. */
#ifndef __ISP_TOP_H__
#define __ISP_TOP_H__
#include "isp_params.h"

// Top Layer Control

struct isp_top_params {
    struct isp_params com;
    // TODO: add top parameters here
} __packed__;

struct isp;
struct isp_module;
int open_top(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_TOP_H__ */
