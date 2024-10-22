/* See LICENSE file for licence details. */
#ifndef __CAM_TYPES_H__
#define __CAM_TYPES_H__
#include <stdint.h>

#ifndef __packed__
#define __packed__ __attribute__((packed))
#endif

#ifndef __unused__
#define __unused__ __attribute__((unused))
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))
#endif

enum io_mode {
    I_MODE = 1,
    O_MODE = 2,
    IO_MODE = 3,
};

enum cam_fmt_type {
    CAM_FMT_BAYER_BG,
    CAM_FMT_BAYER_GB,
    CAM_FMT_BAYER_RG,
    CAM_FMT_BAYER_GR,
    CAM_FMT_YUV420_SP,
    CAM_FMT_MAX,
};

typedef uint32_t buf_pa_t;
typedef uint32_t buf_va_t;
typedef uint32_t buf_sz_t;

struct cam_framedesc {
    uint16_t width, height, stride;
    uint8_t bitdepth;
    enum cam_fmt_type type;
    union {
        struct {
            buf_pa_t pa;
            buf_va_t va;
            buf_sz_t sz, uzd;
        } raw;
        struct {
            buf_pa_t pa_y;
            buf_va_t va_y;
            buf_sz_t sz_y, uzd_y;
            buf_pa_t pa_c;
            buf_va_t va_c;
            buf_sz_t sz_c, uzd_c;
        } sp;
    } fb;
} __packed__;

#endif /* __CAM_TYPES_H__ */
