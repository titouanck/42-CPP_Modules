/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:58:50 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/13 16:44:11 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
	#define SPAN_HPP

	#include <iostream>
	#include <vector>
	#include <set>
	#include <algorithm>
	#include <climits>

	class Span
	{
		private:
			class Exception;
			const unsigned int	N;
			std::vector<int>	vect;
			
		public:
			Span(unsigned int sz);
			Span(const Span &obj);
			~Span(void);
			Span	&operator=(const Span &obj);
			void	addNumber(int nb);
			void	addNumber(unsigned int n, int value);
			void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
			int		shortestSpan(void);
			int		longestSpan(void);
			void	print(void);
	};

	class Span::Exception : public std::exception
	{
		private:
			const char	*exception;

		public:
			Exception(const char *e);
			const char* what() const throw();
	};

#endif
