/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:46:25 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/04 18:07:12 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* PUBLIC ******************************************************************** */

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	unsigned int	date;
	float			value;

	if (!file)
		throw std::runtime_error("btc: could not open database file.");
	std::getline(file, line);
	if (line.compare("date,exchange_rate") != 0)
		throw FORMAT_ERROR;
	while (std::getline(file, line))
	{
		if (line.length() < 12 || line.c_str()[10] != ',')
			throw FORMAT_ERROR;
		try
		{
			date  = BitcoinExchange::getDate(line.substr(0, 10));
			value = BitcoinExchange::getValue(line.substr(11));
			if (this->_database.find(date) != this->_database.end())
				throw FORMAT_ERROR;
		}
		catch (...)
		{
			throw ;
		}
		this->_database[date] = value;
	}
}

BitcoinExchange::~BitcoinExchange()
{
}

/* ************************************************************************** */

void	BitcoinExchange::print()
{
	std::map<unsigned int, float>::iterator	it;

	it = this->_database.begin();
	while (it != this->_database.end())
	{
		std::cout << "[" << it->first << "]" << " = " << it->second << std::endl;
		it++;
	}
}

float	BitcoinExchange::getExchangeRate(unsigned int date)
{
	std::map<unsigned int, float>::iterator it;

	it = this->_database.begin();
	if (it == this->_database.end() || date < it->first)
		return 0;
	while (it != this->_database.end())
	{
		if (date == it->first)
			return it->second;
		else if (date < it->first)
			break ;
		it++;
	}
	if (it != this->_database.begin())
	{
		it--;
		return it->second;
	}
	return 0;
}

/* PUBLIC STATIC MEMBER FUNCTIONS ******************************************* */

unsigned int	BitcoinExchange::getDate(std::string str)
{
	unsigned int	date;

	date = 0;
	if (str.length() != 10)
		throw DATE_ERROR;
	for (unsigned int i = 0; str[i]; i++)
	{
		if ((i == 4 || i == 7) && str[i] == '-');
		else if ('0' <= str[i] && str[i] <= '9')
		{
			date *= 10;
			date += str[i] - '0';
		}
		else
			throw DATE_ERROR;
	}
	if (!existingDate(date))
		throw DATE_ERROR;
	return date;
}

float	BitcoinExchange::getValue(std::string str)
{
	float	value;
	char	*ptr;

	value = strtof(str.c_str(), &ptr);
	if (value >= 0 && ptr == str.c_str() + str.length())
		return value;
	else
		throw VALUE_ERROR;
}

/* PRIVATE ****************************************************************** */

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	(void)	copy;

	return *this;
}

/* ************************************************************************** */
