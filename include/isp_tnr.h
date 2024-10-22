/* Stnr LICENSE file for licence details. */
#ifndef __ISP_TNR_H__
#define __ISP_TNR_H__
#include "isp_params.h"

// Temporal Noise Reduction

struct isp_tnr_params {
    struct isp_params com;
    // TODO: add top parameters here
} __packed__;

struct isp;
struct isp_module;
int open_tnr(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_TNR_H__ */
