#include "Address.h"

string addressToBinaryString(sockaddr_in address)
{
	string ret;
	unsigned char* ip = reinterpret_cast<unsigned char*>(&address.sin_addr.s_addr);
	for (int i = 0; i < 4; ++i) // IPV6 !!!! ARGH
		ret.append(1, ip[0]);
	return ret;
}
