/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:33:24 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 18:51:43 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Constructor: A new Cat has just arrived." << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src.getType())
{
	this->_brain = new Brain();
	std::cout << "Constructor: A new Cat has just arrived, following in the footsteps of another." << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Destructor: A Cat leaves us." << std::endl;
	delete (this->_brain);
}

Cat	&Cat::operator=(const Cat &src)
{
	if (!this->_brain)
		this->_brain = new Brain();
	*(this->_brain) = *(src._brain);

	this->_type = src._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << _type << ": * Meow! Meow! *" << std::endl;
	std::cout << _type << "'s idea: ";
	std::cout << this->_brain->getIdea(0) << std::endl;
}

void	Cat::newIdea(std::string idea)
{
	static unsigned int	idx;

	if (idx >= 100)
		idx = 0;
	this->_brain->defIdea(idea, idx);
}
