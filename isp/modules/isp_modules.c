// See LICENSE file for licence details.
#include "isp_blc.h"
#include "isp_cbc.h"
#include "isp_ccm.h"
#include "isp_csc.h"
#include "isp_dmsc.h"
#include "isp_dpc.h"
#include "isp_ee.h"
#include "isp_gc.h"
#include "isp_hsc.h"
#include "isp_lsc.h"
#include "isp_mem.h"
#include "isp_snr.h"
#include "isp_tnr.h"
#include "isp_top.h"
#include "isp_tpg.h"

#include "isp_module.h"

// clang-format off
int (*modules[])(struct isp *isp, uint32_t id, struct isp_module **mod) = {
    open_top,
    open_dpc,
    open_blc,
    open_lsc,
    open_dmsc,
    open_ccm,
    open_gc,
    open_csc,
    open_hsc,
    open_cbc,
    open_ee,
    open_snr,
    open_tnr,
    open_tpg,
    open_mem,
};
// clang-format on

uint32_t nr_modules = ARRAY_SIZE(modules);
