#include "Tempo.h"

#include <sys/time.h>

uint64_t CurrentTimeSeconds()
{
	struct timeval tv;
	gettimeofday(&tv, 0);
	return tv.tv_sec;
}
