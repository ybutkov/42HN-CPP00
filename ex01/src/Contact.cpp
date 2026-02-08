/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:51:38 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/08 18:21:16 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string first, std::string last, std::string nick,
		std::string phone, std::string secret)
	: m_firstName(std::move(first)), m_lastName(std::move(last)),
		m_nickName(std::move(nick)), m_phoneNumber(std::move(phone)),
		m_darkestSecret(std::move(secret))
{
}

const std::string& Contact::getFirstName() const
{
	return (m_firstName);
}

const std::string& Contact::getLastName() const
{
	return (m_lastName);
}

const std::string& Contact::getNickName() const
{
	return (m_nickName);
}

const std::string& Contact::getPhoneNumber() const
{
	return (m_phoneNumber);
}

const std::string& Contact::getDarkestSecret() const
{
	return (m_darkestSecret);
}

void Contact::setFirstName(const std::string &firstName)
{
	this->m_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
	this->m_lastName = lastName;
}

void Contact::setNickName(const std::string &nickName)
{
	this->m_nickName = nickName;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	this->m_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	this->m_darkestSecret = darkestSecret;
}
