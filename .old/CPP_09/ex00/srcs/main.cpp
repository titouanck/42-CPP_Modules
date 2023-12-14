/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:52:44 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/17 14:39:20 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	fileCorrectlyFormated(std::ifstream &file)
{
	std::string	line;

	if (!file.is_open())
		return (std::cerr << "Error: could not open file.\n", false);
	if (!getline(file, line) || line.compare("date | value") != 0)
	{
		file.close();
		return (std::cerr << "Error: could not read file.\n", false);
	}
	return (true);
}

void	requestDb(BitcoinExchange &btc, std::string line)
{
	std::string	first;
	std::string	middle;
	std::string	second;
	int			numberOfPoints;
	float		value;

	if (line.length() < 14)
		{ std::cerr << "Error: bad input => " << line << std::endl; return ; }
	first = line.substr(0, 10);
	middle = line.substr(10, 3);
	second = line.substr(13, line.length() - 13);
	if (!BitcoinExchange::correctlyFormatted(first) || middle.compare(" | ") != 0)
		{ std::cerr << "Error: bad input => " << line << std::endl; return ; }
	numberOfPoints = 0;
	line = second;
	for (int i = 0; line[i]; i++)
	{
		if (!isdigit(line[i]))
		{
			if (line[i] == '.' && numberOfPoints == 0 && line[i + 1])
				numberOfPoints += 1;
			else
				{ std::cerr << "Error: not a positive number." << std::endl; return ; }
		}
	}
	if (second.length() > 4)
		{ std::cerr << "Error: too large a number." << std::endl; return ; }
	value = atof(line.c_str());
	try
	{
		std::cout << first << " => " << second << " = " << btc.nearestLowValue(first) * value << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(int argc, char **argv)
{
	std::ifstream	file;
	std::string		line;

	if (argc != 2)
		return (std::cerr << "Error: could not open file.\n", 1);
	file.open(argv[1]);
	if (!fileCorrectlyFormated(file))
		return (1);
	try
	{
		BitcoinExchange	btc("data.csv");

		while (getline(file, line))
			requestDb(btc, line);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		file.close();
		return (1);
	}
	file.close();
	return (0);
}
