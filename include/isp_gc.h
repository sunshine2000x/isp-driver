/* See LICENSE file for licence details. */
#ifndef __ISP_GC_H__
#define __ISP_GC_H__
#include "isp_params.h"

// Gamma Correction

struct isp_gc_params {
    struct isp_params com;
    // TODO: add top parameters here
} __packed__;

struct isp;
struct isp_module;
int open_gc(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_GC_H__ */
