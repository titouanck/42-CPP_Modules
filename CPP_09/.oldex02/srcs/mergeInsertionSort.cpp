/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeInsertionSort.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:03:50 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 06:51:39 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

struct Pair {
	unsigned int						a;
	unsigned int						b;
};

/* ************************************************************************** */

static std::vector<Pair>	pairMerge(std::vector<Pair> left, std::vector<Pair> right)
{
	std::vector<Pair>	container;

	while (left.size() && right.size())
	{
		if (left.begin()->a < right.begin()->a)
		{
			container.insert(container.end(), *left.begin());
			left.erase(left.begin());
		}
		else
		{
			container.insert(container.end(), *right.begin());
			right.erase(right.begin());
		}
	}

	while (left.size())
	{
		container.insert(container.end(), *left.begin());
		left.erase(left.begin());
	}

	while (right.size())
	{
		container.insert(container.end(), *right.begin());
		right.erase(right.begin());
	}
	return container;
}

/* ************************************************************************** */

static std::vector<Pair>	pairMergeSort(std::vector<Pair> container)
{
	unsigned int size;
	
	size = container.size();
	if (size < 2)
		return container;

	std::vector<Pair>	left;
	std::vector<Pair>	right;

	left.insert(left.end(), container.begin(), container.begin() + (size / 2));
	right.insert(right.end(), container.begin() + (size / 2), container.end());
	left  = pairMergeSort(left);
	right = pairMergeSort(right);
	return pairMerge(left, right);
}

/* ************************************************************************** */

void	printContainer(std::vector<Pair> container)
{
	std::vector<Pair>::iterator it;

	for (it = container.begin(); it != container.end(); it++)
	{
		if (it != container.begin())
			std::cout << ", ";
		std::cout << "[ " << it->a << ", " << it->b << " ]";
	}
	std::cout << std::endl;
}

std::vector<unsigned int>	mergeInsertionSort(std::vector<unsigned int> container)
{
	std::vector<unsigned int> 			sortedContainer;
	std::vector<unsigned int>::iterator	it;
	std::vector<unsigned int>::iterator	it_2;

	unsigned int						steps;
	(void)	steps;
	unsigned int						totalSteps;
	(void)	totalSteps;
	
	Pair								pair;
	std::vector<Pair>					pairsContainer;
	std::vector<Pair>::iterator			pairsIt;

	for (it = container.begin(); it != container.end() && it + 1 != container.end(); it += 2)
	{
		pair.a = *it;
		pair.b = *(it + 1);
		if (pair.b < pair.a)
			swap(pair.b, pair.a);
		pairsContainer.insert(pairsContainer.end(), pair);
	}
	printContainer(pairsContainer);
	pairsContainer = pairMergeSort(pairsContainer);
	std::cout << "<<1>>  -------------------------------------" << std::endl;
	printContainer(pairsContainer);

	for (pairsIt = pairsContainer.begin(); pairsIt != pairsContainer.end(); pairsIt++)
		sortedContainer.insert(sortedContainer.end(), pairsIt->a);
	std::cout << "<<2>>  -------------------------------------" << std::endl;
	printContainer(sortedContainer);
	
	it = sortedContainer.begin() + 1;
	pairsIt = pairsContainer.begin();
		std::cout << "----------" << std::endl;
	totalSteps = 0;
	while (pairsIt != pairsContainer.end())
	{
		std::cout << "Current list: ";
		printContainer(sortedContainer);
		if (it != sortedContainer.end())
			std::cout << "*it = " << *it << std::endl;
		std::cout << "Number that we want to insert: " << pairsIt->b << std::endl;
		steps = 0;
		it_2 = it;
		while (it_2 != sortedContainer.end() && pairsIt->b > *it_2)
		{
			steps++;
			totalSteps++;
			it_2++;
		}
		std::cout << "steps needed: " << steps << std::endl;
		// next = it + 1;
		if (steps)
			it = sortedContainer.insert(it_2, pairsIt->b) - steps + 2;
		else
		{
			std::cout << "ELSE" << std::endl;
			it = sortedContainer.insert(it_2, pairsIt->b) + 2;
		}
		std::cout << "List now: ";
		printContainer(sortedContainer);
		std::cout << "----------" << std::endl;
		pairsIt++;
	}

	// for (pairsIt = pairsContainer.begin(); pairsIt != pairsContainer.end() && it != sortedContainer.end(); pairsIt++)
	// {
	// 	it_2 = it;
	// 	std::cout << "it2 = " << *it << std::endl;
	// 	while (it != sortedContainer.end() && it_2 != sortedContainer.end() && pairsIt->b < *it_2)
	// 		it_2++;
	// 	sortedContainer.insert(it_2 + 1, pairsIt->b);
	// 	std::cout << "<<3>> -------------------------------------" << std::endl;
	// 	printContainer(sortedContainer);
	// 	it++;
	// }
	std::cout << "-------------------------------------" << std::endl;
	printContainer(sortedContainer);
	std::cout << "-------------------------------------" << std::endl;
	return container;
}


/* ************************************************************************** */
