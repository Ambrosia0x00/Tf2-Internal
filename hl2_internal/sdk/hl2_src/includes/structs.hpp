#pragma once
#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include<sstream>

struct PlayerInfo_t
{
	char name[128];
	int userId;
	uint32_t friendsId;
	char friendsName[128];
};

struct Color_t
{
	unsigned char r = 0, g = 0, b = 0, a = 0;
	bool operator==(Color_t clr) const
	{
		return (r == clr.r && g == clr.g && b == clr.b && a == clr.a);
	}
	bool operator!=(Color_t clr) const
	{
		return !(r == clr.r && g == clr.g && b == clr.b && a == clr.a);
	}
	[[nodiscard]] std::string to_hex() const
	{
		std::stringstream stream;
		stream << "\x7";
		stream << std::hex << (static_cast<int>(r) << 16 | static_cast<int>(g) << 8 | static_cast<int>(b));
		return stream.str();
	}
	[[nodiscard]] std::string to_hex_alpha() const
	{
		std::stringstream stream;
		stream << "\x8";
		stream << std::hex << (static_cast<int>(r) << 16 | static_cast<int>(g) << 8 | static_cast<int>(b));
		stream << std::hex << static_cast<int>(a);
		return stream.str();
	}
};

#endif