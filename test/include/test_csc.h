/* See LICENSE file for license details. */
#ifndef __TEST_CSC_H__
#define __TEST_CSC_H__
#include "isp_csc.h"

struct test_csc_params {
    struct isp_csc_params params;
    struct cam_framedesc in, out;
    uint32_t expected_crc;
} __packed__;

int get_test_csc_params(const char *cn, struct test_csc_params **params);
void free_test_csc_params(struct test_csc_params **params);

#endif /* __TEST_CSC_H__ */
