/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:42:40 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/05/30 15:23:59 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointNumber(0)
{
	// std::cerr << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &src)
{
	// std::cerr << "Copy constructor called\n";
	*this = src;
}

Fixed::Fixed(const int srcNbr) : _fixedPointNumber((float)srcNbr * (1 << this->_fractionalBits))
{
	// std::cerr << "Int constructor called with " << srcNbr << std::endl;
}

Fixed::Fixed(const float srcNbr) : _fixedPointNumber(roundf(srcNbr * (1 << this->_fractionalBits)))
{
	// std::cerr << "Float constructor called with " << srcNbr << std::endl;
}

Fixed::~Fixed()
{
	// std::cerr << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	// std::cerr << "getRawBits member function called\n";
	return (this->_fixedPointNumber);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cerr << "setRawBits member function called\n";
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
	// std::cerr << "Copy assignement operator called\n";
	this->_fixedPointNumber = src.getRawBits();
	return (*this);
}

bool	Fixed::operator<(const Fixed &other)
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other)
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator>(const Fixed &other)
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other)
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other)
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other)
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other)
{
	Fixed	operation(this->toFloat() + other.toFloat());
	return (operation);
}

Fixed	Fixed::operator-(const Fixed &other)
{
	Fixed	operation(this->toFloat() - other.toFloat());
	return (operation);
}

Fixed	Fixed::operator/(const Fixed &other)
{
	Fixed	operation(this->toFloat() / other.toFloat());
	return (operation);
}

Fixed	Fixed::operator*(const Fixed &other)
{
	Fixed	operation(this->toFloat() * other.toFloat());
	return (operation);
}

Fixed	&Fixed::operator++()
{
	this->setRawBits((this->getRawBits()) + 1);
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	operation(*this);

	this->setRawBits((this->getRawBits()) + 1);
	return (operation);
}

Fixed	&Fixed::operator--()
{
	this->setRawBits((this->getRawBits()) - 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	operation(*this);

	this->setRawBits((this->getRawBits()) - 1);
	return (operation);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}

std::ostream&	operator<<(std::ostream &os, const Fixed &srcFixed)
{
	os << (srcFixed.toFloat());
	return (os);
}

