/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:21:19 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/20 16:18:28 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
	#define ARRAY_HPP

	#include <string>
	#include <iostream>

/* ************************************************************************** */

template <typename T>
class Array
{
	public:
		Array();
		Array(const Array &copy);
		Array &operator=(const Array &copy);
		~Array();
};

/* ************************************************************************** */

	#include "Array.tpp"

#endif
