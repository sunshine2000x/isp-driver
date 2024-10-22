/* See LICENSE file for license details. */
#ifndef __TEST_GC_H__
#define __TEST_GC_H__
#include "isp_gc.h"

struct test_gc_params {
    struct isp_gc_params params;
    struct cam_framedesc in, out;
    uint32_t expected_crc;
} __packed__;

int get_test_gc_params(const char *cn, struct test_gc_params **params);
void free_test_gc_params(struct test_gc_params **params);

#endif /* __TEST_GC_H__ */
