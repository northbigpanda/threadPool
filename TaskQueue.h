#pragma once
#include <queue>
#include <pthread.h>

using callback = void(*)(void*);

template <typename T>
struct Task
{
	Task()
	{
		function = nullptr;
		arg = nullptr;
	}
	Task(callback f, void* arg)
	{
		function = f;
		this->arg = (T*)arg;
	}
	callback function;
	T* arg;
};

template <typename T>
class TaskQueue
{
public:
	TaskQueue();
	~TaskQueue();

	void AddTask(Task<T> task);
	void AddTask(callback f, void* arg); 
	Task<T> takeTask();
	inline size_t taskNumber() { return m_taskQ.size(); }	
private:
	std::queue<Task<T>> m_taskQ;
	pthread_mutex_t m_mutex;

};

