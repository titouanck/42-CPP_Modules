/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:32:56 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 01:39:01 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("") 
{
	std::cout << "Constructor: An unknown Animal has just appeared." << std::endl;
}

Animal::Animal(std::string type) : _type(type) 
{
	std::cout << "Constructor: An Animal of type \"" << _type << "\" has just appeared." << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	if (_type.compare("") == 0)
		std::cout << "Constructor: An unknown Animal has just appeared, following the path of another." << std::endl;
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
		std::cout << "unknown" << ": * An unfamiliar and disturbing Animal sound *" << std::endl;
	else
		std::cout << _type << ": * An unfamiliar and disturbing Animal sound *" << std::endl;
}
