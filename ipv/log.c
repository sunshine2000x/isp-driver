// See LICENSE file for licence details.
#include <stdarg.h>
#include <stdio.h>

#include "log.h"

#define BUFFSIZE (128)

int log_level = 3;

void log_print(const char *header, const char *fmt, ...)
{
    char buffer[BUFFSIZE];
    int len;
    va_list args;

    va_start(args, fmt);
    len = vsnprintf(buffer, BUFFSIZE, fmt, args);
    va_end(args);
    if (len <= 0)
        return;
    if (buffer[len - 1] == '\n')
        buffer[len - 1] = 0;
    fprintf(stdout, "%s%s\n", header, buffer);
}
