/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:16:36 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/08 12:43:17 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include <iostream>
#include <string>

Base	*generate(void)
{
	time_t		rawTime;
	Base		*obj;
	
	rawTime = time(&rawTime);
	if (rawTime % 3 == 0)
		obj = new A;
	else if (rawTime % 2 == 0)
		obj = new B;
	else
		obj = new C;
	return (obj);
}

void	identify(Base* p)
{
	A		*addrA;
	B		*addrB;
	C		*addrC;

	addrA = dynamic_cast<A *>(p);
	addrB = dynamic_cast<B *>(p);
	addrC = dynamic_cast<C *>(p);
	
	if (addrA)
		std::cout << "By pointer, we learn that the object's true type is A" << std::endl;
	else if (addrB)
		std::cout << "By pointer, we learn that the object's true type is B" << std::endl;
	else if (addrC)
		std::cout << "By pointer, we learn that the object's true type is C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A		&varA = dynamic_cast<A &>(p);
		(void)	varA;
		
		std::cout << "By reference, we learn that the object's true type is A" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	
	try
	{
		B		&varB = dynamic_cast<B &>(p);
		(void)	varB;
		
		std::cout << "By reference, we learn that the object's true type is B" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

	try
	{
		C		&varC = dynamic_cast<C &>(p);
		(void)	varC;

		std::cout << "By reference, we learn that the object's true type is C" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

}

int	main(void)
{
	Base	*addr;
	
	addr = generate();
	if (!addr)
		return (1);	
	identify(addr);
	std::cout << "---" << std::endl;
	identify(*addr);
	delete addr;
	return (0);
}
