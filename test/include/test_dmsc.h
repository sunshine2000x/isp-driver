/* See LICENSE file for license details. */
#ifndef __TEST_DMSC_H__
#define __TEST_DMSC_H__
#include "isp_dmsc.h"

struct test_dmsc_params {
    struct isp_dmsc_params params;
    struct cam_framedesc in, out;
    uint32_t expected_crc;
} __packed__;

int get_test_dmsc_params(const char *cn, struct test_dmsc_params **params);
void free_test_dmsc_params(struct test_dmsc_params **params);

#endif /* __TEST_DMSC_H__ */
