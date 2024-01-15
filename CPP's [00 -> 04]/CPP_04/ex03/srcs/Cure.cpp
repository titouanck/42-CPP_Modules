/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:46:10 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/03 16:37:30 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{}

Cure::Cure(const Cure &obj) : AMateria("cure")
{
	*this = obj;
}

Cure::~Cure(void)
{}

Cure	&Cure::operator=(const Cure &obj)
{
	(void)	obj;
	return (*this);
}

AMateria	*Cure::clone() const
{
	AMateria	*newOne;

	newOne = new Cure(*this);
	return (newOne);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
