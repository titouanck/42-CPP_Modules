/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:40:19 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/24 17:35:39 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
	#define PHONEBOOK_HPP

	#include <iostream>
	#include <string>
	#include <climits>
	#include <algorithm>

	#define MAX_CONTACTS 8

	#ifdef MAX_CONTACTS
		#if MAX_CONTACTS < 1
		#error "MAX_CONTACTS must be greater than or equal to 1."
		#endif

		#if MAX_CONTACTS > INT_MAX
		#error "MAX_CONTACTS is greater than the maximum value of int."
		#endif
	#else
		#error "MAX_CONTACTS must be defined."
	#endif

	#define RED "\033[0;31m"
	#define GREEN "\033[0;32m"
	#define BLUE "\033[0;34m"
	#define NC "\033[0m"

class contact
{
	public:
		bool		init;
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone;
		std::string	darkestSecret;
};

class phoneBook
{
	private:
		contact	contacts[MAX_CONTACTS];
		int		initialized;

	public:
		void	add();
		void	search();
		void	overwrites();

		phoneBook();
};

/* Utils */

bool		getInput(std::string field, std::string &str, int format);
std::string	stripStr(std::string str);
std::string	toupperStr(std::string str);

#endif
