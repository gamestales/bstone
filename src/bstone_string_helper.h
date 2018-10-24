/*
BStone: A Source port of
Blake Stone: Aliens of Gold and Blake Stone: Planet Strike

Copyright (c) 1992-2013 Apogee Entertainment, LLC
Copyright (c) 2013-2015 Boris I. Bendovsky (bibendovsky@hotmail.com)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the
Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/


#ifndef BSTONE_STRING_HELPER_INCLUDED
#define BSTONE_STRING_HELPER_INCLUDED


#include <locale>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>


namespace bstone
{


using StringList = std::vector<std::string>;


struct StringHelper final
{
public:
	char to_lower(
		const char value) const;

	std::string to_lower(
		const std::string& value) const;

	template<typename T, typename U>
	T lexical_cast(
		const U& src_value) const
	{
		auto oss = std::stringstream{};
		oss << src_value;

		auto result = T{};
		oss >> result;

		if (oss)
		{
			return result;
		}

		throw std::runtime_error("lexical_cast");
	}

	template<typename T, typename U>
	bool lexical_cast(
		const T& src_value,
		U& dst_value) const
	{
		auto oss = std::stringstream{};

		oss.unsetf(std::ios_base::skipws);
		oss << src_value;
		oss >> dst_value;

		return !oss.fail();
	}

	bool is_iequal(
		const std::string& a,
		const std::string& b) const;

	bool is(
		std::ctype_base::mask mask,
		const char value) const;

	const std::string& get_empty() const;
}; // StringHelper


} // bstone


#endif // !BSTONE_STRING_HELPER_INCLUDED
