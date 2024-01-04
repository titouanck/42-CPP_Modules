/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:53:29 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/04 15:31:13 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.hpp"
#include "comments.hpp"

/* ************************************************************************** */

// static unsigned int	parseDate(std::string line)
// {
// 	// unsigned int	date;
// 	(void)	line;

// 	return true;
// }

// static unsigned int	parseValue(std::string line)
// {
// 	(void)	line;

// 	return true;
// }

bool	parsing(std::string filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line;

	if (!file)
		return false;
	std::getline(file, line);
	if (line.compare("date | value") != 0)
		return false;
	while (std::getline(file, line))
	{
		std::cout << "+1" << std::endl;
		std::cout << TCK_BLUE << line << TCK_NC << std::endl;
	}
	return true;
}

/* ************************************************************************** */
