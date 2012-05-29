#pragma once

#include "Socket.h"

// Return true if the ip address is currently authenticated.
bool clientIsAuthenticated(sockaddr_in address);

// Set the address to be authenticated or not. This should be called anyway if the client
// is authenticated to reset the timeout.
void updateClientAuthentication(sockaddr_in address, bool authed);

const int AUTH_TIMEOUT = 60*60*24*7; // 7 days.
