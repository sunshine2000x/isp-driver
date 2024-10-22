/* Stnr LICENSE file for license details. */
#ifndef __TEST_TNR_H__
#define __TEST_TNR_H__
#include "isp_tnr.h"

struct test_tnr_params {
    struct isp_tnr_params params;
    struct cam_framedesc in, out;
    uint32_t expected_crc;
} __packed__;

int get_test_tnr_params(const char *cn, struct test_tnr_params **params);
void free_test_tnr_params(struct test_tnr_params **params);

#endif /* __TEST_TNR_H__ */
