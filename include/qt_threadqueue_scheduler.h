#ifndef _QT_THREADQUEUE_SCHEDULER_H_
#define _QT_THREADQUEUE_SCHEDULER_H_

qthread_shepherd_id_t INTERNAL qt_threadqueue_choose_dest(qthread_shepherd_t * curr_shep);
qthread_worker_id_t INTERNAL qt_threadqueue_max_wps(void);

#endif // _QT_THREADQUEUE_SCHEDULER_H_

