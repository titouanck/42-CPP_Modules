/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:09:43 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/09 19:27:02 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

unsigned int smallestToLargest[] = {4, 8, 15, 16, 23, 42};
// unsigned int largestToSmallest[] = {42, 23, 16, 15, 17, 4};
unsigned int largestToSmallest[] = {13, 55, 87, 92, 30, 20, 70, 56, 53, 66, 33, 90};
// unsigned int largestToSmallest[] = {13, 54, 87, 92, 30, 20, 70, 55, 53, 66, 33, 90, 34, 62, 84, 100, 82, 75, 77, 22, 15, 51, 88, 48, 79, 96, 60, 19, 81, 6, 61, 18, 57, 85, 89, 24, 39, 27, 41, 44, 94, 72, 97, 35, 7, 69, 16, 46, 73, 28, 36, 86, 47, 65, 76, 78, 63, 80, 50, 32, 67, 99, 52, 14, 4, 43, 1, 38, 95, 56, 12, 26, 68, 59, 98, 31, 91, 37, 40, 2, 83, 17, 21, 64, 71, 25, 49, 9, 23, 58, 45, 3, 74, 10, 11, 29, 42, 8, 5, 93};


/* ************************************************************************** */

int	main(void)
{
	std::vector<unsigned int>	vct_largestToSmallest;
	vct_largestToSmallest = fillContainer<std::vector<unsigned int> >(largestToSmallest, sizeof(largestToSmallest) / sizeof(largestToSmallest[0]));
	// vct_largestToSmallest = insertionSort(vct_largestToSmallest);
	vct_largestToSmallest = mergeInsertionSort(vct_largestToSmallest);
	// printContainer(vct_largestToSmallest);

// 	std::vector<unsigned int>	vct_smallestToLargest;
// 	vct_smallestToLargest = fillContainer<std::vector<unsigned int> >(smallestToLargest, sizeof(smallestToLargest) / sizeof(smallestToLargest[0]));
// 	vct_smallestToLargest = insertionSort(vct_smallestToLargest);
// 	printContainer(vct_smallestToLargest);
}

/* ************************************************************************** */
