/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:57:47 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/13 14:20:01 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	noArg(void);

int	main(int argc, char **argv)
{
	Span	span(argc - 1);
	(void)	argv;
	if (argc == 1)
	{
		noArg();
		return (0);
	}
	try
	{
		for (int i = 1; i < argc; i++)
			span.addNumber(atoi(argv[i]));
		span.print();
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "[!] " << e.what() << std::endl;
		return (1);
	}
	return (0);
}

void	noArg(void)
{
	Span	span(6);

	std::cout << "Let's try to find the shortest and longest span in our empty object" << std::endl;
	try
	{
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "[!] " << e.what() << '\n';
	}
	span.print();
	std::cout << std::endl;

	std::cout << "Let's add 6 numbers in our object of size [6]" << std::endl;
	try
	{
		span.addNumber(1500);
		span.addNumber(4);
		span.addNumber(230000);
		span.addNumber(4200000);
		span.addNumber(80);
		span.addNumber(16000);
	}
	catch (std::exception &e)
	{
		std::cerr << "[!] " << e.what() << std::endl;
	}
	span.print();
	std::cout << std::endl;

	std::cout << "Let's add a seventh number in our object of size [6]" << std::endl;
	try
	{
		span.addNumber(-42);
	}
	catch(const std::exception& e)
	{
		std::cerr << "[!] " << e.what() << std::endl;
	}
	span.print();
	std::cout << std::endl;
	
	std::cout << "Let's try to find the shortest and longest span in our filled object" << std::endl;
	try
	{
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "[!] " << e.what() << '\n';
	}
	span.print();
}
