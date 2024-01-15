/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:11:51 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/15 10:29:56 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// 8 16 4 62 42 183 19 23 15 37

/* ************************************************************************** */

bool	PmergeMe(int argc, char **argv)
{
	std::vector<unsigned int>	vectorContainer;
	std::deque<unsigned int>	dequeContainer;
	long						nbr;
	std::string					str;
	char						*ptr;
	struct timeval				tv;
	size_t						startTime;
	size_t						endTime;
	
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		nbr = std::strtol(str.c_str(), &ptr, 0);
		if (nbr < 0 || nbr > static_cast<unsigned int>(-1) || ptr != (str.c_str() + str.length()))
			return std::cout << "Error" << std::endl, false;

		vectorContainer.push_back(nbr);
		dequeContainer.push_back(nbr);
	}
	
	std::cout << "Before: ";
	for (std::vector<unsigned int>::iterator it = vectorContainer.begin(); it != vectorContainer.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != vectorContainer.end())
			std::cout << " ";
	}
	std::cout << std::endl;

	// VECTOR START
	gettimeofday(&tv, 0);
	startTime = 1000000 * tv.tv_sec + tv.tv_usec;
	Algorithm<16>::fordJohnson<unsigned int >(vectorContainer);
	gettimeofday(&tv, 0);
	endTime = 1000000 * tv.tv_sec + tv.tv_usec;
	// VECTOR END

	std::cout << "After:  ";
	for (std::vector<unsigned int>::iterator it = vectorContainer.begin(); it != vectorContainer.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != vectorContainer.end())
			std::cout << " ";
	}
	std::cout << std::endl;
	
	std::cout << "Time to process a range of " << vectorContainer.size() << " elements with std::vector : " << endTime - startTime << " us" << std::endl;

	// DEQUE START
	gettimeofday(&tv, 0);
	startTime = 1000000 * tv.tv_sec + tv.tv_usec;
	Algorithm<16>::fordJohnson<unsigned int >(dequeContainer);
	gettimeofday(&tv, 0);
	endTime = 1000000 * tv.tv_sec + tv.tv_usec;
	// DEQUE END

	std::cout << "Time to process a range of " << dequeContainer.size() << " elements with std::deque  : " << endTime - startTime << " us" << std::endl;
	return true;
}

/* ************************************************************************** */
