/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:10:04 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/19 11:45:00 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ************************************************************************** */

									/* TESTS */

std::string	charTests[]		= {"A", "z", "'4'", "+", "-"};
std::string	intTests[]		= {"42", "0", "2147483647", "-2147483648"};
std::string	floatTests[]	= {"0.0f", "-4.2f", "4.2f", "-inff", "+inff", "nanf"};
std::string	doubleTests[]	= {"0.0", "-4.2", "4.2", "-inf", "+inf", "nan"};
std::string	badTests[]		= {"'42'", "   ", "42euh"};

/* ************************************************************************** */

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int	i;

		i = 0;
		while (++i < argc)
			if (!ScalarConverter::convert(argv[i]))
				return 1;
	}
	else
	{
		int	size;
		std::cout << "/* CHAR ********************** */" << std::endl << std::endl;
		
		size = sizeof(charTests) / sizeof(charTests[0]);
		for (int i = 0; i < size; i++)
		{
			ScalarConverter::convert(charTests[i]);
			std::cout << std::endl;
		}
		std::cout << "/* INT *********************** */" << std::endl << std::endl;

		size = sizeof(intTests) / sizeof(intTests[0]);
		for (int i = 0; i < size; i++)
		{
			ScalarConverter::convert(intTests[i]);
			std::cout << std::endl;
		}
		std::cout << "/* FLOAT ******************** */" << std::endl << std::endl;

		size = sizeof(floatTests) / sizeof(floatTests[0]);
		for (int i = 0; i < size; i++)
		{
			ScalarConverter::convert(floatTests[i]);
			std::cout << std::endl;
		}
		std::cout << "/* DOUBLE ******************** */" << std::endl << std::endl;

		size = sizeof(doubleTests) / sizeof(doubleTests[0]);
		for (int i = 0; i < size; i++)
		{
			ScalarConverter::convert(doubleTests[i]);
			std::cout << std::endl;
		}
		std::cout << "/* OTHER ********************* */" << std::endl << std::endl;

		size = sizeof(badTests) / sizeof(badTests[0]);
		for (int i = 0; i < size; i++)
		{
			ScalarConverter::convert(badTests[i]);
			std::cout << std::endl;
		}
		std::cout << "/* *************************** */" << std::endl;
	}
	return 0;
}
