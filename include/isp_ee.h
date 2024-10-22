/* See LICENSE file for licence details. */
#ifndef __ISP_EE_H__
#define __ISP_EE_H__
#include "isp_params.h"

// Edge Enhancement Control

struct isp_ee_params {
    struct isp_params com;
    // TODO: add top parameters here
} __packed__;

struct isp;
struct isp_module;
int open_ee(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_EE_H__ */
