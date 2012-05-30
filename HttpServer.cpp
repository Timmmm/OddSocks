#include "HttpServer.h"

string printAuthenticationRequest(bool isInvalidPassword)
{
	string ret;
	ret.append("HTTP/1.1 200 OK\r\n");
	ret.append("Server: OddSocks\r\n");
	ret.append("Connection: close\r\n");
	ret.append("Content-type: text/html\r\n");
	ret.append("\r\n");

	ret.append(
	"<!DOCTYPE html>\n"
	"<html>\n"
	"<head>\n"
	"<style type=\"text/css\">\n"
	"body { background-image: url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAQAAAAECAYAAACp8Z5+AAAABHNCSVQICAgIfAhkiAAAACdJREFUCJlj3H3uxH9xcQkGGGBC5rx8+YKBCZkjLi4BEYBxGBgYGADEAwyeXWlVfQAAAABJRU5ErkJggg==);\n"
	"       background-repeat: repeat; }"
	"#page { text-align: center; margin-top: 5em;}"
	"form { margin: 2em; }"
	"input { border: 1px solid #777; }"
	".button {"
	"    background: #f2f2f2;"
	"    color: #000;\n"
	"    padding: 0.3em;\n"
	"    margin-top: 1em;\n"
	"}\n"
	".button:active { background: #ccc; }\n"
	"input:hover, input:focus:hover { border: solid 1px #a00; }\n"
	"input:focus { border: solid 1px #002; }\n"
	"</style>\n"
	"</head>\n"
	"<body>\n"
	"<div id=\"page\">\n"
	"	<p>");
	if (isInvalidPassword)
		ret.append("Authentication failed. Try again.");
	else
		ret.append("&nbsp;");
	ret.append("</p>\n"
	"	<form method=\"get\" action=\"http://203.0.113.1/\">\n"
	"	<input name=\"passhash\" autofocus=\"autofocus\">\n"
	"	<br/><br/>\n"
	"	<input type=\"submit\" value=\"Authenticate\" class=\"button\">\n"
	"	</form>\n"
	"</div>\n"
	"</body>\n"
	"</html>\n");

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
	ret.append(
	"<!DOCTYPE html>\n"
	"<html>\n"
	"<head>\n"
	"<style type=\"text/css\">\n"
	"body { background-image: url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAQAAAAECAYAAACp8Z5+AAAABHNCSVQICAgIfAhkiAAAACdJREFUCJlj3H3uxH9xcQkGGGBC5rx8+YKBCZkjLi4BEYBxGBgYGADEAwyeXWlVfQAAAABJRU5ErkJggg==);\n"
	"       background-repeat: repeat; }"
	"#page { text-align: center; margin-top: 5em;}"
	"form { margin: 2em; }"
	"input { border: 1px solid #777; }"
	".button {"
	"    background: #f2f2f2;"
	"    color: #000;\n"
	"    padding: 0.3em;\n"
	"    margin-top: 1em;\n"
	"}\n"
	".button:active { background: #ccc; }\n"
	"input:hover, input:focus:hover { border: solid 1px #a00; }\n"
	"input:focus { border: solid 1px #002; }\n"
	"</style>\n"
	"</head>\n"
	"<body>\n"
	"<div id=\"page\">\n"
	"	<p>Authentication succeeded!</p>\n"
	"</div>\n"
	"</body>\n"
	"</html>\n");
	return ret;
}
