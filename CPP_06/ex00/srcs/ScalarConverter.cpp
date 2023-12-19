/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:07:56 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/19 12:01:03 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "printConversions.hpp"

/* ************************************************************************** */

static bool	getChar(std::string literal, char &c);
static bool	getInt(std::string literal, int &i);
static bool	getFloat(std::string literal, float &f);
static bool	getDouble(std::string literal, double &d);

long	sign;

/* ************************************************************************** */

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)	copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)	copy;
	return *this;
}
ScalarConverter::~ScalarConverter()
{
}

/* ************************************************************************** */

bool	ScalarConverter::convert(std::string literal)
{
	if (literal.length() < 1)
		return false;
	
	char	c;
	bool	isChar = getChar(literal, c);

	int		i;
	bool	isInt = getInt(literal, i);
	
	float	f;
	bool	isFloat = getFloat(literal, f);

	double	d;
	bool 	isDouble = getDouble(literal, d);

	if (isInt)
		printConversions(i);
	else if (isChar)
		printConversions(c);
	else if (isFloat)
		printConversions(f);
	else if (isDouble)
		printConversions(d);
	else
	{
		std::cout << "convert: bad input." << std::endl;
		return false;
	}
	return true;
}

/* ************************************************************************** */

static bool	getChar(std::string literal, char &c)
{
	if (literal.length() == 1)
		c = literal.c_str()[0];
	else if (literal.length() == 3 && literal.c_str()[0] == '\'' && literal.c_str()[2] == '\'')
		c = literal.c_str()[1];
	else
		c = -1;

	if (c >= 32 && 126 >= c)
		return true;
	else
		return false;
}

static bool	getInt(std::string literal, int &i)
{
	long	nbr;
	int		index;

	nbr = 0;
	if (literal.length() == 1 && (literal.c_str()[0] == '-' || literal.c_str()[0] == '+'))
		return false;
	else if (literal.c_str()[0] == '-')
	{
		sign = -1;
		literal = literal.c_str() + 1;
	}
	else
	{
		sign = 1;
		if (literal.c_str()[0] == '+')
			literal = literal.c_str() + 1;
	}

	index = 0;
	while ('0' <= literal.c_str()[index] && literal.c_str()[index] <= '9')
	{
		nbr = nbr * 10 + literal.c_str()[index] - '0';
		if (nbr > 2147483648)
			return false;
		index++;
	}

	nbr = nbr * sign;
	if (-2147483648 <= nbr && nbr <= 2147483647 && literal.c_str()[index] == '\0')
	{
		i = nbr;
		return true;
	}
	else
		return false;
}

static bool	getFloat(std::string literal, float &f)
{
	char		*ptr;

	f = strtof(literal.c_str(), &ptr);
	if (literal.length() >= 2 && (literal.c_str() + literal.length() - 1) == ptr && *ptr == 'f')
		return true;
	else
		return false;
}

static bool	getDouble(std::string literal, double &d)
{
	char		*ptr;

	d = strtod(literal.c_str(), &ptr);
	if (ptr == literal.c_str() + literal.length())
		return true;
	else
		return false;
}
