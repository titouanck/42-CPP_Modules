/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:47:16 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/29 15:56:09 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */

int	main(void)
{
	Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
sp.debugPrint();

	std::vector<int>	tab;

	tab.insert(tab.end(), 4);
	tab.insert(tab.end(), 2);

	std::vector<int>	tab2;
	Span	sp2(10);

	tab2.insert(tab2.end(), tab.begin(), tab.end());
	for(std::vector<int>::iterator it = tab2.begin(); it != tab2.end(); it++)
	{
		
	}
}

/* ************************************************************************** */
