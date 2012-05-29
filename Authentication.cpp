#include "Authentication.h"
#include "Tempo.h"


#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <poll.h>
#include <netinet/in.h>
#include <signal.h>
#include <arpa/inet.h>

#include <map>
#include <string>

using namespace std;

#include "Mutex.h"
#include "Address.h"

// This is a map from ip address in binary form to the time at which updateClientAuthentication()
// was last called.
map<string, int> authTimes;
Mutex authMutex;




bool clientIsAuthenticated(sockaddr_in address)
{
	MutexLocker m(authMutex);

	string strAddress = addressToBinaryString(address);
	int now = CurrentTimeSeconds();

	if (authTimes.count(strAddress) < 1)
		return false;

	return authTimes[strAddress] + AUTH_TIMEOUT > now;
}

void updateClientAuthentication(sockaddr_in address, bool authed)
{
	MutexLocker m(authMutex);

	string strAddress = addressToBinaryString(address);
	int now = CurrentTimeSeconds();

	if (authed)
		authTimes[strAddress] = now;
	else
		authTimes.erase(strAddress);
}

