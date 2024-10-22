/* See LICENSE file for license details. */
#ifndef __TEST_H__
#define __TEST_H__
#include <stdint.h>
#include <string.h>

#include "cam_osal.h"
#include "crc32.h"
#include "isp_api.h"
#include "isp_module.h"
#include "log.h"
#include "test_params.h"

#ifdef NO_TEST_MAIN
#include "test_api.h"
#endif

int get_test_params(const char *name, void **params, int sz);
void free_test_params(void **params);

/* Definition for test suites */

struct test_suite {
    void (*exec)(struct test_params *params);
    const char *name;
};

extern struct test_suite test_suites[];
extern uint32_t nr_test_suites;

/* Definition for test cases */

struct test_case {
    int (*exec)(void);
    const char *name;
};

#define _T(x)                                                                  \
    {                                                                          \
        x, #x                                                                  \
    }

#define TEST(_test, _case...)                                                  \
    static struct test_case test_cases[] = {_case};                            \
    static uint32_t nr_test_cases = sizeof(test_cases) / sizeof(*test_cases);  \
                                                                               \
    void _test(struct test_params *params)                                     \
    {                                                                          \
        uint32_t i;                                                            \
                                                                               \
        ENTER();                                                               \
        if (!strlen((const char *)params->test_case_name)) {                   \
            for (i = 0; i < nr_test_cases; i++) {                              \
                if (test_cases[i].exec) {                                      \
                    LOGI("Running test case: %s\n", test_cases[i].name);       \
                    test_cases[i].exec();                                      \
                }                                                              \
            }                                                                  \
        } else {                                                               \
            for (i = 0; i < nr_test_cases; i++) {                              \
                if (!strcmp((const char *)params->test_case_name,              \
                            test_cases[i].name)) {                             \
                    if (test_cases[i].exec) {                                  \
                        LOGI("Running test case: %s\n", test_cases[i].name);   \
                        test_cases[i].exec();                                  \
                    }                                                          \
                    break;                                                     \
                }                                                              \
            }                                                                  \
            if (i == nr_test_cases)                                            \
                LOGW("Not found for test case: %s\n", params->test_case_name); \
        }                                                                      \
        LEAVE();                                                               \
    }

#define EXPECT_EQ(func, rc)                                                    \
    do {                                                                       \
        int _rc = func;                                                        \
        if (_rc != (rc))                                                       \
            LOGW("fail: %s, expected: %d, actual: %d\n", #func, (rc), _rc);    \
    } while (0)

#define TEST_ZERO(func, exit)                                                  \
    do {                                                                       \
        int _rc = func;                                                        \
        if (_rc < 0) {                                                         \
            LOGE("fail: %s, return: %d\n", #func, _rc);                        \
            goto exit;                                                         \
        }                                                                      \
    } while (0)

#endif /* __TEST_H__ */
