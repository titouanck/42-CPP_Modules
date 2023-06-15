/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:56:05 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/15 16:07:04 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	std::stack<int>				stk;
	MutantStack<int>			myMStack;
	// std::deque<int>::iterator		it;


	stk.push(4);
	stk.push(8);
	stk.push(15);
	stk.push(16);
	stk.push(23);
	stk.push(42);

	// myMStack = stk;
	// for (it = myMStack.begin(); it != myMStack.end(); it++)
	// 	std::cout << *it << std::endl;
}
