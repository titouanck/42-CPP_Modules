/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:58:32 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/13 16:39:25 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int sz) : N(sz)
{}

Span::Span(const Span &obj) : N(obj.N)
{
	*this = obj;
}

Span::~Span(void)
{}

Span	&Span::operator=(const Span &obj)
{
	vect = obj.vect;
	return (*this);
}

void	Span::addNumber(int nb)
{
	if (vect.size() < N)
		vect.push_back(nb);
	else
		throw (Span::Exception("Impossible to store another integer."));
}

void	Span::addNumber(unsigned int n, int value)
{
	if (vect.size() + n > N)
		throw (Span::Exception("Not enough space availaible."));
	vect.insert(vect.end(), n, value);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>::iterator	it;
	unsigned int							i;

	it = begin;
	i = vect.size();
	while (it != end && i < N)
	{
		i++;
		it++;
	}
	if (it != end)
		throw (Span::Exception("Not enough space availaible."));
	vect.insert(vect.end(), begin, end);
}

int	Span::shortestSpan(void)
{
	int						shortest;
	std::set<int>			s(vect.begin(), vect.end());
	std::set<int>::iterator	it;
	std::set<int>::iterator	itNext;

	if (vect.size() < 2)
		throw (Span::Exception("Not enough numbers in container to find a span."));
	if (vect.size() > s.size())
		return (0);
	shortest = INT_MAX;
	it = s.begin();
	itNext = s.begin();
	itNext++;
	while (itNext != s.end())
	{
		if (*itNext - *it < shortest)
			shortest = *itNext - *it;
		it = itNext;
		itNext++;
	}
	return (shortest);
}

int	Span::longestSpan(void)
{
	std::set<int>			s(vect.begin(), vect.end());
	std::set<int>::iterator	smallest;
	std::set<int>::iterator	largest;

	if (vect.size() < 2)
		throw (Span::Exception("Not enough numbers in container to find a span."));
	smallest = s.begin();
	largest = s.end();
	return (*(--largest) - *smallest);
}

void	Span::print(void)
{
	std::vector<int>::iterator	it;
	
	std::cout << "Numbers: ";
	for (it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

Span::Exception::Exception(const char *e) : exception(e)
{}

const char	*Span::Exception::what() const throw()
{
	return (exception);
}
