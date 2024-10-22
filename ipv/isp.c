// See LICENSE file for licence details.
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

#include "isp_module.h"
#include "log.h"

#include "isp.h"

static pthread_t task_handle;
static bool is_task_exited;
static struct isp_module *irq_module;

static void *isp_task_handler(void *arg)
{
    ENTER();
    while (!is_task_exited) {
        if (irq_module)
            irq_module->api->irq(irq_module);
        usleep(1000000);
    }
    LEAVE();
    return NULL;
}

uint32_t isp_read(struct isp *isp, uint32_t offset)
{
    uint32_t value = 0;

    LOGD("(0x%08x)=(0x%08x)\n", offset, value);
    return 0;
}

void isp_write(struct isp *isp, uint32_t offset, uint32_t value)
{
    LOGD("(0x%08x)=(0x%08x)\n", offset, value);
}

int isp_register_irq(struct isp *isp, struct isp_module *mod)
{
    int rc;

    is_task_exited = false;
    rc = pthread_create(&task_handle, NULL, isp_task_handler, NULL /*arg*/);
    if (rc < 0)
        return rc;
    irq_module = mod;
    return 0;
}

int isp_unregister_irq(struct isp *isp, struct isp_module *mod)
{
    is_task_exited = true;
    pthread_join(task_handle, NULL);
    task_handle = 0;
    irq_module = NULL;
    return 0;
}
