/*
BStone: Unofficial source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike
Copyright (c) 1992-2013 Apogee Entertainment, LLC
Copyright (c) 2013-2022 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors
SPDX-License-Identifier: GPL-2.0-or-later
*/


//
// Former ID_US_A.ASM
//


#include <chrono>
#include <cstdint>


// Force compiler to emit a symbol.
extern const std::uint8_t rndtable[256];


const std::uint8_t rndtable[256] = {
	0x00, 0x08, 0x6D, 0xDC, 0xDE, 0xF1, 0x95, 0x6B, 0x4B, 0xF8, 0xFE, 0x8C,
	0x10, 0x42, 0x4A, 0x15, 0xD3, 0x2F, 0x50, 0xF2, 0x9A, 0x1B, 0xCD, 0x80,
	0xA1, 0x59, 0x4D, 0x24, 0x5F, 0x6E, 0x55, 0x30, 0xD4, 0x8C, 0xD3, 0xF9,
	0x16, 0x4F, 0xC8, 0x32, 0x1C, 0xBC, 0x34, 0x8C, 0xCA, 0x78, 0x44, 0x91,
	0x3E, 0x46, 0xB8, 0xBE, 0x5B, 0xC5, 0x98, 0xE0, 0x95, 0x68, 0x19, 0xB2,
	0xFC, 0xB6, 0xCA, 0xB6, 0x8D, 0xC5, 0x04, 0x51, 0xB5, 0xF2, 0x91, 0x2A,
	0x27, 0xE3, 0x9C, 0xC6, 0xE1, 0xC1, 0xDB, 0x5D, 0x7A, 0xAF, 0xF9, 0x00,
	0xAF, 0x8F, 0x46, 0xEF, 0x2E, 0xF6, 0xA3, 0x35, 0xA3, 0x6D, 0xA8, 0x87,
	0x02, 0xEB, 0x19, 0x5C, 0x14, 0x91, 0x8A, 0x4D, 0x45, 0xA6, 0x4E, 0xB0,
	0xAD, 0xD4, 0xA6, 0x71, 0x5E, 0xA1, 0x29, 0x32, 0xEF, 0x31, 0x6F, 0xA4,
	0x46, 0x3C, 0x02, 0x25, 0xAB, 0x4B, 0x88, 0x9C, 0x0B, 0x38, 0x2A, 0x92,
	0x8A, 0xE5, 0x49, 0x92, 0x4D, 0x3D, 0x62, 0xC4, 0x87, 0x6A, 0x3F, 0xC5,
	0xC3, 0x56, 0x60, 0xCB, 0x71, 0x65, 0xAA, 0xF7, 0xB5, 0x71, 0x50, 0xFA,
	0x6C, 0x07, 0xFF, 0xED, 0x81, 0xE2, 0x4F, 0x6B, 0x70, 0xA6, 0x67, 0xF1,
	0x18, 0xDF, 0xEF, 0x78, 0xC6, 0x3A, 0x3C, 0x52, 0x80, 0x03, 0xB8, 0x42,
	0x8F, 0xE0, 0x91, 0xE0, 0x51, 0xCE, 0xA3, 0x2D, 0x3F, 0x5A, 0xA8, 0x72,
	0x3B, 0x21, 0x9F, 0x5F, 0x1C, 0x8B, 0x7B, 0x62, 0x7D, 0xC4, 0x0F, 0x46,
	0xC2, 0xFD, 0x36, 0x0E, 0x6D, 0xE2, 0x47, 0x11, 0xA1, 0x5D, 0xBA, 0x57,
	0xF4, 0x8A, 0x14, 0x34, 0x7B, 0xFB, 0x1A, 0x24, 0x11, 0x2E, 0x34, 0xE7,
	0xE8, 0x4C, 0x1F, 0xDD, 0x54, 0x25, 0xD8, 0xA5, 0xD4, 0x6A, 0xC5, 0xF2,
	0x62, 0x2B, 0x27, 0xAF, 0xFE, 0x91, 0xBE, 0x54, 0x76, 0xDE, 0xBB, 0x88,
	0x78, 0xA3, 0xEC, 0xF9,
};


static int rndindex;


void US_InitRndT(
	bool randomize)
{
	if (!randomize)
	{
		rndindex = 0;
	}
	else
	{
		using Clock = std::chrono::system_clock;

		auto ticks = (Clock::now() - Clock::time_point()).count();
		rndindex = static_cast<int>(ticks % 256);
	}
}

std::int16_t US_RndT()
{
	rndindex = (rndindex + 1) & 0xFF;
	return rndtable[rndindex];
}
