/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:53:29 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/04 17:58:39 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.hpp"

static unsigned int	getDate(std::string str);
static float		getValue(std::string str);

/* ************************************************************************** */

void	parsing(BitcoinExchange &db, std::string filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	std::string		readableDate;
	unsigned int	date;
	float			value;

	if (!file)
		throw std::runtime_error("Error: could not open file.");
	std::getline(file, line);
	if (line.compare("date | value") != 0)
		throw FORMAT_ERROR;
	while (std::getline(file, line))
	{
		if (line.length() < 14 || line.substr(10, 3).compare(" | ") != 0)
			std::cerr << "Error: bad input => " << line << std::endl;
		else
		{
			try
			{
				double	result;
		
				readableDate = line.substr(0, 10);
				date  = getDate(readableDate);
				value = getValue(line.substr(13));
				
				result =  static_cast<double>(value) * static_cast<double>(db.getExchangeRate(date));
				std::cout << readableDate << " => " << value << " = ";
				std::cout << std::setprecision(2) << result << std::endl;
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
	}
}

/* ************************************************************************** */

static unsigned int	getDate(std::string str)
{
	unsigned int	date;
	std::string		errorMsg;

	errorMsg = "Error: bad input => " + str;

	date = 0;
	if (str.length() != 10)
		throw std::runtime_error(errorMsg.c_str());
	for (unsigned int i = 0; str[i]; i++)
	{
		if ((i == 4 || i == 7) && str[i] == '-');
		else if ('0' <= str[i] && str[i] <= '9')
		{
			date *= 10;
			date += str[i] - '0';
		}
		else
			throw std::runtime_error(errorMsg.c_str());
	}
	if (!existingDate(date))
		throw std::runtime_error(errorMsg.c_str());
	return date;
}

static float	getValue(std::string str)
{
	float		value;
	char		*ptr;
	std::string	errorMsg;

	value = strtof(str.c_str(), &ptr);
	if (value < 0)
		throw std::runtime_error("Error: not a positive number.");
	else if (value > 1000)
		throw std::runtime_error("Error: too large a number.");
	else if (ptr == str.c_str() + str.length())
		return value;
	else
	{
		errorMsg = "Error: bad input => " + str;
		throw std::runtime_error(errorMsg.c_str());
	}
}

/* ************************************************************************** */
