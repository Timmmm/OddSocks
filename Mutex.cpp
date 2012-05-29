#include "Mutex.h"



Mutex::Mutex()
{
	pthread_mutex_init(&mutex, NULL);
}

Mutex::~Mutex()
{
	pthread_mutex_destroy(&mutex);
}

// Block until the mutex is locked.
void Mutex::lock()
{
	pthread_mutex_lock(&mutex);
}

// Try to lock but don't wait. Returns true if the mutext was locked.
bool Mutex::tryLock()
{
	return pthread_mutex_trylock(&mutex) == 0;
}

// Unlock the mutex.
void Mutex::unlock()
{
	pthread_mutex_unlock(&mutex);
}


MutexLocker::MutexLocker(Mutex& m) : rmutex(m)
{
	rmutex.lock();
}

MutexLocker::~MutexLocker()
{
	rmutex.unlock();
}
