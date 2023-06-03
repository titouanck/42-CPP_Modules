/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:36:19 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/03 18:00:41 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{}

AMateria::AMateria(const AMateria &obj) : _type(obj.getType())
{
	*this = obj;	
}

AMateria::~AMateria(void)
{}

AMateria	&AMateria::operator=(const AMateria &obj)
{
	(void)	obj;
	return (*this);
}

const std::string  &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	static bool	preventLoop;

	if (preventLoop)
		return ;
	preventLoop = true;
	use(target);
	preventLoop = false;
}
