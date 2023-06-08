/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:56:16 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/08 13:12:27 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Templates.hpp"

int main( void )
{
	int a = 2;
	int b = 3;
	
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "---" << std::endl;

	a = 42;
	b = 8;

	std::cout << "a vaut: " << a << std::endl;
	std::cout << "b vaut: " << b << std::endl;
	std::cout << "Swaping . . ." << std::endl;
	swap(a, b);
	std::cout << "a vaut: " << a << std::endl;
	std::cout << "b vaut: " << b << std::endl;
	std::cout << "Entre " << a << " et " << b << " la plus petite valeur est " << min(a, b) << std::endl;
	std::cout << "Entre " << a << " et " << b << " la plus grande valeur est " << max(a, b) << std::endl;
	return (0);
}
