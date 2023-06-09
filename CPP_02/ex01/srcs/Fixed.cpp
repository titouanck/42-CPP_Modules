/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:42:40 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/05/30 15:42:23 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointNumber(0)
{
	std::cerr << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &src)
{
	std::cerr << "Copy constructor called\n";
	*this = src;
}

Fixed::Fixed(const int srcNbr) : _fixedPointNumber(srcNbr * (1 << this->_fractionalBits))
{
	std::cerr << "Int constructor called with " << srcNbr << std::endl;
}

Fixed::Fixed(const float srcNbr) : _fixedPointNumber(roundf(srcNbr * (1 << this->_fractionalBits)))
{
	std::cerr << "Float constructor called with " << srcNbr << std::endl;
}

Fixed::~Fixed()
{
	std::cerr << "Destructor called\n";
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

float	Fixed::toFloat (void) const
{
	return ((float)this->_fixedPointNumber / (1 <<_fractionalBits));
}

int		Fixed::toInt (void) const
{
	return (roundf((float)this->_fixedPointNumber / (1 <<_fractionalBits)));
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cerr << "Copy assignement operator called\n";
	this->_fixedPointNumber = src.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream &os, const Fixed &srcFixed)
{
	os << (srcFixed.toFloat());
	return (os);
}
