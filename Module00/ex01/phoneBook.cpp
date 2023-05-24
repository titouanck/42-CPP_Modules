/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:40:19 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/24 02:00:10 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

phoneBook::phoneBook()
{
	for (size_t i = 0; i < 8; i++)
	{
		contacts[i].n = i;
		contacts[i].init = false;
	}
}

int	phoneBook::oldest()
{
	int		oldest;
	int		minIdx;

	// To avoid eventual int overflow
	if (contacts[0].n > 8)
		for (size_t i = 0; i < 8; i++)
			contacts[i].n -= 8;

	// We search for the initalized instance with the lowest index
	minIdx = INT_MAX;
	for (size_t i = 0; i < 8; i++)
	{
		if (contacts[i].init && contacts[i].n < minIdx)
		{
			minIdx = contacts[i].n;
			oldest = i;
		}
	}
	if (minIdx == INT_MAX)
		return (-1);
	return (oldest);
}

void	phoneBook::print()
{
	for (size_t i = 0; i < 8; i++)
		std::cout << "Contacts[" << i << "] = " \
		<< contacts[i].firstname << " . " \
		<< contacts[i].lastname << " . " \
		<< contacts[i].nickname << " . " \
		<< contacts[i].phone << " . " \
		<< contacts[i].n << std::endl;
}

void	phoneBook::add(std::string firstname, std::string lastname, \
		std::string nickname, std::string phone)
{
	static int	initialized;
	int			i;

	if (initialized < 8)
		i = initialized;
	else
		i = phoneBook::oldest();
	contacts[i].firstname = firstname;
	contacts[i].lastname = lastname;
	contacts[i].nickname = nickname;
	contacts[i].phone = phone;
	contacts[i].init = true;
	contacts[i].n += 8;
	initialized += 1;
}

std::string	toupperStr(std::string str)
{
	size_t	length;
	size_t	i;

	length = str.length();
	i = 0;
	while (i < length)
	{
		if ('a' <= str.at(i) && str.at(i) <= 'z')
			str.at(i) += ('A' - 'a');
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	(void) argc; (void) argv;

	phoneBook	myPhoneBook;

	// myPhoneBook.print();
	myPhoneBook.add("Alpha", "Beta", "Charlie", "+33 6 12 34 56");
	myPhoneBook.add("Alpha", "Beta", "Charlie", "+33 6 12 34 56");
	myPhoneBook.add("Alpha", "Beta", "Charlie", "+33 6 12 34 56");
	myPhoneBook.print();
	return (0);
} 
