/* See LICENSE file for license details. */
#ifndef __TEST_CBC_H__
#define __TEST_CBC_H__
#include "isp_cbc.h"

struct test_cbc_params {
    struct isp_cbc_params params;
    struct cam_framedesc in, out;
    uint32_t expected_crc;
} __packed__;

int get_test_cbc_params(const char *cn, struct test_cbc_params **params);
void free_test_cbc_params(struct test_cbc_params **params);

#endif /* __TEST_CBC_H__ */
