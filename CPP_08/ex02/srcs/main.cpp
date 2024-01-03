/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:50:18 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/03 13:15:27 by titouanck        ###   ########.fr       */
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
	MutantStack<int>	msCopy(stk);

	msCopy.push(4);
	msCopy.push(8);
	msCopy.push(15);
	msCopy.push(16);
	msCopy.push(23);
	msCopy.push(42);

	for (std::deque<int>::iterator it = msCopy.begin(); it != msCopy.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}

/* ************************************************************************** */
