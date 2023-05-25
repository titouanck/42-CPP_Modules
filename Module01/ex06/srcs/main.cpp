/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:17:50 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 13:19:05 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	actions(int level)
{
	Harl		complainer;

	switch(level)
	{
		case 0:
			std::cout << "[ DEBUG ]\n";
			complainer.complain("DEBUG");
			std::cout << std::endl;
			actions(level + 1);
			break ;
		case 1:
			std::cout << "[ INFO ]\n";
			complainer.complain("INFO");
			std::cout << std::endl;
			actions(level + 1);
			break ;
		case 2:
			std::cout << "[ WARNING ]\n";
			complainer.complain("WARNING");
			std::cout << std::endl;
			actions(level + 1);
			break ;
		case 3:
			std::cout << "[ ERROR ]\n";
			complainer.complain("ERROR");
			std::cout << std::endl;
			break ;
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}

int	main(int argc, char **argv)
{
	std::string	buffer;
	int			level;

	if (argc != 2)
		return (std::cerr << "usage: ./harlFilter <level>\n", 1);
	buffer = argv[1];
	if (buffer.compare("DEBUG") == 0)
		level = 0;
	else if (buffer.compare("INFO") == 0)
		level = 1;
	else if (buffer.compare("WARNING") == 0)
		level = 2;
	else if (buffer.compare("ERROR") == 0)
		level = 3;
	else
		level = 4;
	actions(level);
}
