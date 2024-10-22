/* See LICENSE file for license details. */
#ifndef __TEST_DPC_H__
#define __TEST_DPC_H__
#include "isp_dpc.h"

struct test_dpc_params {
    struct isp_dpc_params params;
    struct cam_framedesc in, out;
    uint32_t expected_crc;
} __packed__;

int get_test_dpc_params(const char *cn, struct test_dpc_params **params);
void free_test_dpc_params(struct test_dpc_params **params);

#endif /* __TEST_DPC_H__ */
