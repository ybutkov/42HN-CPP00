/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:51:21 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/07 18:10:03 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_HPP
# define PRINTER_HPP

# include "Phonebook.hpp"
# include <iostream>
# include <ostream>
# include <string>

class Printer
{
	private:
		std::ostream* out;
		void printTableRow(int index, const Contact& contact);
	public:
		Printer(std::ostream& out=std::cout): out(&out) {}
		Printer(const Printer& printer) = default;
		std::ostream& getOut();
		void printPhonebook(const Phonebook& phonebook);
		void printContact(const Contact& contact);
};

#endif
