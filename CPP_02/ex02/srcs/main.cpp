/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:42:17 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/05/26 19:11:20 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed _4(4), _8(8), _15(15), _16(16), _23(23), _42(42);
Fixed theNumber(42);
Fixed notTheNumber(-42);
Fixed negativeNumber(-1);

void	testComparisonOperators(void)
{
	std::cout << std::endl << std::boolalpha << "The 6 comparison operators: >, <, >=, <=, == and !=" << std::endl;
	
	std::cout << "  " << std::boolalpha << "Should be true:" << std::endl;
	{
		std::cout << "   " << std::boolalpha << (_4 < _8) << std::endl;
		std::cout << "   " << std::boolalpha << (_23 < _42) << std::endl;

		std::cout << "   " << std::boolalpha << (_8 <= _15) << std::endl;
		std::cout << "   " << std::boolalpha << (_16 <= _23) << std::endl;

		std::cout << "   " << std::boolalpha << (_15 >= _8) << std::endl;
		std::cout << "   " << std::boolalpha << (_23 >= _16) << std::endl;

		std::cout << "   " << std::boolalpha << (_42 > _23) << std::endl;
		std::cout << "   " << std::boolalpha << (_8 > _4) << std::endl;

		std::cout << "   " << std::boolalpha << (theNumber <= _42) << std::endl;
		std::cout << "   " << std::boolalpha << (theNumber >= _42) << std::endl;
		std::cout << "   " << std::boolalpha << (theNumber == _42) << std::endl;
		std::cout << "   " << std::boolalpha << (theNumber != notTheNumber) << std::endl;

		std::cout << "   " << std::boolalpha << (negativeNumber < _42) << std::endl;
		std::cout << "   " << std::boolalpha << (negativeNumber <= _42) << std::endl;
		std::cout << "   " << std::boolalpha << (_42 > negativeNumber) << std::endl;
		std::cout << "   " << std::boolalpha << (_42 >= negativeNumber) << std::endl;
		std::cout << "   " << std::boolalpha << (negativeNumber != _42) << std::endl;
		std::cout << "   " << std::boolalpha << (negativeNumber == negativeNumber) << std::endl;
	}

	std::cout << "  " << std::boolalpha << "Should be false:" << std::endl;
	{
		std::cout << "   " << std::boolalpha << (_4 > _8) << std::endl;
		std::cout << "   " << std::boolalpha << (_23 > _42) << std::endl;

		std::cout << "   " << std::boolalpha << (_8 >= _15) << std::endl;
		std::cout << "   " << std::boolalpha << (_16 >= _23) << std::endl;

		std::cout << "   " << std::boolalpha << (_15 <= _8) << std::endl;
		std::cout << "   " << std::boolalpha << (_23 <= _16) << std::endl;

		std::cout << "   " << std::boolalpha << (_42 < _23) << std::endl;
		std::cout << "   " << std::boolalpha << (_8 < _4) << std::endl;

		std::cout << "   " << std::boolalpha << (theNumber <= notTheNumber) << std::endl;
		std::cout << "   " << std::boolalpha << (notTheNumber >= _42) << std::endl;
		std::cout << "   " << std::boolalpha << (notTheNumber == _42) << std::endl;
		std::cout << "   " << std::boolalpha << (notTheNumber == theNumber) << std::endl;

		std::cout << "   " << std::boolalpha << (negativeNumber > _42) << std::endl;
		std::cout << "   " << std::boolalpha << (negativeNumber >= _42) << std::endl;
		std::cout << "   " << std::boolalpha << (_42 < negativeNumber) << std::endl;
		std::cout << "   " << std::boolalpha << (_42 <= negativeNumber) << std::endl;
		std::cout << "   " << std::boolalpha << (negativeNumber == _42) << std::endl;
		std::cout << "   " << std::boolalpha << (negativeNumber != negativeNumber) << std::endl;
	}
}

void	testArithmeticOperators(void)
{
	std::cout << std::endl << std::boolalpha << "The 4 arithmetic operators: +, -, *, and /" << std::endl;

	std::cout << "   " << "4 + 8 + 15 + 16 + 23 + 42 = " \
	<< _4 + _8 + _15 + _16 + _23 + _42 \
	<< " ? " << 4 + 8 + 15 + 16 + 23 + 42 << std::endl;

	std::cout << "   " << "-42 + 42 = " \
	<< notTheNumber + theNumber \
	<< " ? " << -42 + 42 << std::endl;

	std::cout << "   " << "42 + (-42) = " \
	<< theNumber + notTheNumber \
	<< " ? " << 42 + (-42) << std::endl;

	std::cout << "   " << "(-42) + (-42) = " \
	<< notTheNumber + notTheNumber \
	<< " ? " << (-42) + (-42) << std::endl;
}

int main(void)
{
	testComparisonOperators();
	testArithmeticOperators();
	return 0;
}