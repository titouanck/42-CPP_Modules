/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:50:18 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/03 13:33:18 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "comments.hpp"

/* ************************************************************************** */

int	main(void)
{
	comment_("");
	MutantStack<std::string>	ms;

	ms.push("Podasai");
	ms.push("Snayzy");
	
	for (std::deque<std::string>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	_comment_("");

	std::stack<int>		stk;

	stk.push(4);
	stk.push(8);
	stk.push(15);
	stk.push(16);
	stk.push(23);
	stk.push(42);

	MutantStack<int>	msCopy(stk);

	for (std::deque<int>::iterator it = msCopy.begin(); it != msCopy.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}

/* ************************************************************************** */
