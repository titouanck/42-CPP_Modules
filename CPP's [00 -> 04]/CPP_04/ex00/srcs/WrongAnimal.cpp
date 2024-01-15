/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:32:56 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 01:35:40 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("") 
{
	std::cout << "Constructor: An Unknown WrongAnimal has just appeared." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) 
{
	std::cout << "Constructor: A WrongAnimal of type \"" << _type << "\" has just appeared." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	if (_type.compare("") == 0)
		std::cout << "Constructor: An Unknown WrongAnimal has just appeared, following the path of another." << std::endl;
	else
		std::cout << "Constructor: A WrongAnimal of type \"" << _type << "\" has just appeared, following the path of another." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	if (_type.compare("") == 0)
		std::cout << "Destructor: A WrongAnimal has just left us." << std::endl;
	else
		std::cout << "Destructor: A WrongAnimal of type \"" << _type << "\" has just left us." << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	this->_type = src._type;
	return (*this);	
}

std::string	WrongAnimal::getType(void) const
{
	return(this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	if (this->_type.compare("") == 0)
		std::cout << "Unknown" << ": *  Screeeeeeeeeeech! *" << std::endl;
	else
		std::cout << _type << ": *  Screeeeeeeeeeech! *" << std::endl;
}
