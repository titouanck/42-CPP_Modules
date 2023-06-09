/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:23:48 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/09 14:57:43 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <queue>
#include <map>
#include <list>
#include <stack>


#include <algorithm>
#include <iostream>
#include "easyfind.hpp"

template <typename T>
void	fillContainerPushBack(T &container)
{
	container.push_back(4);
	container.push_back(8);
	container.push_back(15);
	container.push_back(16);
	container.push_back(23);
	container.push_back(42);
}

template <typename T>
void	fillContainerPush(T &container)
{
	container.push(4);
	container.push(8);
	container.push(15);
	container.push(16);
	container.push(23);
	container.push(42);
}

int	main(void)
{
	std::vector<int>			myVector;
	std::deque<int>				myDeque;
	std::list<int>				myList;
	std::stack<int>				myStack;
	std::queue<int>				myQueue;
	std::priority_queue<int>	myPriorityQueue;
	
	std::vector<int>::iterator	it;
	std::deque<int>::iterator	it2;
	std::list<int>::iterator	it3;
	std::stack<int>::iterator	it4;
	std::queue<int>::iterator	it5;
	std::priority_queue<int>::iterator	it6;

	fillContainerPushBack(myVector);
	fillContainerPushBack(myDeque);
	fillContainerPushBack(myList);
	fillContainerPush(myStack);
	fillContainerPush(myQueue);
	fillContainerPush(myPriorityQueue);

	it = easyfind(myVector, 23);
	if (it == myVector.end())
		std::cout << "Not founded." << std::endl;
	else
	{
		std::cout << "Founded!" << std::endl;
		std::cout << "Located between " << *(it - 1) << " and " << *(it + 1) << std::endl;
	}

	it2 = easyfind(myDeque, 23);
	if (it2 == myDeque.end())
		std::cout << "Not founded." << std::endl;
	else
	{
		std::cout << "Founded!" << std::endl;
		std::cout << "Located between " << *(it2 - 1) << " and " << *(it2 + 1) << std::endl;
	}

	it3 = easyfind(myList, 23);
	if (it3 == myList.end())
		std::cout << "Not founded." << std::endl;
	else
	{
		std::cout << "Founded!" << std::endl;
		std::cout << "Located between ";
		it3--;
		std::cout << *it3 << " and ";
		it3++;
		it3++;
		std::cout << *it3 << std::endl;
	}

}
