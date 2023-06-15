/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:53:58 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/15 16:19:54 by tchevrie         ###   ########.fr       */
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
		// private:
		// 	T	*_begin;

		public:
			// class iterator;
			
			MutantStack(void);
			// MutantStack(const MutantStack<T> &obj);
			// ~MutantStack(void);

			// MutantStack<T, C>						&operator=(const MutantStack<T, C> &obj);
			// MutantStack<T, C>						&operator=(const std::stack<T, C> &obj);
			// typename std::deque<T, C>::iterator	begin(void);
			// typename std::deque<T, C>::iterator	end(void);
	};

	// template <typename T>
	// class MutantStack<T>::iterator
	// {
	// 	private:
	// 		T	*addr;
	// 	public:
	// 		T							&operator*();
	// 		MutantStack<T>::iterator	&operator=(T *inAddr);
	// 		MutantStack<T>::iterator	&operator=(const MutantStack<T>::iterator &obj);
	// 		MutantStack<T>::iterator	operator+(int n);
	// 		MutantStack<T>::iterator	&operator++(void);
	// 		MutantStack<T>::iterator	operator++(int);
	// 		MutantStack<T>::iterator	&operator--(void);
	// 		MutantStack<T>::iterator	operator--(int);
	// 		bool						operator!=(const MutantStack<T>::iterator &other);
	// };

	#include "MutantStack.tpp"

#endif