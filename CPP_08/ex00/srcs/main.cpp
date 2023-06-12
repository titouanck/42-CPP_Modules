/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:23:48 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/12 18:45:32 by tchevrie         ###   ########.fr       */
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

	vect.push_back(4);	dqe.push_back(4);		lst.push_back(4);
	vect.push_back(8);	dqe.push_back(8);		lst.push_back(8);
	vect.push_back(15);	dqe.push_back(15);	lst.push_back(15);
	vect.push_back(16);	dqe.push_back(16);	lst.push_back(16);
	vect.push_back(23);	dqe.push_back(23);	lst.push_back(23);
	vect.push_back(42);	dqe.push_back(42);	lst.push_back(42);
	

	std::vector<int>::iterator	vectIt;
	std::deque<int>::iterator	dqeIt;
	std::list<int>::iterator	lstIt;
	std::cout << *easyfind(vect, 42) << std::endl;
	std::cout << *easyfind(dqe, 42) << std::endl;
	std::cout << *easyfind(lst, 42) << std::endl;

	std::cout << easyfind(vect, -42) << std::endl;
	// std::cout << *easyfind(deque, -42) << std::endl;
	// std::cout << *easyfind(lst, -42) << std::endl;

	// std::vector<int>	t(std::vector<int> stk);
	// std::vector<int>::container_type::iterator	vectResult;
	// std::stack<int>::container_type::iterator	stkResult;


	// std::cout << easyfind(stk, 42) << std::endl;
	// std::cout << easyfind(stk, 23) << std::endl;
	// std::cout << easyfind(stk, 16) << std::endl;
	// std::cout << easyfind(stk, 15) << std::endl;
	// std::cout << easyfind(stk, 8) << std::endl;
	// std::cout << easyfind(stk, 4) << std::endl;
	// std::cout << easyfind(stk, -42) << std::endl;
}
