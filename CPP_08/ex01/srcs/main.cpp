/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:57:47 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/13 17:06:04 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	noArg(void);
void	rangeOfIterators(void);

int	main(int argc, char **argv)
{
	Span	sp(argc - 1);

	if (argc == 1)
	{
		noArg();
		return (0);
	}
	try
	{
		for (int i = 1; i < argc; i++)
			sp.addNumber(atoi(argv[i]));
		sp.print();
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
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
	Span	sp(14);

	sp.addNumber(4);
	sp.addNumber(8);
	sp.addNumber(15);
	sp.addNumber(16);

	sp.print();
	std::cout << "---" << std::endl;

	sp.addNumber(4, 23);
	sp.print();

	std::cout << "---" << std::endl;

	std::vector<int>	vect;

	vect.insert(vect.end(), 6, 42);
	sp.addNumber(vect.begin(), vect.end());
	sp.print();

	std::cout << "---" << std::endl;
	
	try
	{
		sp.addNumber(-42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
