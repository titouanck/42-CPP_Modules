/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:33:36 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 01:39:39 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Constructor: A new Dog has just arrived." << std::endl;
}

Dog::Dog(const Dog &src)
{
	std::cout << "Constructor: A new Dog has just arrived, following in the footsteps of another." << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Destructor: A Dog leaves us." << std::endl;
}

Dog	&Dog::operator=(const Dog &src)
{
	this->_type = src._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << _type << ": * Woof! Woof! *" << std::endl;
}
