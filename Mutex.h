#pragma once

#include <pthread.h>

class Mutex
{
public:
	Mutex();
	~Mutex();

	// Block until the mutex is locked.
	void lock();

	// Try to lock but don't wait. Returns true if the mutext was locked.
	bool tryLock();

	// Unlock the mutex.
	void unlock();
private:
	Mutex(const Mutex&);
	Mutex& operator=(const Mutex&);

	pthread_mutex_t mutex;
};

// Class to lock the mutex during the current scope.
class MutexLocker
{
public:
	MutexLocker(Mutex& m);
	~MutexLocker();
private:
	MutexLocker(const MutexLocker&);
	MutexLocker& operator=(const MutexLocker&);

	Mutex& rmutex;
};
