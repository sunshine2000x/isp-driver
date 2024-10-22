/* See LICENSE file for license details. */
#ifndef __TEST_PARAMS_H__
#define __TEST_PARAMS_H__
#include "cam_types.h"

struct test_params {
    int8_t test_suite_name[32];
    int8_t test_case_name[32];
} __packed__;

#endif /* __TEST_PARAMS_H__ */
