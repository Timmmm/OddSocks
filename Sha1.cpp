#include "Sha1.h"

#include <string>
#include <iostream>
#include <stdint.h>

using namespace std;

typedef uint32_t uint32;
typedef uint64_t uint64;
typedef uint8_t uint8;

// n must be 0 <= n < 32
uint32 S(uint32 x, int n)
{
//	n %= 32;
	return (x << n) | (x >> (32-n));
}


// Round functions

uint32 f1(uint32 b, uint32 c, uint32 d)
{
	return (b & c) | ((~b) & d);
}

uint32 f24(uint32 b, uint32 c, uint32 d)
{
	return b ^ c ^ d;
}

uint32 f3(uint32 b, uint32 c, uint32 d)
{
	return (b & c) | (b & d) | (c & d);
}

uint32 f(uint32 b, uint32 c, uint32 d, int t)
{
	if (t < 20)
		return f1(b, c, d);
	if (t < 40)
		return f24(b, c, d);
	if (t < 60)
		return f3(b, c, d);
	return f24(b, c, d);
}

// Round constants.

const uint32 K1 = 0x5A827999;
const uint32 K2 = 0x6ED9EBA1;
const uint32 K3 = 0x8F1BBCDC;
const uint32 K4 = 0xCA62C1D6;

uint32 K(int t)
{
	if (t < 20)
		return K1;
	if (t < 40)
		return K2;
	if (t < 60)
		return K3;
	return K4;
}

char IntToHex(int C)
{
	switch (C)
	{
		case 0: return '0';
		case 1: return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';
		case 10: return 'a';
		case 11: return 'b';
		case 12: return 'c';
		case 13: return 'd';
		case 14: return 'e';
		case 15: return 'f';
	}

	return '-';
}

string Hash(string msg)
{
	// We will just hash one 512 bit block.
	// For simplicity we will therefore limit the
	// msg to 512-64-1 = 440 bits (rounded down to 55 bytes.

	if (msg.length() > 55)
		msg.resize(55);

	uint8 block[64];
	for (int i = 0; i < 64; ++i)
		block[i] = 0;

	for (unsigned int i = 0; i < msg.length(); ++i)
		block[i] = msg[i];

	// Append a '1' bit (we're in big endian bit order)
	block[msg.length()] = 0x80;

	// Set the last 64 bits to the length of the message in bits in the original message.

	int bits = msg.length() * 8;
	// Big endian, and it can't be more than 55*8=440.
	block[62] = (bits >> 8) & 0xFF;
	block[63] = (bits) & 0xFF;


	// Now the main computation.
	uint32 A, B, C, D, E;

	uint32 H[5];

	H[0] = 0x67452301;
	H[1] = 0xEFCDAB89;
	H[2] = 0x98BADCFE;
	H[3] = 0x10325476;
	H[4] = 0xC3D2E1F0;

	uint32 W[80];
	for (int i = 0; i < 80; ++i) // Probably not needed.
		W[i] = 0;

	uint32 temp;

	// Fill W.

	for (int i = 0; i < 16; ++i)
		W[i] = (block[i*4] << 24) | (block[i*4 + 1] << 16) | (block[i*4 + 2] << 8) | (block[i*4 + 3]);

	// Do computation.
	for (int t = 16; t < 80; ++t)
		W[t] = S(W[t-3] ^ W[t-8] ^ W[t-14] ^ W[t-16], 1);

	A = H[0];
	B = H[1];
	C = H[2];
	D = H[3];
	E = H[4];

	for (int t = 0; t < 80; ++t)
	{
		temp = S(A, 5) + f(B, C, D, t) + E + W[t] + K(t);
		E = D;
		D = C;
		C = S(B, 30);
		B = A;
		A = temp;
	}

	H[0] += A;
	H[1] += B;
	H[2] += C;
	H[3] += D;
	H[4] += E;

	// The hash is now H0-4.

	string ret;
	for (int i = 0; i < 5; ++i)
	{
		ret += IntToHex((H[i] >> 28) & 0xF);
		ret += IntToHex((H[i] >> 24) & 0xF);
		ret += IntToHex((H[i] >> 20) & 0xF);
		ret += IntToHex((H[i] >> 16) & 0xF);
		ret += IntToHex((H[i] >> 12) & 0xF);
		ret += IntToHex((H[i] >> 8) & 0xF);
		ret += IntToHex((H[i] >> 4) & 0xF);
		ret += IntToHex((H[i]) & 0xF);
	}
	return ret;
}
