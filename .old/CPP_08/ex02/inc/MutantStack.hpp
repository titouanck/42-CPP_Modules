/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:53:58 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/15 16:39:40 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
	#define MUTANTSTACK_HPP

	#include <iostream>
	#include <stack>
	#include <deque>
	#include <algorithm>


	template <typename T, typename C = std::deque<T> >
	class MutantStack : public std::stack< T, std::deque<T> >
	{	
		public:
			typedef typename C::iterator iterator;
			MutantStack(void);
			MutantStack(const MutantStack<T, C> &obj);
			MutantStack(const std::stack<T, C> &obj);
			~MutantStack(void);
			MutantStack<T, C>	&operator=(const MutantStack<T, C> &obj);
			MutantStack<T, C>	&operator=(const std::stack<T, C> &obj);
			iterator			begin(void);
			iterator			end(void);
	};

	#include "MutantStack.tpp"

#endif
