/* See LICENSE file for licence details. */
#ifndef __ISP_MEM_H__
#define __ISP_MEM_H__
#include "isp_params.h"

// Memory Control

struct isp_mem_params {
    struct isp_params com;
    // TODO: add mem parameters here
} __packed__;

struct isp;
struct isp_module;
int open_mem(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_MEM_H__ */
