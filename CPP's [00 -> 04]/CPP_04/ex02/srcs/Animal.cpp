/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:32:56 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 18:58:22 by titouan_ck       ###   ########.fr       */
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

