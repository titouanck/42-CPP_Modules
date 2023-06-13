/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:58:32 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/13 14:21:42 by tchevrie         ###   ########.fr       */
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
	set = obj.set;
	return (*this);
}

void	Span::addNumber(int nb)
{
	if (set.size() < N)
		set.insert(nb);
	else
		throw (Span::Exception("Container full, impossible to store another integer."));
}

int	Span::shortestSpan(void)
{
	int						left;
	int						right;
	int						shortest;
	std::set<int>::iterator	it;
	std::set<int>::iterator	itNext;

	if (set.size() < 2)
		throw (Span::Exception("Not enough numbers in container to find a span."));
	shortest = INT_MAX;
	it = set.begin();
	itNext = set.begin();
	itNext++;
	while (itNext != set.end())
	{
		if (*itNext - *it < shortest)
		{
			left = *it;
			right = *itNext;
			shortest = right - left;
		}
		it++;
		itNext++;
	}
	std::cout << '[' << left << "-" << right << ']' << std::endl;
	return (shortest);
}

int	Span::longestSpan(void)
{
	int						left;
	int						right;
	int						longest;
	std::set<int>::iterator	it;
	std::set<int>::iterator	itNext;

	if (set.size() < 2)
		throw (Span::Exception("Not enough numbers in container to find a span."));
	longest = INT_MIN;
	it = set.begin();
	itNext = set.begin();
	itNext++;
	while (itNext != set.end())
	{
		if (*itNext - *it > longest)
		{
			left = *it;
			right = *itNext;
			longest = right - left;
		}
		it++;
		itNext++;
	}
	std::cout << '[' << left << "-" << right << ']' << std::endl;
	return (longest);
}

void	Span::print(void)
{
	std::set<int>::iterator	it;
	
	std::cout << "Numbers: ";
	for (it = set.begin(); it != set.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

Span::Exception::Exception(const char *e) : exception(e)
{}

const char	*Span::Exception::what() const throw()
{
	return (exception);
}
