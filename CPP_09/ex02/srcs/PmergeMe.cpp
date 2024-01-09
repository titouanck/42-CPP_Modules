/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:09:43 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/09 15:09:40 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

unsigned int smallestToLargest[] = {4, 8, 15, 16, 23, 42};
unsigned int largestToSmallest[] = {42, 23, 16, 15, 8, 4};

/* ************************************************************************** */

int	main(void)
{
	std::vector<unsigned int>	vct_largestToSmallest;
	vct_largestToSmallest = fillContainer<std::vector<unsigned int> >(largestToSmallest, sizeof(largestToSmallest) / sizeof(largestToSmallest[0]));
	// vct_largestToSmallest = insertionSort(vct_largestToSmallest);
	vct_largestToSmallest = mergeInsertionSort(vct_largestToSmallest);
	printContainer(vct_largestToSmallest);

// 	std::vector<unsigned int>	vct_smallestToLargest;
// 	vct_smallestToLargest = fillContainer<std::vector<unsigned int> >(smallestToLargest, sizeof(smallestToLargest) / sizeof(smallestToLargest[0]));
// 	vct_smallestToLargest = insertionSort(vct_smallestToLargest);
// 	printContainer(vct_smallestToLargest);
}

/* ************************************************************************** */
