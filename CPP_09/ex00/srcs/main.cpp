/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:46:25 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/04 15:50:47 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comments.hpp"
#include "parsing.hpp"
#include "BitcoinExchange.hpp"

/* ************************************************************************** */

int	main(int argc, char **argv)
{
	(void)	argc;
	(void)	argv;

	// if (argc != 2)
	// {
	// 	std::cerr << "Error: could not open file." << std::endl;
	// 	return 1;
	// }
	
	try
	{
		BitcoinExchange	db("data/data.csv");
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// if (!parsing(argv[1]))
	// {
	// 	std::cerr << "Error: file is not valid." << std::endl;
	// 	return 1;
	// }

	return 0;
}

/* ************************************************************************** */
