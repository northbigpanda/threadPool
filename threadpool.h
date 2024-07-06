#ifndef _THREADPOOL_H
#define _THREADPOOL_H


typedef struct ThreadPool ThreadPool;

ThreadPool* threadPoolCreate(int min, int max, int queueSize);

void threadPoolAdd(ThreadPool* pool, void (*function)(void* arg), void* arg);

void* worker(void* arg);
void* manager(void* arg);
void threadExit(ThreadPool* pool);

int threadPoolBusyNum(ThreadPool* pool);
int threadPoolAliveNum(ThreadPool* pool);

int threadPoolDestroy(ThreadPool* pool);

#endif // _THREADPOOL_H