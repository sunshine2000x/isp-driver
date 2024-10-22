// See LICENSE file for license details.
#include "test.h"

#ifdef NO_TEST_MAIN
int test(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    struct test_params *params;
    int rc;
    uint32_t i;

    ENTER();
    rc = get_test_params("test", (void **)&params, sizeof(*params));
    if (rc < 0)
        return rc;

    if (!strlen((const char *)params->test_suite_name)) {
        for (i = 0; i < nr_test_suites; i++) {
            if (test_suites[i].exec) {
                LOGI("Running test suite: %s\n", test_suites[i].name);
                test_suites[i].exec(params);
            }
        }
    } else {
        for (i = 0; i < nr_test_suites; i++) {
            if (!strcmp((const char *)params->test_suite_name,
                        test_suites[i].name)) {
                if (test_suites[i].exec) {
                    LOGI("Running test suite: %s\n", test_suites[i].name);
                    test_suites[i].exec(params);
                }
                break;
            }
        }
        if (i == nr_test_suites)
            LOGW("Not found for test suite: %s\n", params->test_suite_name);
    }

    free_test_params((void **)&params);
    LEAVE();
    return 0;
}
