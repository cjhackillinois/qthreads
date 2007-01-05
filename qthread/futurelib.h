#ifndef FUTURES_H
#define FUTURES_H

#include <qthread/qthread.h>

#ifdef __cplusplus
extern "C"
{
#endif
typedef qthread_t future_t;

void future_create(qthread_t * qthr, aligned_t (*fptr) (qthread_t *, void *),
			void *arg, aligned_t *retval);

void future_join_all(qthread_t * qthr, aligned_t * fta, int ftc);

void future_init(qthread_t * qthr, int vp_per_loc, int loc_count);

void future_exit(qthread_t * qthr);

int future_yield(qthread_t * qthr);
void future_acquire(qthread_t * qthr);

#ifdef __cplusplus
}
#include <qthread/loop_templates.hpp>
#endif

#endif
