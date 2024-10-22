// See LICENSE file for license details.
#include <stdio.h>

#include "gen_test.h"

int main(int argc, char *argv[])
{
    uint32_t i, offset = 0;
    char name[128];
    FILE *file1, *file2, *file3;

#ifdef TEST_PARAMS_PATH
    snprintf(name, sizeof(name), "%s/all_test.bin", TEST_PARAMS_PATH);
#else
    snprintf(name, sizeof(name), "all_test.bin");
#endif

    file2 = fopen(name, "wb");
    if (!file2) {
        fprintf(stderr, "%s failed to open file: %s\n", argv[0], name);
        return -1;
    }

#ifdef TEST_PARAMS_PATH
    snprintf(name, sizeof(name), "%s/all_test.txt", TEST_PARAMS_PATH);
#else
    snprintf(name, sizeof(name), "all_test.txt");
#endif

    file3 = fopen(name, "w+");
    if (!file3) {
        fprintf(stderr, "%s failed to open file: %s\n", argv[0], name);
        fclose(file3);
        return -1;
    }

    fprintf(file3, "%-5s %-10s %s\n", "Index", "Offset", "Name");
    for (i = 0; i < nr_all_params; i++) {
#ifdef TEST_PARAMS_PATH
        snprintf(name, sizeof(name), "%s/%s.bin", TEST_PARAMS_PATH,
                 gen_all_params[i].name);
#else
        snprintf(name, sizeof(name), "%s.bin", gen_all_params[i].name);
#endif
        file1 = fopen(name, "wb");
        if (!file1) {
            fprintf(stderr, "%s failed to open file: %s\n", argv[0], name);
            fclose(file2);
            fclose(file3);
            return -1;
        }

        fwrite(gen_all_params[i].params, gen_all_params[i].size, 1, file1);
        fwrite(gen_all_params[i].params, gen_all_params[i].size, 1, file2);
        fprintf(file3, "[%3d] 0x%08x %s.bin\n", i, offset,
                gen_all_params[i].name);
        offset += gen_all_params[i].size;
        fclose(file1);
    }
    fclose(file2);
    fclose(file3);
    return 0;
}
