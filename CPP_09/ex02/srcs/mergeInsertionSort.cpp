/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeInsertionSort.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:03:50 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/09 15:29:44 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

struct Pair {
	unsigned int	a;
	unsigned int	b;
};

/* ************************************************************************** */

static std::vector<unsigned int>	pairMerge(std::vector<Pair> left, std::vector<Pair> right)
{
	std::vector<unsigned int>	container;

	while (left.size() && right.size())
	{
		if (left.begin()->a < right.begin()->b)
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

static std::vector<unsigned int>	pairMergeSort(std::vector<Pair> container)
{
	unsigned int size;
	
	size = container.size();
	if (size < 2)
		return container;

	std::vector<unsigned int>	left;
	std::vector<unsigned int>	right;

	left.insert(left.end(), container.begin(), container.begin() + (size / 2));
	right.insert(right.end(), container.begin() + (size / 2), container.end());
	left  = mergeSort(left);
	right = mergeSort(right);
	return merge(left, right);
}

/* ************************************************************************** */

std::vector<unsigned int>	mergeInsertionSort(std::vector<unsigned int> container)
{
	std::vector<unsigned int>::iterator	it;
	
	Pair								pair;
	std::vector<Pair>					pairsContainer;
	std::vector<Pair>::iterator			pairsIt;

	// 1. Given an unsorted list, group the list into pairs. If the list is odd, the last element is unpaired.
	// 2. Each pair is sorted (using a single comparison each) into what we will call [a b] pairs.
	for (it = container.begin(); it != container.end() && it + 1 != container.end(); it += 2)
	{
		pair.a = *it;
		pair.b = *(it + 1);
		if (pair.b < pair.a)
			swap(pair.b, pair.a);
		pairsContainer.insert(pairsContainer.end(), pair);
	}
	// 3. The pairs are sorted recursively based on the a of each, and we call the pairs [a1 b1], [a2 b2] etc. If the list was odd, the unpaired element is considered the last b.
	pairMergeSort(pairsContainer);
	return container;
}


/* ************************************************************************** */
