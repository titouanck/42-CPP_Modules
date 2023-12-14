/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:00:02 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/15 16:56:56 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename C>
MutantStack<T, C>::MutantStack(void) : std::stack<T, C>()
{}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack<T, C> &obj) : std::stack<T, C>(obj)
{}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const std::stack<T, C> &obj) : std::stack<T, C>(obj)
{}

template <typename T, typename C>
MutantStack<T, C>::~MutantStack(void)
{}

template <typename T, typename C>
MutantStack<T, C>	&MutantStack<T, C>::operator=(const MutantStack<T, C> &obj)
{
	if (*this == obj)
		return (*this);
	while (!this->empty())
		this->pop();
	for (typename C::iterator it = ((MutantStack<T, C>) obj).c.begin(); it != ((MutantStack<T, C>) obj).c.end(); it++)
		this->push(*it);
	return (*this);
}

template <typename T, typename C>
MutantStack<T, C>	&MutantStack<T, C>::operator=(const std::stack<T, C> &obj)
{
	MutantStack<T, C>	mutant(obj);

	while (!this->empty())
		this->pop();
	for (typename C::iterator it = mutant.c.begin(); it != mutant.c.end(); it++)
		this->push(*it);
	return (*this);
}

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
