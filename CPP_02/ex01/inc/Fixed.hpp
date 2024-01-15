/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:41:33 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/05/26 16:34:50 by tchevrie         ###   ########.fr       */
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
		Fixed();
		Fixed( const Fixed &src );
		Fixed( const int srcNbr );
		Fixed( const float srcNbr );
		~Fixed();
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat ( void ) const;
		int		toInt ( void ) const;

		Fixed	& operator=( const Fixed &src );
};

std::ostream&	operator<<( std::ostream &os, const Fixed &srcFixed );

#endif
