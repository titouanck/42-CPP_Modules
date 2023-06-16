/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:15:40 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/16 16:00:39 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string	BitcoinExchange::_getKey(std::string line)
{
	(void) line;
	throw (BitcoinExchange::Exception("Date not correctly formated."));
}

float	BitcoinExchange::_getValue(std::string line)
{
	(void) line;
	throw (BitcoinExchange::Exception("Value not correctly formated."));
}

BitcoinExchange::BitcoinExchange(const char *databaseName)
{
	std::ifstream	csvFile;
	std::string		line;
	std::string		key;
	float			value;

	csvFile.open(databaseName);
	if (!csvFile.is_open())
		throw (BitcoinExchange::Exception("Could not open database file."));
	if (!getline(csvFile, line) || line.compare("date,exchange_rate") != 0)
	{
		csvFile.close();
		throw (BitcoinExchange::Exception("Could not read database file."));
	}
	while (getline(csvFile, line))
	{
		try
		{
			key = _getKey(line);
			value = _getValue(line);
			database[key] = value;
		}
		catch (std::string exception)
		{
			csvFile.close();
			throw ;
		}
	}
	csvFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange::~BitcoinExchange(void)
{}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	this->database = obj.database;
	return (*this);
}

BitcoinExchange::Exception::Exception(const char *exception) : _exception(exception)
{}

const char	*BitcoinExchange::Exception::what() const throw()
{
	return (_exception);
}
