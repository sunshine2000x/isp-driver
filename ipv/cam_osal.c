// See LICENSE file for licence details.
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#include "cam_errors.h"

#include "cam_osal.h"

void *cam_alloc(size_t sz)
{
    return calloc(1, sz);
}

void cam_free(void *p)
{
    free(p);
}

void cam_usleep(size_t us)
{
    usleep(us);
}

struct cam_lock {
    pthread_mutex_t lock;
};

int create_lock(struct cam_lock **l)
{
    struct cam_lock *lock;
    int rc;

    if (!l)
        return ERR_WRONG_ARGS;

    lock = (struct cam_lock *)calloc(1, sizeof(*lock));
    if (!lock)
        return ERR_NO_MEM;

    rc = pthread_mutex_init(&lock->lock, NULL);
    if (rc < 0)
        return ERR_SYS_CALL;
    *l = lock;
    return 0;
}

int destroy_lock(struct cam_lock **l)
{
    int rc;

    if (!l || !*l)
        return ERR_WRONG_ARGS;

    rc = pthread_mutex_destroy(&(*l)->lock);
    if (rc < 0)
        return ERR_SYS_CALL;

    free(*l);
    *l = NULL;
    return 0;
}

int cam_lock(struct cam_lock *l)
{
    int rc;

    if (!l)
        return ERR_WRONG_ARGS;

    rc = pthread_mutex_lock(&l->lock);
    if (rc < 0)
        return ERR_SYS_CALL;
    return 0;
}

int cam_unlock(struct cam_lock *l)
{
    int rc;

    if (!l)
        return ERR_WRONG_ARGS;

    rc = pthread_mutex_unlock(&l->lock);
    if (rc < 0)
        return ERR_SYS_CALL;
    return 0;
}
