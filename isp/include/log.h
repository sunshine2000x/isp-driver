/* See LICENSE file for licence details. */
#ifndef __LOG_H__
#define __LOG_H__
#include <stdio.h>

#define HEADSIZE (128)

extern int log_level;

enum LOG_LEVEL {
    LOG_ERR,
    LOG_WARN,
    LOG_INFO,
    LOG_DEBUG,
};

#define MLOG(_m, _l, _s, ...)                                                  \
    do {                                                                       \
        if (log_level >= (_l)) {                                               \
            char header[HEADSIZE];                                             \
            snprintf(header, HEADSIZE, _s "[%s%d]%s:%d ", (_m)->name,          \
                     (_m)->id, __func__, __LINE__);                            \
            log_print(header, __VA_ARGS__);                                    \
        }                                                                      \
    } while (0)
#define MLOGE(_m, ...) MLOG(_m, LOG_ERR, "[E]", __VA_ARGS__)
#define MLOGW(_m, ...) MLOG(_m, LOG_WARN, "[W]", __VA_ARGS__)
#define MLOGI(_m, ...) MLOG(_m, LOG_INFO, "[I]", __VA_ARGS__)
#define MLOGD(_m, ...) MLOG(_m, LOG_DEBUG, "[D]", __VA_ARGS__)
#define MENTER(_m)     MLOGD(_m, "enter")
#define MLEAVE(_m)     MLOGD(_m, "leave")

#define LOG(_l, _s, ...)                                                       \
    do {                                                                       \
        if (log_level >= (_l)) {                                               \
            char header[HEADSIZE];                                             \
            snprintf(header, HEADSIZE, _s "[isp]%s:%d ", __func__, __LINE__);  \
            log_print(header, __VA_ARGS__);                                    \
        }                                                                      \
    } while (0)
#define LOGE(...) LOG(LOG_ERR, "[E]", __VA_ARGS__)
#define LOGW(...) LOG(LOG_WARN, "[W]", __VA_ARGS__)
#define LOGI(...) LOG(LOG_INFO, "[I]", __VA_ARGS__)
#define LOGD(...) LOG(LOG_DEBUG, "[D]", __VA_ARGS__)
#define ENTER()   LOGD("enter")
#define LEAVE()   LOGD("leave")

void log_print(const char *header, const char *fmt, ...);

#endif /* __LOG_H__ */
