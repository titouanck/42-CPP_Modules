/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:31:18 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/29 15:50:10 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */

Span::Span() : _N(0)
{
}

Span::Span(const Span &copy) : _N(copy._N)
{
	*this = copy;
}

Span	&Span::operator=(const Span &copy)
{
	if (copy._numbers.size() <= this->_N)
		this->_numbers = copy._numbers;
	else
		throw std::runtime_error("Span: the destination object has less capacity than necessary to accommodate the source object's numbers");
	return	*this;
}

Span::~Span()
{
}

/* ************************************************************************** */

Span::Span(unsigned int N) : _N(N)
{
}

/* ************************************************************************** */

void	Span::addNumber(int number)
{
	if (this->_numbers.size() < this->_N)
		this->_numbers.insert(this->_numbers.end(), number);
	else
		throw std::runtime_error("Span: object has already reached its maximum capcity");
}

void	Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	std::vector<int>::iterator	tmp;
	unsigned int				size;

	tmp = first;
	size = 0;
	while (tmp < last)
	{
		tmp++;
		size++;
	}
	if (this->_numbers.size() + size < this->_N)
		this->_numbers.insert(this->_numbers.end(), first, last);
	else
		throw std::runtime_error("Span: object do not have enough space to store that many numbers");
}

/* ************************************************************************** */

unsigned int	Span::shortestSpan()
{
	unsigned int				count;
	std::vector<int>::iterator	previousIt;	
	std::vector<int>::iterator	nextIt;	

	if (this->_numbers.size() < 2)
		throw std::runtime_error("Span: Not enough numbers to find a span (< 2)");
	std::sort(this->_numbers.begin(), this->_numbers.end());
	
	previousIt	= this->_numbers.begin();
	nextIt	 	= this->_numbers.begin() + 1;
	count		= -1;
	
	while (nextIt != this->_numbers.end())
	{
		if (static_cast<unsigned int>(*nextIt - *previousIt) < count)
			count = *nextIt - *previousIt;
		previousIt += 1;
		nextIt += 1;
	}
	return (count);
}

unsigned int	Span::longestSpan()
{
	if (this->_numbers.size() < 2)
		throw std::runtime_error("Span: Not enough numbers to find a span (< 2)");
	std::sort(this->_numbers.begin(), this->_numbers.end());
	
	return *(this->_numbers.end() - 1) - *this->_numbers.begin();
}

void	Span::debugPrint()
{
	std::cout << "content: ";
	for (std::vector<int>::iterator it = this->_numbers.begin(); it != this->_numbers.end(); it++)
	{
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}

/* ************************************************************************** */
