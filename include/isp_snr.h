/* Ssnr LICENSE file for licence details. */
#ifndef __ISP_SNR_H__
#define __ISP_SNR_H__
#include "isp_params.h"

// Spatial Noise Reduction

struct isp_snr_params {
    struct isp_params com;
    // TODO: add top parameters here
} __packed__;

struct isp;
struct isp_module;
int open_snr(struct isp *isp, uint32_t id, struct isp_module **mod);

#endif /* __ISP_SNR_H__ */
