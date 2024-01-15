/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:46:10 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/03 16:37:41 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{}

Ice::Ice(const Ice &obj) : AMateria("ice")
{
	*this = obj;
}

Ice::~Ice(void)
{}

Ice	&Ice::operator=(const Ice &obj)
{
	(void)	obj;
	return (*this);
}

AMateria	*Ice::clone() const
{
	AMateria	*newOne;

	newOne = new Ice(*this);
	return (newOne);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
