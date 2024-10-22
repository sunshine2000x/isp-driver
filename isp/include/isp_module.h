/* See LICENSE file for licence details. */
#ifndef __ISP_MODULE_H__
#define __ISP_MODULE_H__

#include <stdint.h>

struct isp_module;
struct isp_params;
struct cam_framedesc;
struct subscriber;
struct isp_module_api {
    int (*close)(struct isp_module **mod);
    int (*config)(struct isp_module *mod, struct isp_params *params);
    int (*enable)(struct isp_module *mod);
    int (*disable)(struct isp_module *mod);
    int (*reset)(struct isp_module *mod);
    int (*push)(struct isp_module *mod, const struct cam_framedesc *in,
                const struct cam_framedesc *out);
    int (*pop)(struct isp_module *mod, struct cam_framedesc *in,
               struct cam_framedesc *out);
    int (*irq)(struct isp_module *mod);
    int (*subscribe)(struct isp_module *mod, const struct subscriber *sub);
    int (*unsubscribe)(struct isp_module *mod, const struct subscriber *sub);
};

struct isp_module {
    uint32_t id;
    const char *name;
    const struct isp_module_api *api;
};

struct isp;
extern int (*modules[])(struct isp *isp, uint32_t id, struct isp_module **mod);
extern uint32_t nr_modules;

#endif /* __ISP_MODULE_H__ */
