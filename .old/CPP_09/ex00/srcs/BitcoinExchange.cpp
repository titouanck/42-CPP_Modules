/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:15:40 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/17 14:10:06 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

typedef struct s_date
{
	int	year;
	int	month;
	int	day;
}		t_date;

bool	BitcoinExchange::correctlyFormatted(std::string line)
{
	t_date		date;
	bool		bissextile;	

	if (line.length() != 10 || line[4] != '-' || line[7] != '-')
		return (false);
	else if (!isdigit(line[0]) || !isdigit(line[1]) || !isdigit(line[2]) || !isdigit(line[3]) \
	|| !isdigit(line[5]) || !isdigit(line[6]) \
	|| !isdigit(line[8]) || !isdigit(line[9]))
		return (false);
	date.year = atoi(line.c_str());
	date.month = atoi(line.c_str() + 5);
	date.day = atoi(line.c_str() + 8);
	if (date.year < 0 || date.month < 0 || date.day < 0)
		return (false);
	if (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0))
		bissextile = true;
	else
		bissextile = false;
	if (((date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) && date.day > 31) \
	|| ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && date.day > 30) \
	|| (date.month == 2 && bissextile && date.day > 29) || (date.month == 2 && !bissextile && date.day > 28))
		return (false);
	return (true);
}


std::string	BitcoinExchange::_getKey(std::string line)
{
	size_t		pos;
	std::string	key;

	pos = line.find(',');
	if (line.length() < 12 || pos != 10)
		throw (BitcoinExchange::Exception("Error: Date not correctly formated."));
	key = line.substr(0, pos);
	if (!correctlyFormatted(key))
		throw (BitcoinExchange::Exception("Error: Date not correctly formated."));
	return (key);
}

float	BitcoinExchange::_getValue(std::string line)
{
	int		numberOfPoints;
	float	value;

	numberOfPoints = 0;
	line = line.substr(11, line.length() - 11);
	for (int i = 0; line[i]; i++)
	{
		if (!isdigit(line[i]))
		{
			if (line[i] == '.' && numberOfPoints == 0 && line[i + 1])
				numberOfPoints += 1;
			else
				throw (BitcoinExchange::Exception("Error: Value not correctly formated."));
		}
	}
	value = atof(line.c_str());
	return (value);
}

BitcoinExchange::BitcoinExchange(const char *databaseName)
{
	std::ifstream	csvFile;
	std::string		line;
	std::string		key;
	float			value;

	csvFile.open(databaseName);
	if (!csvFile.is_open())
		throw (BitcoinExchange::Exception("Error: could not open database file."));
	if (!getline(csvFile, line) || line.compare("date,exchange_rate") != 0)
	{
		csvFile.close();
		throw (BitcoinExchange::Exception("Error: could not read database file."));
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

float	BitcoinExchange::nearestLowValue(std::string input)
{
	std::map<std::string, float>::iterator	it;
	t_date	thisDate;
	t_date	inputDate;

	if (!correctlyFormatted(input))
		throw (BitcoinExchange::Exception("Error: Input date not correctly formated."));
	inputDate.year = atoi(input.c_str());
	inputDate.month = atoi(input.c_str() + 5);
	inputDate.day = atoi(input.c_str() + 8);
	if (database.size() == 0)
		return (0);
	for (it = database.begin(); it != database.end(); it++)
	{
		thisDate.year = atoi(it->first.c_str());
		thisDate.month = atoi(it->first.c_str() + 5);
		thisDate.day = atoi(it->first.c_str() + 8);
		if (thisDate.year == inputDate.year && thisDate.month == inputDate.month && thisDate.day == inputDate.day)
			return (it->second);
		if (thisDate.year > inputDate.year \
		|| (thisDate.year == inputDate.year && thisDate.month > inputDate.month) \
		|| (thisDate.year == inputDate.year && thisDate.month == inputDate.month && thisDate.day > inputDate.day))
		{
			if (it == database.begin())
				return (0);
			it--;
			return (it->second);
		}
	}
	it = database.end();
	it--;
	return (it->second);
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
