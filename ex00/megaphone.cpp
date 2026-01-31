/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:37:18 by ybutkov           #+#    #+#             */
/*   Updated: 2026/01/18 22:05:06 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>
#include <string_view>

constexpr std::string_view DEFAULT_MSG = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

void	string_toupper(std::string &str)
{
	for (std::string::size_type i = 0; i < str.size(); ++i)
		str[i] = std::toupper(str[i]);
}

int	main(int argc, char **argv)
{
	std::string str;
	if (argc == 1)
		std::cout << DEFAULT_MSG;
	else
		for (int i = 1; i < argc; ++i)
		{
			str = argv[i];
			string_toupper(str);
			std::cout << str;
		}
	std::cout << std::endl;
	return (0);
}
