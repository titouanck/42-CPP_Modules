/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:35:07 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/20 12:27:43 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

/* ************************************************************************** */

Base	*generate(void)
{
	static bool	srandInit;
	Base		*obj;
	
	if (srandInit == false)
	{
		struct timeval tp;
		gettimeofday(&tp, NULL);
		srand(tp.tv_usec);
		srandInit = true;
	}

	obj = NULL;
	switch (rand() % 3)
	{
		case 0:
			std::cout << "Generated an object of class: " << 'A' << std::endl;
			obj = new A;
			break ;
		case 1:
			std::cout << "Generated an object of class: " << 'B' << std::endl;
			obj = new B;
			break ;
		case 2:
			std::cout << "Generated an object of class: " << 'C' << std::endl;
			obj = new C;
			break ;
	}
	return obj;
}

/* ************************************************************************** */

void	identify(Base *p)
{
	std::cout << "And the class derived from the object contained in this address is... ";
	if (dynamic_cast<A*>(p))
		std::cout << 'A' << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << 'B' << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << 'C' << std::endl;
	else
		std::cout << "undetermined" << std::endl;
}

/* ************************************************************************** */

void	identify(Base &p)
{
	std::cout << "And the class derived from this object is... ";

	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << 'A' << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << 'B' << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << 'C' << std::endl;
		return ;
	}
	catch (...) {}

	std::cout << "undetermined" << std::endl;
}

/* ************************************************************************** */
