/* See LICENSE file for license details. */
#ifndef __TEST_BLC_H__
#define __TEST_BLC_H__
#include "isp_blc.h"

struct test_blc_params {
    struct isp_blc_params params;
    struct cam_framedesc in, out;
    uint32_t expected_crc;
} __packed__;

int get_test_blc_params(const char *cn, struct test_blc_params **params);
void free_test_blc_params(struct test_blc_params **params);

#endif /* __TEST_BLC_H__ */
