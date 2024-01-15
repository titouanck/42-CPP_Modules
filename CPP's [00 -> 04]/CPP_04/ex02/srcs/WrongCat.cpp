/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:33:24 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 01:35:34 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Constructor: A new WrongCat has just arrived." << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src.getType())
{
	std::cout << "Constructor: A new WrongCat has just arrived, following in the footsteps of another." << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor: A WrongCat leaves us." << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	this->_type = src._type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << _type << ": * Grrrrrrooooooaaaarrrr! *" << std::endl;
}
