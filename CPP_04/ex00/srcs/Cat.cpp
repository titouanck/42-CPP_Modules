/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:33:24 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 01:39:31 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Constructor: A new Cat has just arrived." << std::endl;
}

Cat::Cat(const Cat &src)
{
	std::cout << "Constructor: A new Cat has just arrived, following in the footsteps of another." << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Destructor: A Cat leaves us." << std::endl;
}

Cat	&Cat::operator=(const Cat &src)
{
	this->_type = src._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << _type << ": * Meow! Meow! *" << std::endl;
}
