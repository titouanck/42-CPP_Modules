/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:32:56 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 14:29:31 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("") 
{
	std::cout << "Constructor: An Unknown Animal has just appeared." << std::endl;
}

Animal::Animal(std::string type) : _type(type) 
{
	std::cout << "Constructor: An Animal of type \"" << _type << "\" has just appeared." << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	if (_type.compare("") == 0)
		std::cout << "Constructor: An Unknown Animal has just appeared, following the path of another." << std::endl;
	else
		std::cout << "Constructor: An Animal of type \"" << _type << "\" has just appeared, following the path of another." << std::endl;
}

Animal::~Animal()
{
	if (_type.compare("") == 0)
		std::cout << "Destructor: An Animal has just left us." << std::endl;
	else
		std::cout << "Destructor: An Animal of type \"" << _type << "\" has just left us." << std::endl;
}

Animal	&Animal::operator=(const Animal &src)
{
	this->_type = src._type;
	return (*this);	
}

std::string	Animal::getType(void) const
{
	return(this->_type);
}

void	Animal::makeSound(void) const
{
	if (this->_type.compare("") == 0)
		std::cout << "Unknown" << ": * An unfamiliar and disturbing Animal sound *" << std::endl;
	else
		std::cout << _type << ": * An unfamiliar and disturbing Animal sound *" << std::endl;
}

void	Animal::newIdea(std::string idea)
{
	(void) idea;

	if (_type.compare("Cat") == 0 || _type.compare("Dog") == 0 || _type.compare("Demogorgon") == 0 )
		std::cout << _type << ": This is not the best place to share ideas." << std::endl;
	else
		std::cout << "Any animal: not a Cat, not a Dog, not even a Demogorgon. Who am I to have ideas?" << std::endl;
}
