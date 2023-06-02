/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:33:36 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 18:35:16 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Constructor: A new Dog has just arrived." << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src.getType())
{
	std::cout << "Constructor: A new Dog has just arrived, following in the footsteps of another." << std::endl;
	this->_brain = new Brain();
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Destructor: A Dog leaves us." << std::endl;
	delete (this->_brain);
}

Dog	&Dog::operator=(const Dog &src)
{
	if (!this->_brain)
		this->_brain = new Brain();
	*(this->_brain) = *(src._brain);

	this->_type = src._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << _type << ": * Woof! Woof! *" << std::endl;
	std::cout << _type << "'s idea: ";
	std::cout << this->_brain->getIdea(0) << std::endl;
}

void	Dog::newIdea(std::string idea)
{
	static unsigned int	idx;

	if (idx >= 100)
		idx = 0;
	this->_brain->defIdea(idea, idx);
}
