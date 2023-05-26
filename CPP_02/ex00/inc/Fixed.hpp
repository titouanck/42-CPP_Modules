/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:41:33 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/05/26 02:19:57 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
	#define FIXED_HPP

	#include <string>
	#include <climits>
	#include <iostream>

class Fixed
{
	private:
		int					_fixedPointNumber;
		const static int	_fractionalBits;
	
	public:
		Fixed();
		Fixed( const Fixed &src );
		~Fixed();
		Fixed	&operator=( const Fixed &src );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
