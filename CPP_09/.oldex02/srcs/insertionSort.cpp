/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:40:13 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/09 14:49:01 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */

std::vector<unsigned int>	insertionSort(std::vector<unsigned int> container)
{
	std::vector<unsigned int>::iterator	it;
	std::vector<unsigned int>::iterator	previous;
	std::vector<unsigned int>::iterator	current;
	// unsigned int						nbr;

	it  = container.begin();
	while (it != container.end())
	{
		// nbr = *it;
		if (it != container.begin())
		{
			current	 = it;
			previous = current - 1;
			while (*current < *previous)
			{
				// printContainer(container);
				swap(*current, *previous);
				if (previous == container.begin())
					break ;
				current--;
				previous--;
			}
		}
		// std::cout << "[DONE " << nbr << "] ";
		// printContainer(container);
		it++;
	}
	return container;
}

/* ************************************************************************** */
