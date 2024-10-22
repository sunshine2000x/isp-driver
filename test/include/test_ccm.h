/* See LICENSE file for license details. */
#ifndef __TEST_CCM_H__
#define __TEST_CCM_H__
#include "isp_ccm.h"

struct test_ccm_params {
    struct isp_ccm_params params;
    struct cam_framedesc in, out;
    uint32_t expected_crc;
} __packed__;

int get_test_ccm_params(const char *cn, struct test_ccm_params **params);
void free_test_ccm_params(struct test_ccm_params **params);

#endif /* __TEST_CCM_H__ */
