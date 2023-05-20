/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:40:19 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/20 16:00:20 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

std::string	toupperStr(std::string str)
{
	size_t	i;

	i = 0;
	while (i < str.length())
	{
		if ('a' <= str.at(i) && str.at(i) <= 'z')
			str.at(i) += ('A' - 'a');
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 1;
		while (i < argc)
		{
			std::cout << toupperStr(argv[i]);
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
} 
