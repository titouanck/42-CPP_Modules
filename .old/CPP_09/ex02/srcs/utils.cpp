/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:16:42 by tchevrie          #+#    #+#             */
/*   Updated: 2023/07/17 16:38:18 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	swap(int *a, int *b)
{
	int	tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	printContainer(std::vector<int> vct)
{
	size_t	i;

	i = 0;
	for (std::vector<int>::iterator it = vct.begin(); it != vct.end(); it ++)
	{
		if (i % 2 == 0)
			std::cout << *it << ' ';
		else
			std::cout << RED << *it << NC << ' ';
		i += 1;
	}
	std::cout << '\n';
}

void	printContainerRed(std::vector<int> vct)
{
	size_t	i;

	i = 0;
	for (std::vector<int>::iterator it = vct.begin(); it != vct.end(); it ++)
	{
		std::cout << RED << *it << NC << ' ';
		i += 1;
	}
	std::cout << '\n';
}

void	printContainerDefault(std::vector<int> vct)
{
	size_t	i;

	i = 0;
	for (std::vector<int>::iterator it = vct.begin(); it != vct.end(); it ++)
	{
		std::cout << *it << ' ';
		i += 1;
	}
	std::cout << '\n';
}

void	printContainer(std::deque<int> vct)
{
	size_t	i;

	i = 0;
	for (std::deque<int>::iterator it = vct.begin(); it != vct.end(); it ++)
	{
		if (i % 2 == 0)
			std::cout << *it << ' ';
		else
			std::cout << RED << *it << NC << ' ';
		i += 1;
	}
	std::cout << '\n';
}

void	printContainerRed(std::deque<int> vct)
{
	size_t	i;

	i = 0;
	for (std::deque<int>::iterator it = vct.begin(); it != vct.end(); it ++)
	{
		std::cout << RED << *it << NC << ' ';
		i += 1;
	}
	std::cout << '\n';
}

void	printContainerDefault(std::deque<int> vct)
{
	size_t	i;

	i = 0;
	for (std::deque<int>::iterator it = vct.begin(); it != vct.end(); it ++)
	{
		std::cout << *it << ' ';
		i += 1;
	}
	std::cout << '\n';
}
