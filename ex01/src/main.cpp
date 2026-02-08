/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:51:44 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/08 21:11:00 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Buro.hpp"

int main()
{
	Phonebook phonebook;
	Printer printer(std::cout);
	// Printer printer(std::cerr);
	Buro buro(&phonebook, &printer);
	phonebook.addContact({"John", "Doe", "Johnny", "1234567", "secret"});
	// Printer printer2(std::cerr);
	// buro.setPrinter(printer2);
	buro.work();
	return (0);
}
