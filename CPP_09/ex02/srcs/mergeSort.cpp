/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:44:17 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/09 14:49:00 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */

static std::vector<unsigned int>	merge(std::vector<unsigned int> left, std::vector<unsigned int> right)
{
	std::vector<unsigned int>	container;

	while (left.size() && right.size())
	{
		if (*left.begin() < *right.begin())
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

std::vector<unsigned int>	mergeSort(std::vector<unsigned int> container)
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
