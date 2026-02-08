/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:51:07 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/08 18:20:28 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
  private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_nickName;
	std::string m_phoneNumber;
	std::string m_darkestSecret;

  public:
	Contact() = default;
	Contact(std::string first, std::string last, std::string nick,
			std::string phone, std::string secret);
	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getNickName() const;
	const std::string& getPhoneNumber() const;
	const std::string& getDarkestSecret() const;

	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setNickName(const std::string& nickName);
	void setPhoneNumber(const std::string& phoneNumber);
	void setDarkestSecret(const std::string& darkestSecret);
};

#endif
