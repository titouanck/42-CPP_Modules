/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:56:16 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/07 18:29:00 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	
	if (argc > 1)
		ScalarConverter::convert(argv[1]);
	else
	{
		std::cout << ">> A few tests :" << std::endl << std::endl;
		
		ScalarConverter	_42("42");
		std::cout << "[42]" << std::endl << std::endl;
		_42.convertIt();

		std::cout << "--- ---- --- --- ---" << std::endl;

		ScalarConverter	_D("D");
		std::cout << "[D]" << std::endl << std::endl;
		_D.convertIt();

		std::cout << "--- ---- --- --- ---" << std::endl;

		ScalarConverter	_42p0f("42.0f");
		std::cout << "[42.0f]" << std::endl << std::endl;
		_42p0f.convertIt();

		std::cout << "--- ---- --- --- ---" << std::endl;

		ScalarConverter	_0f("0f");
		std::cout << "[0f]" << std::endl << std::endl;
		_0f.convertIt();

		std::cout << "--- ---- --- --- ---" << std::endl;

		ScalarConverter	_2147483647("2147483647");
		std::cout << "[2147483647]" << std::endl << std::endl;
		_2147483647.convertIt();

		std::cout << "--- ---- --- --- ---" << std::endl;
		
		ScalarConverter	_2147483648("2147483648");
		std::cout << "[2147483648]" << std::endl << std::endl;
		_2147483648.convertIt();

		std::cout << "--- ---- --- --- ---" << std::endl;

		ScalarConverter	_n2147483648("-2147483648");
		std::cout << "[-2147483648]" << std::endl << std::endl;
		_n2147483648.convertIt();

		std::cout << "--- ---- --- --- ---" << std::endl;

		ScalarConverter	_n2147483649("-2147483649");
		std::cout << "[-2147483649]" << std::endl << std::endl;
		_n2147483649.convertIt();
	}
}
