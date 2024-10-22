// See LICENSE file for license details.
#include "test.h"

extern void test_dpc(struct test_params *params);
extern void test_blc(struct test_params *params);
extern void test_lsc(struct test_params *params);
extern void test_dmsc(struct test_params *params);
extern void test_ccm(struct test_params *params);
extern void test_gc(struct test_params *params);
extern void test_csc(struct test_params *params);
extern void test_hsc(struct test_params *params);
extern void test_cbc(struct test_params *params);
extern void test_ee(struct test_params *params);
extern void test_tpg(struct test_params *params);
extern void test_tnr(struct test_params *params);
extern void test_snr(struct test_params *params);

// clang-format off
struct test_suite test_suites[] = {
    _T(test_dpc),
    _T(test_blc),
    _T(test_lsc),
    _T(test_dmsc),
    _T(test_ccm),
    _T(test_gc),
    _T(test_csc),
    _T(test_hsc),
    _T(test_cbc),
    _T(test_ee),
    _T(test_tpg),
    _T(test_tnr),
    _T(test_snr),
};
// clang-format on
uint32_t nr_test_suites = sizeof(test_suites) / sizeof(*test_suites);
