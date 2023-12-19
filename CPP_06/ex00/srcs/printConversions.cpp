/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printConversions.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:15:08 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/19 10:49:42 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ************************************************************************** */

extern long	sign;

/* ************************************************************************** */

void	printConversions(char &c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	printConversions(int &i)
{
	if (32 <= i && i <= 126)
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	else if (-128 <= i && i <= 127)
		std::cout << "char: Not displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	printConversions(float &f)
{
	std::cout << std::fixed;

	if (f == f && 32.0 <= f && f <= 126.0)
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else if (f == f && -128.0 <= f && f <= 127.0)
		std::cout << "char: Not displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	if (f == f && -2147483648.0 <= f && f <= 2147483647.0 \
	&& (static_cast<int>(f) * sign >= 0) && f < FLT_MAX && f > FLT_MY_MIN)
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	
	std::cout << "float: " << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void	printConversions(double &d)
{
	std::cout << std::fixed;

	if (d == d && 32.0 <= d && d <= 126.0)
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else if (d == d && -128.0 <= d && d <= 127.0)
		std::cout << "char: Not displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	
	if (d == d && -2147483648.0 <= d && d <= 2147483647.0 \
	&& (static_cast<int>(d) * sign >= 0) && d < DBL_MAX && d > DBL_MY_MIN)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	
	if ((d > FLT_MY_MIN && FLT_MAX > d) || d != d)
		std::cout << "float: " << std::setprecision(1) << static_cast<double>(d) << "f" << std::endl;
	else if (d < FLT_MY_MIN)
		std::cout << "float: -inff" << std::endl;
	else if (d > FLT_MAX)
		std::cout << "float: inff" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	
	std::cout << "double: " << std::setprecision(1) << d << std::endl;
}
