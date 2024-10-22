// See LICENSE file for licence details.
#include "cam_osal.h"

void *cam_alloc(size_t sz)
{
    return 0;
}

void cam_free(void *p)
{
}

void cam_usleep(size_t us)
{
}

int create_lock(struct cam_lock **l)
{
    return 0;
}

int destroy_lock(struct cam_lock **l)
{
    return 0;
}

int cam_lock(struct cam_lock *l)
{
    return 0;
}

int cam_unlock(struct cam_lock *l)
{
    return 0;
}
