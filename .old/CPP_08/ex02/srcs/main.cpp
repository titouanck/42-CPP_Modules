/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:56:05 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/15 16:55:43 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	std::stack<int>					myStack;
	MutantStack<int>				myMutantStack;
	MutantStack<int>::iterator		it;

	myStack.push(4);
	myStack.push(8);
	myStack.push(15);
	myStack.push(16);
	myStack.push(23);
	myStack.push(42);

	myMutantStack = myStack;
	for (it = myMutantStack.begin(); it != myMutantStack.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "---" << std::endl;

	MutantStack<int>	anotherMutantStack(myMutantStack);
	
	for (it = anotherMutantStack.begin(); it != anotherMutantStack.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "---" << std::endl;
	
	MutantStack<int>	someOtherMutantStack = myMutantStack;
	
	for (it = someOtherMutantStack.begin(); it != someOtherMutantStack.end(); it++)
		std::cout << *it << std::endl;
}
