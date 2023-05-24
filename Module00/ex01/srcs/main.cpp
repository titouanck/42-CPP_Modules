/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:40:19 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/24 17:37:15 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

int	main(void)
{
	bool		error;
	phoneBook	myPhoneBook;
	std::string	cmd;

	error = 0;
	while (1)
	{
		std::cout << BLUE "Please type ADD, SEARCH or EXIT." NC << std::endl;
		error = 0;
		if (!getline(std::cin, cmd))
		{
			std::cout << "exit" << std::endl;
			break ;
		}
		cmd = toupperStr(stripStr(cmd));
		if (cmd.compare("ADD") == 0)
			myPhoneBook.add();
		else if (cmd.compare("SEARCH") == 0)
			myPhoneBook.search();
		else if (cmd.compare("EXIT") == 0)
			break ;
		else
		{
			error = 1;
			std::cerr << RED "Invalid entry." NC << std::endl;
		}
		std::cout << std::endl;
	}
	return (0);
} 
