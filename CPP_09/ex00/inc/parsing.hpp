/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:53:57 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/04 17:53:04 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HPP
	#define PARSING_HPP

	#include <string>
	#include <iostream>
	#include <fstream>
	#include "BitcoinExchange.hpp"
	#include "date.hpp"

/* ************************************************************************** */

void	parsing(BitcoinExchange &db, std::string filename);

/* ************************************************************************** */

#endif
