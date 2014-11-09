#pragma once

#include "Socket.h"

#include <stdint.h> // cstdint not available on Macs
#include <string>

using std::string;

// Authentication is IP based. We don't use any of the SOCKS authentication methods because
// no browsers implement them! The only place I've seen them is on OSX.

// Return true if the ip address is currently authenticated. Takes the current time into account.
bool clientIsAuthenticated(sockaddr_in address);

// Set the address to be authenticated or not. This should be called anyway if the client
// is authenticated to reset the timeout.
void updateClientAuthentication(sockaddr_in address, bool authed);

// Set and check the password. Default "".
void setPassword(string password);
bool checkPassword(string password);

const uint64_t AUTH_TIMEOUT = 60*60*24*7; // 7 days.
