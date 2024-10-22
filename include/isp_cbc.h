/* See LICENSE file for licence details. */
#ifndef __ISP_CBC_H__
#define __ISP_CBC_H__
#include "isp_params.h"

// Contrast/Brightness Control

struct isp_cbc_params {
    struct isp_params com;
    // TODO: add top parameters here
} __packed__;

struct isp;
struct isp_module;
int open_cbc(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_CBC_H__ */
