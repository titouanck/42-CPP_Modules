/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:41:50 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/09 15:04:27 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
	#define PMERGEME_TPP

/* ************************************************************************** */

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

/* ************************************************************************** */

template <typename C>
C	fillContainer(unsigned int tab[], unsigned int size)
{
	C	container;

	for (unsigned int i = 0; i < size; i++)
		container.insert(container.end(), tab[i]);
	return container;
}

template <typename C>
void	printContainer(C container)
{
	typename C::iterator it;

	for (it = container.begin(); it != container.end(); it++)
	{
		if (it != container.begin())
		std::cout << ", ";
		std::cout << *it;
	}
	std::cout << std::endl;
}

/* ************************************************************************** */

#endif