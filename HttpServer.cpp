#include "HttpServer.h"

string printAuthenticationRequest(bool isInvalidPassword)
{
	string ret;
	ret.append("HTTP/1.1 200 OK\r\n");
	ret.append("Server: OddSocks\r\n");
	ret.append("Connection: close\r\n");
	ret.append("Content-type: text/html\r\n");
	ret.append("\r\n");
	ret.append("<!DOCTYPE html><html><body><h1>Authentication Required</h1><p>Please authenticate yourself.</p>");
	if (isInvalidPassword)
		ret.append("<p>Authentication failed, try again.</p>");
	ret.append("<form method=get action='http://203.0.113.1/'><input name=passhash></form></body></html>");

	return ret;
}

string printAuthenticationSuccess()
{
	string ret;
	ret.append("HTTP/1.1 200 OK\r\n");
	ret.append("Server: OddSocks\r\n");
	ret.append("Connection: close\r\n");
	ret.append("Content-type: text/html\r\n");
	ret.append("\r\n");
	ret.append("<html><body><p>Authentication succeeded.</p></body></html>");
	return ret;
}
