// See LICENSE file for license details.
#include "test.h"

#include "test_dmsc.h"

static int test_dmsc_case(const char *name)
{
    struct test_dmsc_params *params;
    struct isp *isp;
    uint32_t crc;

    ENTER();
    TEST_ZERO(get_test_params(name, (void **)&params, sizeof(*params)), _exit);
    TEST_ZERO(open_isp(0, &isp), _exit1);
    TEST_ZERO(isp->api->init(isp), _exit2);
    TEST_ZERO(isp->api->config(isp, &params->params.com), _exit2);
    TEST_ZERO(isp->api->push(isp, &params->in, &params->out), _exit2);
    TEST_ZERO(isp->api->start(isp), _exit2);
    TEST_ZERO(isp->api->pop(isp, &params->in, &params->out), _exit2);
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

static int test_dmsc_case_disable(void)
{
    return test_dmsc_case("test_dmsc_case_disable");
}

static int test_dmsc_case_enable(void)
{
    return test_dmsc_case("test_dmsc_case_enable");
}

// clang-format off
TEST(test_dmsc,
    _T(test_dmsc_case_disable),
    _T(test_dmsc_case_enable),
    // TODO: add new cases
)
// clang-format on
