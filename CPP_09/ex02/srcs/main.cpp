/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:11:51 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 12:42:42 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "binarySearch.hpp"

/* ************************************************************************** */

// template <typename T>
// void printVector(std::vector<T> vct)
// {
// 	typename std::vector<T>::iterator	it;

// 	it = vct.begin();
// 	while (it != vct.end())
// 	{
// 		std::cout << *it;
// 		it++;
// 		if (it != vct.end())
// 			std::cout << ", ";
// 	}
// 	std::cout << std::endl;
// }

int	main(int ac, char **av)
{
	(void)	ac;
	(void)	av;
	
	std::vector<unsigned int>	vct;
	std::vector<unsigned int>::iterator	it;
	vct.push_back(8);
	vct.push_back(16);
	vct.push_back(4);
	vct.push_back(62);
	vct.push_back(42);
	vct.push_back(183);
	vct.push_back(19);
	vct.push_back(23);
	vct.push_back(15);
	vct.push_back(37);

	// for (it = vct.begin(); it != vct.end(); it++)
	// {
	// 	std::cout << *it << ", ";
	// }
	// std::cout << std::endl;

	// vct.push_back(8);
	// vct.push_back(16);
	// vct.push_back(4);
	// vct.push_back(42);
	// vct.push_back(23);
	// vct.push_back(15);

	// vct.push_back(1);
	// vct.push_back(4);
	// vct.push_back(5);
	// vct.push_back(7);
	// vct.push_back(40);
	// vct.push_back(50);


	// vct.push_back(4);
	// vct.push_back(7);
	// vct.push_back(50);
	recursivity<32>::fordJohnsonAlgorithm<unsigned int>(vct);
	
	std::cout << "final result: ";
	for (it = vct.begin(); it != vct.end(); it++)
	{
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	// Pair<unsigned int>	pair_a(8, 2);
	// Pair<unsigned int>	pair_b(6, 3);
	// std::cout << "pair_b < pair_a (should be 1) : " << (pair_b < pair_a) << std::endl;
	// std::cout << "pair_a < pair_b (should be 0) : " << (pair_a < pair_b) << std::endl;
	
	// printVector(vct);

	// std::cout << *(binarySearch(vct.begin(), vct.end(), static_cast<unsigned int>(1))) << std::endl;
}

/* ************************************************************************** */
