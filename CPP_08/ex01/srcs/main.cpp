/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:47:16 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/03 11:45:31 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "comments.hpp"

/* ************************************************************************** */

void	mainFromTheSubject()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

/* ************************************************************************** */

int main()
{
	comment_("Tests from the subject's main");
	mainFromTheSubject();

	/* ********************************************************************** */

	_comment_("This class will have a member function called addNumber() to add a single number to the Span");

	Span	s(2);

	std::cout << "s.addNumber(4)" << std::endl;
	std::cout << "s.addNumber(2)" << std::endl;
	std::cout << std::endl;
	std::cout << "s.print() = ";

	s.addNumber(4);
	s.addNumber(2);
	s.print();

	/* ********************************************************************** */

	_comment_("Any attempt to add a new element if there are already N elements stored should throw an exception");

	try
	{
		std::cout << "s.addNumber(42)" << std::endl;
		s.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	/* ********************************************************************** */
	
	_comment_("Implement two member functions: shortestSpan() and longestSpan()");

	Span	sp(6);
	
	sp.addNumber(4);
	sp.addNumber(8);
	sp.addNumber(15);
	sp.addNumber(16);
	sp.addNumber(23);
	sp.addNumber(42);

	std::cout << "sp.print()        = "; sp.print();
	std::cout << "sp.shortestSpan() = " << sp.shortestSpan() << std::endl;
	std::cout << "sp.longestSpan()  = " << sp.longestSpan() << std::endl;

	/* ********************************************************************** */

	_comment_("Implement a member function to add many numbers to your Span in one call.");

	std::vector<int>	container;

	container.insert(container.end(), 42000, 42);
	
	Span newSp(42000);
	newSp.addNumber(container.begin(), container.end());
	std::cout << "container.insert(container.end(), 42000, 42)" << std::endl;
	std::cout << "newSp.addNumber(container.begin(), container.end())" << std::endl;
	std::cout << "newSp.getSize() = " << newSp.getSize() << std::endl;
}

/* ************************************************************************** */
