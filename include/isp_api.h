/* See LICENSE file for licence details. */
#ifndef __ISP_API_H__
#define __ISP_API_H__

#include "cam_types.h"

struct isp;
struct isp_params;
struct register_api {
    uint32_t (*read)(struct isp *isp, uint32_t offset);
    void (*write)(struct isp *isp, uint32_t offset, uint32_t value);
};

struct subscriber {
    void (*notify)(int event, void *arg);
    void *arg;
};

struct isp_api {
    const struct register_api reg;
    int (*close)(struct isp **isp);
    int (*init)(struct isp *isp);
    int (*config)(struct isp *isp, struct isp_params *params);
    int (*reset)(struct isp *isp);
    int (*start)(struct isp *isp);
    int (*stop)(struct isp *isp);
    int (*push)(struct isp *isp, const struct cam_framedesc *in,
                const struct cam_framedesc *out);
    int (*pop)(struct isp *isp, struct cam_framedesc *in,
               struct cam_framedesc *out);
    int (*subscribe)(struct isp *isp, const struct subscriber *sub);
    int (*unsubscribe)(struct isp *isp, const struct subscriber *sub);
};

struct isp {
    const struct isp_api *api;
};

int open_isp(uint32_t id, struct isp **isp);

#endif /* __ISP_API_H__ */
