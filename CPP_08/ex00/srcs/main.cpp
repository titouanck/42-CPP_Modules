/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:23:48 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/13 11:49:14 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>
#include "easyfind.hpp"


int	main(void)
{
	std::vector<int>	vect;
	std::deque<int>		dqe;
	std::list<int>		lst;

	vect.push_back(4);		dqe.push_back(4);		lst.push_back(4);
	vect.push_back(8);		dqe.push_back(8);		lst.push_back(8);
	vect.push_back(15);		dqe.push_back(15);		lst.push_back(15);
	vect.push_back(16);		dqe.push_back(16);		lst.push_back(16);
	vect.push_back(23);		dqe.push_back(23);		lst.push_back(23);
	// vect.push_back(42);		dqe.push_back(42);		lst.push_back(42);
	

	std::vector<int>::iterator	vectIt;
	std::deque<int>::iterator	dqeIt;
	std::list<int>::iterator	lstIt;

	vectIt = easyfind(vect, 42);
	dqeIt = easyfind(dqe, 42);
	lstIt = easyfind(lst, 42);

	if (vectIt != vect.end())
		std::cout << "Found: " << *vectIt << std::endl;
	else
		std::cout << "Not Found in <vector>." << std::endl;
	if (dqeIt != dqe.end())
		std::cout << "Found: " << *dqeIt << std::endl;
	else
		std::cout << "Not Found in <deque>." << std::endl;
	if (lstIt != lst.end())
		std::cout << "Found: " << *lstIt << std::endl;
	else
		std::cout << "Not Found in <list>." << std::endl;
}
