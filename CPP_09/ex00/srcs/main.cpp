/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:46:25 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/04 16:46:59 by titouanck        ###   ########.fr       */
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

	existingDate(20031225);

	// if (argc != 2)
	// {
	// 	std::cerr << "Error: could not open file." << std::endl;
	// 	return 1;
	// }
	
	// try
	// {
	// 	BitcoinExchange	db("data/data.csv");
	// 	parsing(db, argv[1]);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// 	return 1;
	// }

	// return 0;
}

/* ************************************************************************** */
