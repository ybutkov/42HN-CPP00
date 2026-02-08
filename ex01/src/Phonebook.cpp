/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:51:50 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/08 21:47:20 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <optional>

std::optional<Contact>  Phonebook::getContact(int contactIndex) const
{
    if (contactIndex >= 0 && contactIndex < getSize())
        return m_contacts[contactIndex];
    return std::nullopt;
}

int Phonebook::getSize() const
{
    return m_size;
}

bool Phonebook::addContact(Contact contact)
{
    if (getSize() < CONTACTS_CAPACITY)
    {
        ++m_size;
    }
    if (!updateContact(m_index, contact))
        return false;    
    m_index = (m_index + 1) % CONTACTS_CAPACITY;
    return true;
}

bool Phonebook::updateContact(int index, Contact contact)
{
    if (index < 0 || index >= getSize())
        return false;
    m_contacts[index] = contact;
    return true;
}
