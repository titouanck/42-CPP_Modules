/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:06:26 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/26 16:45:24 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#define NUMBERS {4, 8, 15, 16, 23, 42, 4, 8, 15, 16, 23, 42}

#define BLUE 	"\033[34m"
#define ITALIC 	"\033[3m"
#define NC 		"\033[0m"

/* ************************************************************************** */

template <typename T>
static void init(T &container);

/* ************************************************************************** */

int	main(void)
{
	/* VECTOR *************************************************************** */
	std::vector<int>			container;
	std::vector<int>::iterator	it;
	
	/* DEQUE **************************************************************** */
	// std::deque<int>				container;
	// std::deque<int>::iterator	it;
	
	/* LIST ***************************************************************** */
	// std::list<int>			container;
	// std::list<int>::iterator	it;

	/* ********************************************************************** */

	init(container);

	std::cout << "vector's content: " << std::endl;
	for (it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << "\t[" << &(*it) << ']' << std::endl;
	}
	std::cout << std::endl;
	
	/* ********************************************************************** */

	std::cout << "easyfind's return value" << std::endl;
	std::cout << "4\t[" << static_cast<void *>(&easyfind(container, 4)) << ']' << std::endl;
	std::cout << "42\t[" << static_cast<void *>(&easyfind(container, 42)) << ']' << std::endl;

	try
	{
		std::cout << "-42\t[" << static_cast<void *>(&easyfind(container, -42)) << ']' << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ']' << '\n';
	}
}

/* ************************************************************************** */

template <typename T>
static void init(T &container)
{
	int			numbers[] = NUMBERS;
	size_t		size;

	size = sizeof(numbers) / sizeof(numbers[0]);
	for (size_t i = 0; i < size; i++)
	{
		container.insert(container.end(), numbers[i]);
	}
}

/* ************************************************************************** */
