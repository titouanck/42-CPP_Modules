/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:42:40 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/05/26 02:20:54 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	std::cerr << "Default constructor called\n";
	this->_fixedPointNumber = 0;
}

Fixed::Fixed(const Fixed &src)
{
	std::cerr << "Copy constructor called\n";
	this->_fixedPointNumber = src.getRawBits();
}

Fixed::~Fixed()
{
	std::cerr << "Destructor called\n";
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cerr << "Copy assignement operator called\n";
	this->_fixedPointNumber = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cerr << "getRawBits member function called\n";
	return (this->_fixedPointNumber);
}

void	Fixed::setRawBits(int const raw)
{
	std::cerr << "setRawBits member function called\n";
	this->_fixedPointNumber = raw;
}
