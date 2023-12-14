/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:56:45 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/08 14:43:19 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
	#define ARRAY_HPP

	#include <iostream>

	template <typename T>
	class Array
	{
		private:	
			class OutOfRange;

			T				*_array;
			size_t			_size;

		public:
			Array(void);
			Array(const unsigned int n);
			Array(const Array &obj);
			~Array(void);
			Array	&operator=(const Array &obj);
			T		&operator[](size_t index);

			size_t	size(void) const;
	};

	template <typename T>
	class Array<T>::OutOfRange : public std::exception
	{
		private:
			const char	*_exception;
		public:
			OutOfRange(const char *exception);
			const char	*what() const throw();
	};

	#include "Array.tpp"

#endif
