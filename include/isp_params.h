/* See LICENSE file for licence details. */
#ifndef __ISP_PARAMS_H__
#define __ISP_PARAMS_H__

#include "cam_types.h"

struct isp_params {
    uint32_t index;
    enum io_mode mode;
} __packed__;

#endif /* __ISP_PARAMS_H__ */
