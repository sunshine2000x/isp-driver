/* See LICENSE file for license details. */
#ifndef __TEST_HSC_H__
#define __TEST_HSC_H__
#include "isp_hsc.h"

struct test_hsc_params {
    struct isp_hsc_params params;
    struct cam_framedesc in, out;
    uint32_t expected_crc;
} __packed__;

int get_test_hsc_params(const char *cn, struct test_hsc_params **params);
void free_test_hsc_params(struct test_hsc_params **params);

#endif /* __TEST_HSC_H__ */
