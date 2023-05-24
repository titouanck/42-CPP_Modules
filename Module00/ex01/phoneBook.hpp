/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:40:19 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/24 01:57:39 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <climits>

class contact
{
	public:
		bool		init;
		int			n;
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone;
};

class phoneBook
{
	private:
		contact	contacts[8];

	public:
		void	add(std::string, std::string, std::string, std::string);

		int		oldest();
		void	print();

		phoneBook();
};

#endif
