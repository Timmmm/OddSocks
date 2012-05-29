#pragma once

#include <string>

using namespace std;

#include "Socket.h"

// An IPv4 or IPv6 address, (and port?)
/*class Address
{

	bool isIPv4() const;
	bool isIPv6() const;

	string toString_IPv6() const;
	string toString_IPv4() const; // For ipv6 addresses this won't work in some way.

private:
	unsigned char octets[32];
};*/

string addressToBinaryString(sockaddr_in address);
