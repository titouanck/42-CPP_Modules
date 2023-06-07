/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:00:56 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/07 18:14:41 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utils.hpp"

ScalarConverter::ScalarConverter(const char *input) : _input(input)
{}
ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter::~ScalarConverter(void)
{}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)	obj;
	return (*this);
}

void	ScalarConverter::convertIt(void)
{
	convert(this->_input);
}

void	ScalarConverter::convert(const char *input)
{
	t_convert	tnbr;

	int		len;
	
	len = ft_strlen(input);
	if (len < 1)
		setDisplayability(noType, tnbr);
	else if (isChar(input, len, tnbr.charNbr))
		setDisplayability(charType, tnbr);
	else if (isInt(input, len, tnbr.intNbr))
		setDisplayability(intType, tnbr);
	else if (isDouble(input, len, tnbr.doubleNbr))
		setDisplayability(doubleType, tnbr);
	else if (isFloat(input, len, tnbr.floatNbr, tnbr.doubleNbr))
		setDisplayability(floatType, tnbr);
	else
		setDisplayability(noType, tnbr);
	print(tnbr);
}

bool	ScalarConverter::isChar(std::string str, int len, char &nbr)
{
	nbr = *str.begin();
	if (len != 1 || ft_isdigit(nbr))
		return (false);
	return (true);
}

bool	ScalarConverter::isInt(std::string str, int len, int &nbr)
{
	int		oldnbr		= 0;
	int		i			= 0;
	bool	negative	= false;

	nbr = 0;
	if ((*str.begin() == '+' || *str.begin() == '-') && len > 1)
		i += 1;
	if (*str.begin() == '-')
		negative = true;
	while (i < len)
	{
		if (!ft_isdigit(str.at(i)))
			return (false);
		oldnbr = nbr;
		if (negative)
			nbr = (nbr * 10) - (str.at(i) - '0');
		else
			nbr = (nbr * 10) + (str.at(i) - '0');
		if (negative == false && nbr < oldnbr)
			return (false);
		else if (negative == true && nbr > oldnbr)
			return (false);
		i++;
	}
	return (true);
}

bool	ScalarConverter::isDouble(const char *input, int len, double &nbr)
{
	char		*ptr;

	nbr = strtod(input, &ptr);
	if (ptr != input + len)
		return (false);
	return (true);
}

bool	ScalarConverter::isFloat(const char *input, int len, float &nbr, double &dnbr)
{
	char		*ptr;

	nbr = strtof(input, &ptr);
	dnbr = strtod(input, &ptr);
	if (len >= 2 && (input + len - 1) == ptr && *ptr == 'f')
		return (true);
	else
		return (false);
}

void	ScalarConverter::setDisplayability(inputType type, t_convert &tnbr)
{
	switch (type)
	{
		case noType:
			tnbr.charDis = Impossible;
			tnbr.intDis = Impossible;
			tnbr.doubleDis = Impossible;
			tnbr.floatDis = Impossible;
			break ;
		
		case charType:
			tnbr.charDis = Displayable;
			tnbr.intDis = Displayable;
			tnbr.doubleDis = Displayable;
			tnbr.floatDis = Displayable;
			break ;
		
		case intType:
			if (tnbr.intNbr < CHAR_MIN || tnbr.intNbr > CHAR_MAX)
				tnbr.charDis = Impossible;
			else if (!ft_isprint(tnbr.intNbr))
				tnbr.charDis = Non_displayable;
			else
				tnbr.charDis = Displayable;
			tnbr.intDis = Displayable;
			tnbr.doubleDis = Displayable;
			tnbr.floatDis = Displayable;
			break ;
		
		case doubleType:
			if ((int) tnbr.doubleNbr < CHAR_MIN || (int) tnbr.doubleNbr > CHAR_MAX)
				tnbr.charDis = Impossible;
			else if (!ft_isprint((int) tnbr.doubleNbr))
				tnbr.charDis = Non_displayable;
			else
				tnbr.charDis = Displayable;
			if (tnbr.doubleNbr != tnbr.doubleNbr  || tnbr.doubleNbr < (double) INT_MIN || tnbr.doubleNbr > (double) INT_MAX)
				tnbr.intDis = Impossible;
			else
				tnbr.intDis = Displayable;
			tnbr.doubleDis = Displayable;
			if ((tnbr.doubleNbr <= DBL_MAX && tnbr.doubleNbr >= DBL_MIN) && (tnbr.doubleNbr > FLT_MAX || tnbr.doubleNbr < FLT_MIN))
				tnbr.floatDis = Impossible;
			else
				tnbr.floatDis = Displayable;
			break ;
		
		case floatType:
			if ((int) tnbr.floatNbr < CHAR_MIN || (int) tnbr.floatNbr > CHAR_MAX)
				tnbr.charDis = Impossible;
			else if (!ft_isprint((int) tnbr.floatNbr))
				tnbr.charDis = Non_displayable;
			else
				tnbr.charDis = Displayable;
			if (tnbr.doubleNbr != tnbr.doubleNbr  || tnbr.doubleNbr < (double) INT_MIN || tnbr.doubleNbr > (double) INT_MAX)
				tnbr.intDis = Impossible;
			else
				tnbr.intDis = Displayable;
			tnbr.doubleDis = Displayable;
			tnbr.floatDis = Displayable;
			break ;
	}
	castNbr(type, tnbr);
}

void	ScalarConverter::castNbr(inputType type, t_convert &tnbr)
{
	switch (type)
	{
		case noType:
			break ;

		case charType:
			tnbr.intNbr		= (int) tnbr.charNbr;
			tnbr.doubleNbr	= (double) tnbr.charNbr;
			tnbr.floatNbr	= (float) tnbr.charNbr;
			break ;

		case intType:
			tnbr.charNbr	= (char) tnbr.intNbr;
			tnbr.doubleNbr	= (double) tnbr.intNbr;
			tnbr.floatNbr	= (float) tnbr.intNbr;
			break ;

		case doubleType:
			tnbr.charNbr	= (char) tnbr.doubleNbr;
			tnbr.intNbr		= (int) tnbr.doubleNbr;
			tnbr.floatNbr	= (float) tnbr.doubleNbr;
			break ;

		case floatType:
			tnbr.charNbr	= (char) tnbr.floatNbr;
			tnbr.intNbr		= (int) tnbr.doubleNbr;
			tnbr.doubleNbr	= (double) tnbr.floatNbr;
			break ;
	}
}

void	ScalarConverter::print(t_convert &tnbr)
{
	std::cout << "char: ";
	if (tnbr.charDis == Displayable)
		std::cout << '\'' << tnbr.charNbr << '\'' << std::endl;
	else if (tnbr.charDis == Non_displayable)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (tnbr.intDis == Displayable)
		std::cout << tnbr.intNbr << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: ";
	if (tnbr.floatDis == Displayable)
		std::cout << tnbr.floatNbr << 'f' << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "double: ";
	if (tnbr.doubleDis == Displayable)
		std::cout << tnbr.doubleNbr << std::endl;
	else
		std::cout << "impossible" << std::endl;
}
