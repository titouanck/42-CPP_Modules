/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:41:33 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/05/30 17:41:27 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
	#define FIXED_HPP

	#include <string>
	#include <climits>
	#include <cmath>
	#include <iostream>

class Fixed
{
	private:
		int					_fixedPointNumber;
		const static int	_fractionalBits;
	
	public:
		static Fixed	&min( Fixed &a, Fixed &b );
		const static 	Fixed	&min( const Fixed &a, const Fixed &b );
		static Fixed	&max( Fixed &a, Fixed &b );
		const static	 Fixed	&max( const Fixed &a, const Fixed &b );

		Fixed();
		Fixed( const Fixed &src );
		Fixed( const int srcNbr );
		Fixed( const float srcNbr );
		~Fixed();
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat ( void ) const;
		int		toInt ( void ) const;

		Fixed	&operator=( const Fixed &src );
		bool	operator<(const Fixed &other);
		bool	operator<=(const Fixed &other);
		bool	operator>(const Fixed &other);
		bool	operator>=(const Fixed &other);
		bool	operator==(const Fixed &other);
		bool	operator!=(const Fixed &other);
		Fixed	operator+(const Fixed &other);
		Fixed	operator-(const Fixed &other);
		Fixed	operator/(const Fixed &other);
		Fixed	operator*(const Fixed &other);
		Fixed	&operator++();
		Fixed	operator++( int );
		Fixed	&operator--();
		Fixed	operator--( int );
};

std::ostream&	operator<<( std::ostream &os, const Fixed &srcFixed );

#endif
