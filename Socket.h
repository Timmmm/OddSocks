#pragma once

#include <stdint.h>
#include <limits.h> // netfilter_ipv4 should include this!

#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <poll.h>
#include <netinet/in.h>
#include <signal.h>
#include <arpa/inet.h>

#include <string>

#ifdef __linux__
#include <linux/netfilter_ipv4.h>
#endif

// Bytes type. I may change this to a dedicated roughly string-compatible class later.
typedef std::string bytes;

// A TCP socket.
class Socket
{
public:
	// Create a new TCP socket.
	Socket();
	// Construct this from a socket returned by accept().
	explicit Socket(int sock);
	virtual ~Socket();

	// Close existing connections, and connect to a IPv4 (4 bytes) or IPv6 (16 bytes).
	// TODO: This could automatically determine whether to use IPv4 or 6 by the length.
	virtual bool connect4(const bytes& ip, uint16_t port);
	virtual bool connect6(const bytes& ip, uint16_t port);
	virtual bool connect(const std::string& domain, uint16_t port);

	// Send some data. Sets errno on failure and returns false.
	virtual bool send(const bytes& d);
	// Receive some data. Sets errno on failure and returns false.
	// If size is 0, it waits for at least 1 byte, and then returns all available data up to 4096 bytes.
	// If size is non-zero, it waits for /size/ bytes (up to 4096).
	virtual bool receive(bytes& d, int size = 0);

	// Get the file descriptor (for polling, etc).
	int descriptor();

	// Close connection.
	virtual void close();

#ifdef __linux__
	// Get the original destination if applicable.
	bool originalDestination(uint32_t& ip, uint16_t& port) const;
#endif
protected:
	int fd;
private:
	// No copying.
	Socket(const Socket&);
	Socket& operator=(const Socket&);
};

// Convert a string of hex bytes, like this "deadf00d" into a string.
bytes hexBytes(const std::string& hb);
