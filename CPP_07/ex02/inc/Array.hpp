/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:21:19 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/20 17:26:59 by titouanck        ###   ########.fr       */
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

		unsigned int	size();

	private:
		void			allocate(unsigned int n);
		
		T		*_array;
		size_t	_length;
};


/* ************************************************************************** */

	#include "Array.tpp"

#endif
