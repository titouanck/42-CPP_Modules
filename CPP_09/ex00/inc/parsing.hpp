/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:53:57 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/04 16:44:24 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HPP
	#define PARSING_HPP

	#include <string>
	#include <iostream>
	#include <fstream>

/* ************************************************************************** */

bool	parsing(BitcoinExchange db, std::string filename);
bool	existingDate(unsigned int date);

/* ************************************************************************** */

#endif
