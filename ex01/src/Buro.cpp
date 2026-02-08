/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Buro.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:51:32 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/08 21:50:39 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Buro.hpp"
#include <iomanip>
#include <iostream>
#include <optional>
#include <cctype>

namespace
{
bool	isNumber(std::string str, std::size_t from = 0)
{
	for (std::size_t i = from; i < str.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
	}
	return (true);
}

std::optional<std::string> inputString(std::string prompt)
{
	std::string newString;
	while (true)
	{
		std::cout << "Input " << prompt << ": ";
		if (!std::getline(std::cin, newString))
		{
			std::cout << "\nEOF" << std::endl;
			return (std::nullopt);
		}
		if (!newString.empty())
			break ;
		std::cout << "Can't be empty line. Try again" << std::endl;
	}
	return (newString);
}

bool	checkPhoneNumber(std::string phoneNumber)
{
	if (phoneNumber.empty())
	{
		return false;
	}
	if ((isNumber(phoneNumber) && phoneNumber.size() >= 7 && phoneNumber.size() <= 15)
		|| (phoneNumber[0] == '+' && isNumber(phoneNumber, 1)
			&& phoneNumber.size() >= 8 && phoneNumber.size() <= 16))
		return (true);
	return (false);
}

} // namespace

const Phonebook& Buro::getPhonebook() const
{
	return (*m_phonebook);
}

Phonebook& Buro::getPhonebook()
{
	return (*m_phonebook);
}

Printer& Buro::getPrinter()
{
	return (*m_printer);
}

const Printer& Buro::getPrinter() const
{
	return (*m_printer);
}

void Buro::setPhonebook(Phonebook* phonebook)
{
	this->m_phonebook = phonebook;
}

void Buro::setPrinter(Printer* printer)
{
	this->m_printer = printer;
}

void Buro::addContact()
{
	std::optional<std::string> firstName;
	std::optional<std::string> lastName;
	std::optional<std::string> nickName;
	std::optional<std::string> phoneNumber;
	std::optional<std::string> darkestSecret;
	firstName = inputString("first name");
	if (!firstName.has_value())
	{
		return ;
	}
	lastName = inputString("last name");
	if (!lastName.has_value())
	{
		return ;
	}
	nickName = inputString("nick name");
	if (!nickName.has_value())
	{
		return ;
	}
	while (true)
	{
		phoneNumber = inputString("phone number");
		if (!phoneNumber.has_value())
		{
			return ;
		}
		if (checkPhoneNumber(phoneNumber.value()))
			break ;
		std::cout << "Input correct phone number (+)7-15 digits" << std::endl;
	}
	darkestSecret = inputString("darkest secret");
	if (!darkestSecret.has_value())
	{
		return ;
	}
	getPhonebook().addContact({firstName.value(), lastName.value(),
		nickName.value(), phoneNumber.value(), darkestSecret.value()});
}

void Buro::searchContact()
{
	int	index;

	std::optional<Contact> contact;
	std::string str;
	if (getPhonebook().getSize() == 0)
	{
		std::cout << "Empty phonebook. Nothing to print" << std::endl;
		return ;
	}
	std::cout << "List of contacts" << std::endl;
	getPrinter().printPhonebook(getPhonebook());
	while (true)
	{
		std::cout << "Input contact index: ";
		if (!std::getline(std::cin, str))
		{
			break ;
		}
		if (str.empty() || !isNumber(str))
		{
			std::cout << "  I will accept only correct number" << std::endl;
			continue ;
		}
		index = std::stoi(str);
		contact = getPhonebook().getContact(index);
		if (!contact.has_value())
		{
			std::cout << "  Not correct index. Try again" << std::endl;
			continue ;
		}
		getPrinter().printContact(contact.value());
		break ;
	}
}

void Buro::work()
{
	std::string choice;
    // m_phonebook->addContact({"aaaaaaaa", "bbbb", "cccc", "123456789012", "dark1" });
    // m_phonebook->addContact({"aaaaaaaa2", "bbbb2", "cccc2", "223456789012","dark2" });
    // m_phonebook->addContact({"aaaaaaaaaaaaa3", "bbbb3", "cccc3", "323456789012", "dark3" });
    // m_phonebook->addContact({"aaaaaaaaaaaaa4", "bbbb4", "cccc4", "423456789012", "dark4" });
    // m_phonebook->addContact({"aaaaaaaaaaaaa5", "bbbb5", "cccc5", "523456789012", "dark5" });
    // m_phonebook->addContact({"aaaaaaaaaaaaa6", "bbbb6", "cccc6", "623456789012", "dark6" });
    std::cout << "Buro is open" << std::endl;
    while (true)
    {
		if (std::cin.eof())
		{
			break ;
		}
	    std::cout << "Enter one of three commands(ADD, SEARCH or EXIT): ";
	    if (!std::getline(std::cin, choice))
            break;
	    if (choice == "SEARCH")
	    	searchContact();
	    else if (choice == "ADD")
	    	addContact();
	    else if (choice == "EXIT")
	    	break ;
	    else
	    	std::cout << "Read above! Only (ADD, SEARCH or EXIT)" << std::endl;
    }
    std::cout << "Buro is closed" << std::endl;
}
