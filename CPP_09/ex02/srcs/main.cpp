/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:11:51 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 07:14:14 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */

template <typename T>
void printVector(std::vector<T> vct)
{
	typename std::vector<T>::iterator	it;

	it = vct.begin();
	while (it != vct.end())
	{
		std::cout << *it;
		it++;
		if (it != vct.end())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int	main(void)
{
	std::vector<unsigned int>	vct;

	vct.push_back(8);
	// vct.push_back(16);
	// vct.push_back(4);
	// vct.push_back(42);
	// vct.push_back(23);
	// vct.push_back(15);
	fordJohnsonAlgorithm(vct);

	// Pair<unsigned int>	pair_a(8, 2);
	// Pair<unsigned int>	pair_b(6, 3);
	// std::cout << "pair_b < pair_a (should be 1) : " << (pair_b < pair_a) << std::endl;
	// std::cout << "pair_a < pair_b (should be 0) : " << (pair_a < pair_b) << std::endl;
	
	// printVector(vct);
}

/* ************************************************************************** */
