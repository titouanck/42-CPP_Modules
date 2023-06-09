/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:15:51 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/17 14:04:02 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
	#define BITCOINEXCHANGE_HPP

	#include <iostream>
	#include <string>
	#include <fstream>
	#include <map>
	#include <cstdlib>

	class BitcoinExchange
	{
		private:
			class 							Exception;
			std::map<std::string, float>	database;
	
			static std::string	_getKey(std::string line);
			static float		_getValue(std::string line);

		public:
			BitcoinExchange(const char *databaseName);
			BitcoinExchange(const BitcoinExchange &obj);
			~BitcoinExchange(void);
			
			BitcoinExchange	&operator=(const BitcoinExchange &obj);
			float			nearestLowValue(std::string date);
			static bool		correctlyFormatted(std::string inputDate);
	};

	class BitcoinExchange::Exception : public std::exception
	{
		private:
			const char *_exception;

		public:
			Exception(const char *exception);
			const char	*what() const throw();
	};

#endif
