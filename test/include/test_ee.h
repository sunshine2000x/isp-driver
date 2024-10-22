/* See LICENSE file for license details. */
#ifndef __TEST_EE_H__
#define __TEST_EE_H__
#include "isp_ee.h"

struct test_ee_params {
    struct isp_ee_params params;
    struct cam_framedesc in, out;
    uint32_t expected_crc;
} __packed__;

int get_test_ee_params(const char *cn, struct test_ee_params **params);
void free_test_ee_params(struct test_ee_params **params);

#endif /* __TEST_EE_H__ */
