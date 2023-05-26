/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:42:17 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/05/26 18:17:53 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void	testComparisonOperators(void)
{
	Fixed _4(4), _8(8), _15(15), _16(16), _23(23), _42(42);
	
	Fixed theNumber(42);
	Fixed notTheNumber(-42);
	Fixed negativeNumber(-1);

	std::cout << std::boolalpha << "Should be true:" << std::endl;
	{
		std::cout << std::boolalpha << (_4 < _8) << std::endl;
		std::cout << std::boolalpha << (_23 < _42) << std::endl;

		std::cout << std::boolalpha << (_8 <= _15) << std::endl;
		std::cout << std::boolalpha << (_16 <= _23) << std::endl;

		std::cout << std::boolalpha << (_15 >= _8) << std::endl;
		std::cout << std::boolalpha << (_23 >= _16) << std::endl;

		std::cout << std::boolalpha << (_42 > _23) << std::endl;
		std::cout << std::boolalpha << (_8 > _4) << std::endl;

		std::cout << std::boolalpha << (theNumber <= _42) << std::endl;
		std::cout << std::boolalpha << (theNumber >= _42) << std::endl;
		std::cout << std::boolalpha << (theNumber == _42) << std::endl;
		std::cout << std::boolalpha << (theNumber != notTheNumber) << std::endl;

		std::cout << std::boolalpha << (negativeNumber < _42) << std::endl;
		std::cout << std::boolalpha << (negativeNumber <= _42) << std::endl;
		std::cout << std::boolalpha << (_42 > negativeNumber) << std::endl;
		std::cout << std::boolalpha << (_42 >= negativeNumber) << std::endl;
		std::cout << std::boolalpha << (negativeNumber != _42) << std::endl;
		std::cout << std::boolalpha << (negativeNumber == negativeNumber) << std::endl;
	}

	std::cout << std::boolalpha << "Should be false:" << std::endl;
	{
		std::cout << std::boolalpha << (_4 > _8) << std::endl;
		std::cout << std::boolalpha << (_23 > _42) << std::endl;

		std::cout << std::boolalpha << (_8 >= _15) << std::endl;
		std::cout << std::boolalpha << (_16 >= _23) << std::endl;

		std::cout << std::boolalpha << (_15 <= _8) << std::endl;
		std::cout << std::boolalpha << (_23 <= _16) << std::endl;

		std::cout << std::boolalpha << (_42 < _23) << std::endl;
		std::cout << std::boolalpha << (_8 < _4) << std::endl;

		std::cout << std::boolalpha << (theNumber <= notTheNumber) << std::endl;
		std::cout << std::boolalpha << (notTheNumber >= _42) << std::endl;
		std::cout << std::boolalpha << (notTheNumber == _42) << std::endl;
		std::cout << std::boolalpha << (notTheNumber == theNumber) << std::endl;

		std::cout << std::boolalpha << (negativeNumber > _42) << std::endl;
		std::cout << std::boolalpha << (negativeNumber >= _42) << std::endl;
		std::cout << std::boolalpha << (_42 < negativeNumber) << std::endl;
		std::cout << std::boolalpha << (_42 <= negativeNumber) << std::endl;
		std::cout << std::boolalpha << (negativeNumber == _42) << std::endl;
		std::cout << std::boolalpha << (negativeNumber != negativeNumber) << std::endl;
	}
}

int main(void)
{
	testComparisonOperators();
	return 0;
}