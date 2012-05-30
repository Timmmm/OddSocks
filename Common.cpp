#include "Common.h"

// Escape \ to \\ and ' to \'.
string EscapeSingleQuotes(const string& S)
{
	string Ret;

	for (unsigned int i = 0; i < S.length(); ++i)
	{
		switch (S[i])
		{
		case '\\':
			Ret += "\\\\";
			break;
		case '\'':
			Ret += "\\'";
			break;
		default:
			Ret += S[i];
			break;
		}
	}

	return Ret;
}

// HTML escape.
string HTMLEscape(const string& S)
{
	string Ret;

	for (unsigned int i = 0; i < S.length(); ++i)
	{
		if (isalnum(S[i]) || S[i] == ' ' || S[i] == '.' || S[i] == '/' || S[i] == ':'
		    || S[i] == '_' || S[i] == '-' // TODO: Find safe/unsafe ones.
		    || static_cast<unsigned char>(S[i]) >= 128) // TODO: Check this (for utf8).
		{
			Ret += S[i];
		}
		else
		{
			Ret += "&#" + UItoS(static_cast<unsigned char>(S[i])) + ";";
		}
	}

	return Ret;
}

// Attribute escape.
string AttributeEscape(const string& S)
{
	string Ret;
	
	// TODO: Check.
	for (unsigned int i = 0; i < S.length(); ++i)
	{
		switch (S[i])
		{
		case '"':
			Ret += "&quot;";
			break;
		case '\'':
			Ret += "&apos;";
			break;
		case '&':
			Ret += "&amp;";
			break;
		case '<':
			Ret += "&lt;";
			break;
		case '>':
			Ret += "&gt;";
			break;
		default:
			Ret += S[i];
			break;
		}
	}
	
	return Ret;
	
}
