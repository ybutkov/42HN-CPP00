/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:51:55 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/08 00:13:42 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Printer.hpp"
#include <iomanip>
#include <iostream>

namespace
{
std::string truncateString(std::string str, std::size_t width = 10)
{
	if (str.size() < width)
		return (str);
	return (str.substr(0, width - 1) + ".");
}

} // namespace

std::ostream &Printer::getOut()
{
	return (*out);
}

void Printer::printPhonebook(const Phonebook &phonebook)
{
	getOut() << "┌──────────┬──────────┬──────────┬──────────┐\n";
	getOut() << "│     Index│First Name│ Last Name│  Nickname│\n";
	getOut() << "├──────────┼──────────┼──────────┼──────────┤\n";
	for (int i = 0; i < phonebook.getSize(); ++i)
	{
		auto opt = phonebook.getContact(i);
		if (opt.has_value())
			printTableRow(i, phonebook.getContact(i).value());
	}
	getOut() << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}

void Printer::printTableRow(int index, const Contact &contact)
{
	getOut() << "│" << std::setw(10)
				<< index
				<< "│" << std::setw(10)
				<< truncateString(contact.getFirstName())
				<< "│" << std::setw(10)
				<< truncateString(contact.getLastName())
				<< "│" << std::setw(10)
				<< truncateString(contact.getNickName())
				<< "│" 	<< std::endl;
}

void Printer::printContact(const Contact &contact)
{
	getOut() << "┌───────────────────────────────────────────┐\n";
	getOut() << "│" <<std::left << "First name: " << std::setw(31) 
			<< truncateString(contact.getFirstName(), 31) << "│\n"
			<< "│" <<std::left << "Last name: " << std::setw(32)
			<< truncateString(contact.getLastName(), 32) << "│\n"
			<< "│" <<std::left << "Nick name: " << std::setw(32)
			<< truncateString(contact.getNickName(), 32) << "│\n"
			<< "│" <<std::left << "Phone number: " << std::setw(29)
			<< truncateString(contact.getPhoneNumber(), 29) << "│\n"
			<< "│" <<std::left << "Darkest secret: " << std::setw(27)
			<< truncateString(contact.getDarkestSecret(), 27) << "│\n";
	getOut() << "└───────────────────────────────────────────┘" << std::endl;
}
