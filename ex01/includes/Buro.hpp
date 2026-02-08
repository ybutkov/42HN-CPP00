/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Buro.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:51:00 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/08 21:28:05 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Buro_HPP
# define Buro_HPP

# include "Phonebook.hpp"
# include "Printer.hpp"

class Buro
{
  private:
	Phonebook* m_phonebook;
	Printer* m_printer;

  public:
	Buro(Phonebook* phonebook, Printer* printer)
		: m_phonebook(phonebook), m_printer(printer) {};
	void work();
	void addContact();
	void searchContact();
	Phonebook& getPhonebook();
	const Phonebook& getPhonebook() const;
	Printer& getPrinter();
	const Printer& getPrinter() const;
	void setPhonebook(Phonebook* phonebook);
	void setPrinter(Printer* printer);
};

#endif
