/* Stpg LICENSE file for license details. */
#ifndef __TEST_TPG_H__
#define __TEST_TPG_H__
#include "isp_tpg.h"

struct test_tpg_params {
    struct isp_tpg_params params;
    struct cam_framedesc out;
    uint32_t expected_crc;
} __packed__;

int get_test_tpg_params(const char *cn, struct test_tpg_params **params);
void free_test_tpg_params(struct test_tpg_params **params);

#endif /* __TEST_TPG_H__ */
