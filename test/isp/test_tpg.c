// Stpg LICENSE file for license details.
#include "test.h"

#include "test_tpg.h"

static int test_tpg_case(const char *name)
{
    struct test_tpg_params *params;
    struct isp *isp;
    uint32_t crc;

    ENTER();
    TEST_ZERO(get_test_params(name, (void **)&params, sizeof(*params)), _exit);
    TEST_ZERO(open_isp(0, &isp), _exit1);
    TEST_ZERO(isp->api->init(isp), _exit2);
    TEST_ZERO(isp->api->config(isp, &params->params.com), _exit2);
    TEST_ZERO(isp->api->push(isp, NULL, &params->out), _exit2);
    TEST_ZERO(isp->api->start(isp), _exit2);
    TEST_ZERO(isp->api->pop(isp, NULL, &params->out), _exit2);
    TEST_ZERO(isp->api->stop(isp), _exit2);

    crc = crc32(params->out.fb.sp.va_y, params->out.fb.sp.sz_y, NULL);
    EXPECT_EQ(crc32(params->out.fb.sp.va_c, params->out.fb.sp.sz_c, &crc),
              params->expected_crc);

_exit2:
    TEST_ZERO(isp->api->close(&isp), _exit1);
_exit1:
    free_test_params((void **)&params);
_exit:
    LEAVE();
    return 0;
}

static int test_tpg_case_disable(void)
{
    return test_tpg_case("test_tpg_case_disable");
}

static int test_tpg_case_enable(void)
{
    return test_tpg_case("test_tpg_case_enable");
}

// clang-format off
TEST(test_tpg,
    _T(test_tpg_case_disable),
    _T(test_tpg_case_enable),
    // TODO: add new cases
)
// clang-format on
