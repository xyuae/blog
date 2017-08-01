p thread: POSIX  threads: portable operating system interface 
pthread_t aThread; // type of thread
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void* (*start_routine)(void *), void *arg));
int pthread_join(pthread_t head, void **status);
