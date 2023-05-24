/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:40:19 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/24 17:48:01 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

static int	_search_errCheck(std::string input, int initialized);
static void	_search_display(contact theContact, int index);
static void	_search_formatField(std::string str);

phoneBook::phoneBook()
{
	for (size_t i = 0; i < MAX_CONTACTS; i++)
		contacts[i].init = false;
	initialized = 0;
}

void	phoneBook::add()
{
	int			i;
	contact		newContact;

	if (initialized < MAX_CONTACTS)
		i = initialized;
	else
	{
		phoneBook::overwrites();
		i = MAX_CONTACTS - 1;
	}
	if (!getInput("firstname", newContact.firstname, 1))
		return ;
	if (!getInput("lastname", newContact.lastname, 1))
		return ;
	if (!getInput("nickname", newContact.nickname, 1))
		return ;
	if (!getInput("phone number", newContact.phone, 2))
		return ;
	if (!getInput("darkest secret", newContact.darkestSecret, 1))
		return ;
	newContact.init = true;
	contacts[i] = newContact;
	if (initialized < MAX_CONTACTS)
		initialized += 1;
}

void	phoneBook::search()
{
	std::string	input;
	long		index;

	if (contacts[0].init == false)
	{
		std::cout << "The phoneBook is currently empty." << std::endl;
		return ;
	}
	for (size_t i = 0; i < MAX_CONTACTS; i++)
	{
		if (contacts[i].init)
		{
			std::cout << "         " << i;
			_search_formatField(contacts[i].firstname);
			_search_formatField(contacts[i].lastname);
			_search_formatField(contacts[i].nickname);
			_search_formatField(contacts[i].phone);
			_search_formatField(contacts[i].darkestSecret);
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	if (!getInput("index", input, 1) || _search_errCheck(input, initialized) == -1)
		return ;
	index = atoi(input.c_str());
	_search_display(contacts[index], index);
}

void	phoneBook::overwrites()
{
	for (size_t i = 0; i < MAX_CONTACTS - 1; i++)
		contacts[i] = contacts[i + 1];
}

static int	_search_errCheck(std::string input, int initialized)
{
	long	index;

	if (input.length() < 1 || input.length() > MAX_CONTACTS / 10 + 1)
	{
		std::cerr << RED "Index should be in range (0 - " << initialized - 1 << ")." NC << std::endl;
		return (-1);
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input.at(i)))
		{
			std::cerr << RED "Index should only contain digits." NC << std::endl;
			return (-1);
		}
	}
	index = atoi(input.c_str());
	if (index > initialized - 1)
	{
		std::cerr << RED "Index should be in range (0 - " << initialized - 1 << ")." NC << std::endl;
		return (-1);
	}
	return (index);
}


static void	_search_display(contact theContact, int index)
{
	std::cout << "---" << std::endl;
	std::cout << index << "'s firstname: " << theContact.firstname << std::endl;
	std::cout << index << "'s lastname: " << theContact.lastname << std::endl;
	std::cout << index << "'s nickname: " << theContact.nickname << std::endl;
	std::cout << index << "'s phone number: " << theContact.phone << std::endl;
	std::cout << index << "'s darkest secret: " << theContact.darkestSecret << std::endl;
	std::cout << "---" << std::endl;
}

static void	_search_formatField(std::string str)
{
	int	length;

	std::cout << '|';
	length = str.length();
	if (length <= 10)
	{
		for (int i = 0; i < 10 - length; i++)
			std::cout << ' ';
		std::cout << str;
	}
	else
		std::cout << str.substr(0, 9) << '.';
}

