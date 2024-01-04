/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:45:30 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/04 17:42:04 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
	#define BITCOINEXCHANGE_HPP

	#include <string>
	#include <iostream>
	#include <iomanip>
	#include <fstream>
	#include <cstdlib>
	#include <map>
	#include "date.hpp"

	#define FORMAT_ERROR	std::runtime_error("Error: file not correctly formatted.")
	#define DATE_ERROR		std::runtime_error("Error: date not correctly formatted.")
	#define VALUE_ERROR		std::runtime_error("Error: value not correctly formatted.")

/* ************************************************************************** */

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string filename);
		~BitcoinExchange();

		void	print();
		float	getExchangeRate(unsigned int date);

		static unsigned int	getDate(std::string str);
		static float		getValue(std::string str);


		std::map<unsigned int, float>	_database;
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);

};

/* ************************************************************************** */

#endif
