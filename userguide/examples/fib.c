#include <stdio.h>
#include <stdlib.h>
#include <qthread/qthread.h>

unsigned int total = 0;

static aligned_t fib(void *arg)
{
    aligned_t x = 0, y = 0;
    unsigned long n = (unsigned long)(uintptr_t) arg;

    //printf("Inside fib with arg = %d\n",n);

    if (n < 2) return n;

    qthread_fork(fib, (void *) n-1, &x);
    qthread_fork(fib, (void *) n-2, &y);

    qthread_readFF(NULL, &x);
    qthread_readFF(NULL, &y);

    qthread_incr(&total,2);
    return (x + y);
}

int main(int argc, char *argv[])
{
    aligned_t return_value = 0;
    unsigned long n = 0;

    if (argc > 1)
       n = atol(argv[1]);

    qthread_initialize();

    qthread_fork(fib, (void *) n, &return_value);

    qthread_readFF(NULL, &return_value);

    printf("fib(%ld) = %ld\nTotal = %d\n", n, return_value,total+1);

    return 0;
}
