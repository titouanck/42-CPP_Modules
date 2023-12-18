/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:10:04 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/18 19:04:40 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ************************************************************************** */

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int	i;

		i = 0;
		while (++i < argc)
			if (!ScalarConverter::convert(argv[i]))
				return 1;
	}
	else
	{
		std::cout << FLT_MAX << std::endl;
		std::cout << DBL_MAX << std::endl;
	}
	return 0;
}
