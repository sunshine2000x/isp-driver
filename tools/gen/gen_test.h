/* See LICENSE file for license details. */
#ifndef __GEN_TEST_H__
#define __GEN_TEST_H__
#include "gen_test_blc_params.h"
#include "gen_test_cbc_params.h"
#include "gen_test_ccm_params.h"
#include "gen_test_csc_params.h"
#include "gen_test_dmsc_params.h"
#include "gen_test_dpc_params.h"
#include "gen_test_ee_params.h"
#include "gen_test_gc_params.h"
#include "gen_test_hsc_params.h"
#include "gen_test_lsc_params.h"
#include "gen_test_params.h"
#include "gen_test_snr_params.h"
#include "gen_test_tnr_params.h"
#include "gen_test_tpg_params.h"

#define _T(x)                                                                  \
    {                                                                          \
        &x, sizeof(x), #x                                                      \
    }

static struct {
    void *params;
    uint32_t size;
    const char *name;
} gen_all_params[] = {
    // clang-format off
    _T(test),
    // dpc
    _T(test_dpc_case_disable),
    _T(test_dpc_case_enable),
    // blc
    _T(test_blc_case_disable),
    _T(test_blc_case_enable),
    // lsc
    _T(test_lsc_case_disable),
    _T(test_lsc_case_enable),
    // dmsc
    _T(test_dmsc_case_disable),
    _T(test_dmsc_case_enable),
    // ccm
    _T(test_ccm_case_disable),
    _T(test_ccm_case_enable),
    // gc
    _T(test_gc_case_disable),
    _T(test_gc_case_enable),
    // csc
    _T(test_csc_case_disable),
    _T(test_csc_case_enable),
    // hsc
    _T(test_hsc_case_disable),
    _T(test_hsc_case_enable),
    // cbc
    _T(test_cbc_case_disable),
    _T(test_cbc_case_enable),
    // ee
    _T(test_ee_case_disable),
    _T(test_ee_case_enable),
    // tpg
    _T(test_tpg_case_disable),
    _T(test_tpg_case_enable),
    // tnr
    _T(test_tnr_case_disable),
    _T(test_tnr_case_enable),
    // snr
    _T(test_snr_case_disable),
    _T(test_snr_case_enable),
    // TODO: Add new cases
    // clang-format on
};
static uint32_t nr_all_params =
    sizeof(gen_all_params) / sizeof(*gen_all_params);

#endif /* __GEN_TEST_H__ */
