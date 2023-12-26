/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:21:19 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/26 12:03:58 by titouanck        ###   ########.fr       */
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
		
		Array(unsigned int n);
		
		T &operator[](size_t pos);
		unsigned int	size() const;

	private:
		T		*_array;
		size_t	_length;

		void	allocate(unsigned int n);
};

/* ************************************************************************** */

	#include "Array.tpp"

#endif
