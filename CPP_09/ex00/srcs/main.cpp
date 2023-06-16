/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:52:44 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/16 16:02:06 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	(void)	argc;
	(void)	argv;
	// if (argc != 2)
	// {
	// 	std::cerr << "btc : The program takes a single file as argument." << std::endl;
	// 	return (1);
	// }

	try
	{
		BitcoinExchange	btc("data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << "[btc] " << e.what() << '\n';
		return (1);
	}
	return (0);
}
