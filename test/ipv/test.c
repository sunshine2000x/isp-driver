// See LICENSE file for license details.
#include <stdlib.h>

#include "cam_errors.h"

#include "test.h"

static int read_binary_file(const char *name, void *dat, int sz)
{
    FILE *fp;
    char fn[128];

    if (!name || !dat || sz <= 0)
        return ERR_WRONG_ARGS;

#ifdef TEST_PARAMS_PATH
    snprintf(fn, sizeof(fn), "%s/%s.bin", TEST_PARAMS_PATH, name);
#else
    snprintf(fn, sizeof(fn), "%s.bin", name);
#endif
    fp = fopen(fn, "rb");
    if (!fp) {
        fprintf(stderr, "%s failed to open file: %s\n", __func__, fn);
        return ERR_SYS_CALL;
    }

    sz = fread(dat, 1, sz, fp);
    fclose(fp);
    return sz;
}

int get_test_params(const char *name, void **params, int sz)
{
    void *p;
    int rc;

    if (!name || !params || sz <= 0)
        return ERR_WRONG_ARGS;

    p = (void *)calloc(1, sz);
    if (!p)
        return ERR_NO_MEM;

    rc = read_binary_file(name, p, sz);
    if (rc != sz) {
        free(p);
        return ERR_UNKNOWN;
    }
    *params = p;
    return 0;
}

void free_test_params(void **params)
{
    if (params) {
        free(*params);
        *params = NULL;
    }
}
