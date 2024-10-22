/* See LICENSE file for licence details. */
#ifndef __CAM_OSAL_H__
#define __CAM_OSAL_H__
#include <stddef.h>

void *cam_alloc(size_t sz);
void cam_free(void *p);

void cam_usleep(size_t us);

struct cam_lock;
int create_lock(struct cam_lock **l);
int destroy_lock(struct cam_lock **l);
int cam_lock(struct cam_lock *l);
int cam_unlock(struct cam_lock *l);

#endif /* __CAM_OSAL_H__ */
