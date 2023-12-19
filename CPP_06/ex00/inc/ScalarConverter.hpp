/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:05:34 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/19 11:48:01 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
	#define SCALARCONVERTER_HPP

	#include <string>
	#include <iostream>
	#include <iomanip>
	#include <cfloat>
	#include <cstdlib>

	#define FLT_MY_MIN -FLT_MAX
	#define DBL_MY_MIN -DBL_MAX

/* ************************************************************************** */

class ScalarConverter
{
	public:
		static bool	convert(std::string literal);	
};

#endif
