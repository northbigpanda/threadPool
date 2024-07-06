#pragma once
#include "TaskQueue.h"
#include "TaskQueue.cpp"
template <typename T>
class ThreadPool
{
public:
    ThreadPool(int min, int max);
    ~ThreadPool();

    // �������
    void addTask(Task<T> task);
    // ��ȡæ�̵߳ĸ���
    int getBusyNumber();
    // ��ȡ���ŵ��̸߳���
    int getAliveNumber();

private:
    // �������̵߳�������
    static void* worker(void* arg);
    // �������̵߳�������
    static void* manager(void* arg);
    void threadExit();

private:
    pthread_mutex_t m_lock;
    pthread_cond_t m_notEmpty;
    pthread_t* m_threadIDs;
    pthread_t m_managerID;
    TaskQueue<T>* m_taskQ;
    int m_minNum;
    int m_maxNum;
    int m_busyNum;
    int m_aliveNum;
    int m_exitNum;
    bool m_shutdown = false;
    static  const int NUMBER = 2;

};

