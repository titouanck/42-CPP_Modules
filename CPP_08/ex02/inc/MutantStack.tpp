/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:51:30 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/03 13:07:49 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
	#define MUTANTSTACK_TPP

/* ************************************************************************** */

template <typename T, typename C>
MutantStack<T, C>::MutantStack(void) : std::stack<T, C>()
{
}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack<T, C> &copy) : std::stack<T, C>(copy)
{
}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const std::stack<T, C> &copy) : std::stack<T, C>(copy)
{
}

/* ************************************************************************** */

template <typename T, typename C>
MutantStack<T, C>	&MutantStack<T, C>::operator=(const MutantStack<T, C> &copy)
{
	if (*this == copy)
		return (*this);
	while (!this->empty())
		this->pop();
	for (typename C::iterator it = ((MutantStack<T, C>) copy).c.begin(); it != ((MutantStack<T, C>) copy).c.end(); it++)
		this->push(*it);
	return (*this);
}

template <typename T, typename C>
MutantStack<T, C>	&MutantStack<T, C>::operator=(const std::stack<T, C> &copy)
{
	MutantStack<T, C>	mutant(copy);

	while (!this->empty())
		this->pop();
	for (typename C::iterator it = mutant.c.begin(); it != mutant.c.end(); it++)
		this->push(*it);
	return (*this);
}

/* ************************************************************************** */

template <typename T, typename C>
MutantStack<T, C>::~MutantStack(void)
{
}

/* ************************************************************************** */

template <typename T, typename C>
typename C::iterator	MutantStack<T, C>::begin(void)
{
	return (this->c.begin());
}

template <typename T, typename C>
typename C::iterator	MutantStack<T, C>::end(void)
{
	return (this->c.end());
}

/* ************************************************************************** */

#endif
