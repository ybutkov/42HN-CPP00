/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:37:18 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/07 22:31:32 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>
#include <string_view>

constexpr std::string_view DEFAULT_MSG = "* LouD aND uNBEArABLE FeedBACK noise *";

namespace {
	
void	string_toupper(std::string &str)
{
	for (std::string::size_type i = 0; i < str.size(); ++i)
		str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
}
} // end namespace

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::string tmp{DEFAULT_MSG};
		string_toupper(tmp);
		std::cout << tmp << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; ++i)
	{
		std::string str = argv[i];
		string_toupper(str);
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
