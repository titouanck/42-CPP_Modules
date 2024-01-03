/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:50:45 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/03 13:16:04 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
	#define MUTANTSTACK_HPP

	#include <iostream>
	#include <stack>
	#include <deque>
	#include <algorithm>

/* ************************************************************************** */

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, std::deque<T> >
{	
	public:
		MutantStack(void);
		MutantStack(const MutantStack<T, C> &obj);
		MutantStack<T, C> &operator=(const MutantStack<T, C> &obj);
		MutantStack<T, C> &operator=(const std::stack<T, C> &obj);
		MutantStack(const std::stack<T, C> &obj);
		~MutantStack(void);

		typedef typename C::iterator iterator;

		iterator	begin(void);
		iterator	end(void);
};

/* ************************************************************************** */

	#include "MutantStack.tpp"

#endif
