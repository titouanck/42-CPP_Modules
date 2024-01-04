/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:45:30 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/04 15:45:07 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
	#define BITCOINEXCHANGE_HPP

	#include <string>
	#include <iostream>
	#include <fstream>
	#include <cstdlib>
	#include <map>

/* ************************************************************************** */

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string filename);
		~BitcoinExchange();

		static unsigned int	getDate(std::string str);
		static float		getValue(std::string str);


	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		std::map<unsigned int, float>	_database;
};

/* ************************************************************************** */

#endif
