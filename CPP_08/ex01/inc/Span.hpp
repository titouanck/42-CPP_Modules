/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:47:52 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/29 15:29:48 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
	#define SPAN_HPP

	#include <cstdlib>
	#include <vector>
	#include <algorithm>
	#include <stdexcept>
	#include <string>
	#include <iostream>

/* ************************************************************************** */

class Span
{
	public:
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();

		Span(unsigned int N);

		void			addNumber(int number);
		void			addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			debugPrint();

	private:
		Span();

		std::vector<int>	_numbers;
		const unsigned int	_N;
};

/* ************************************************************************** */

#endif
