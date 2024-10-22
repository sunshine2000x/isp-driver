/* Ssnr LICENSE file for license details. */
#ifndef __TEST_SNR_H__
#define __TEST_SNR_H__
#include "isp_snr.h"

struct test_snr_params {
    struct isp_snr_params params;
    struct cam_framedesc in, out;
    uint32_t expected_crc;
} __packed__;

int get_test_snr_params(const char *cn, struct test_snr_params **params);
void free_test_snr_params(struct test_snr_params **params);

#endif /* __TEST_SNR_H__ */
