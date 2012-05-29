#include "Tempo.h"

#include <sys/time.h>

int CurrentTimeSeconds()
{
	struct timeval tv;
	gettimeofday(&tv, 0);
	return tv.tv_sec;
}
