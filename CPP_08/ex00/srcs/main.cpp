/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:23:48 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/12 16:04:55 by tchevrie         ###   ########.fr       */
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

int	main(void)
{
	std::stack<int>	stk;

	stk.push(4);
	stk.push(8);
	stk.push(15);
	stk.push(16);
	stk.push(23);
	stk.push(42);
	
	std::vector<int>	vect(std::vector<int> stk);

	vect.push_back(4);
	// std::vector<int>	vect;
	// vect.push_back(8);
	// vect.push_back(15);
	// vect.push_back(16);
	// vect.push_back(23);
	// vect.push_back(42);

	// std::cout << easyfind(vect, 42) << std::endl;
	// std::cout << easyfind(vect, 23) << std::endl;
	// std::cout << easyfind(vect, 16) << std::endl;
	// std::cout << easyfind(vect, 15) << std::endl;
	// std::cout << easyfind(vect, 8) << std::endl;
	// std::cout << easyfind(vect, 4) << std::endl;
	// std::cout << easyfind(vect, -42) << std::endl;

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
