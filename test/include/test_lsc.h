/* See LICENSE file for license details. */
#ifndef __TEST_LSC_H__
#define __TEST_LSC_H__
#include "isp_lsc.h"

struct test_lsc_params {
    struct isp_lsc_params params;
    struct cam_framedesc in, out;
    uint32_t expected_crc;
} __packed__;

int get_test_lsc_params(const char *cn, struct test_lsc_params **params);
void free_test_lsc_params(struct test_lsc_params **params);

#endif /* __TEST_LSC_H__ */
