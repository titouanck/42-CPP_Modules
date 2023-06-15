/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:00:02 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/15 16:19:38 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename C = std::deque<T> >
MutantStack<T, C>::MutantStack(void)
{
	// this->push(42);
	// _begin = &(this->top());
	// this->pop();
}

// // template <typename T>
// template <typename T, typename C = std::deque<T> >
// MutantStack<T, C>::MutantStack(const MutantStack<T> &obj)
// {
// 	*this = obj;
// }

// // template <typename T>
// template <typename T, typename C = std::deque<T> >
// MutantStack<T, C>::~MutantStack(void)
// {}

// // template <typename T>
// template <typename T, typename C = std::deque<T> >
// MutantStack<T>	&MutantStack<T, C>::operator=(const MutantStack<T> &obj)
// {
// 	std::stack<T>	tmp;
// 	MutantStack<T>	objPtr;

// 	objPtr = (MutantStack<T> *) &obj;
// 	while (!this->empty())
// 		this->pop();
// 	while (!objPtr->empty())
// 	{
// 		tmp.push(objPtr->top());
// 		objPtr->pop();
// 	}
// 	while (!tmp.empty())
// 	{
// 		this->push(tmp.top());
// 		objPtr->push(tmp.top());
// 		tmp.pop();
// 	}
// 	return (*this);
// }

// // template <typename T>
// template <typename T, typename C = std::deque<T> >
// MutantStack<T>	&MutantStack<T, C>::operator=(const std::stack<T> &obj)
// {
// 	std::stack<T>	tmp;
// 	std::stack<T>	*objPtr;

// 	objPtr = (std::stack<T> *) &obj;
// 	while (!this->empty())
// 		this->pop();
// 	while (!objPtr->empty())
// 	{
// 		tmp.push(objPtr->top());
// 		objPtr->pop();
// 	}
// 	while (!tmp.empty())
// 	{
// 		this->push(tmp.top());
// 		objPtr->push(tmp.top());
// 		tmp.pop();
// 	}
// 	return (*this);
// }

// // template <typename T>
// template <typename T, typename C = std::deque<T> >
// typename std::deque<T>::iterator	MutantStack<T, C>::begin(void)
// {
// 	return (this->c.begin());
// }

// // template <typename T>
// template <typename T, typename C = std::deque<T> >
// typename std::deque<T>::iterator	MutantStack<T, C>::end(void)
// {
// 	return (this->c.end());
// }

// // template <typename T>
// // typename MutantStack<T, C>::iterator	&MutantStack<T, C>::iterator::operator=(T *inAddr)
// // {
// // 	addr = inAddr;
// // 	return (*this);
// // }

// // template <typename T>
// // typename MutantStack<T, C>::iterator	&MutantStack<T, C>::iterator::operator=(const MutantStack<T, C>::iterator &obj)
// // {
// // 	addr = obj.addr;
// // 	return (*this);
// // }

// // template <typename T>
// // typename MutantStack<T, C>::iterator	MutantStack<T, C>::iterator::operator+(int n)
// // {
// // 	MutantStack<T, C>::iterator	it;

// // 	it = *this;
// // 	it.addr += n;
// // 	return (it);
// // }

// // template <typename T>
// // T	&MutantStack<T, C>::iterator::operator*()
// // {
// // 	return (*addr);
// // }

// // template <typename T>
// // typename MutantStack<T, C>::iterator	&MutantStack<T, C>::iterator::operator++(void)
// // {
// // 	this->addr += 1;
// // 	return (*this);
// // }

// // template <typename T>
// // typename MutantStack<T, C>::iterator	MutantStack<T, C>::iterator::operator++(int)
// // {
// // 	MutantStack<T, C>::iterator	it;

// // 	it = *this;
// // 	this->addr += 1;
// // 	return (it);
// // }

// // template <typename T>
// // typename MutantStack<T, C>::iterator	&MutantStack<T, C>::iterator::operator--(void)
// // {
// // 	this->addr -= 1;
// // 	return (*this);
// // }

// // template <typename T>
// // typename MutantStack<T, C>::iterator	MutantStack<T, C>::iterator::operator--(int)
// // {
// // 	MutantStack<T, C>::iterator	it;

// // 	it = *this;
// // 	this->addr -= 1;
// // 	return (it);
// // }

// // template <typename T>
// // bool	MutantStack<T, C>::iterator::operator!=(const MutantStack<T, C>::iterator &other)
// // {
// // 	return (this->addr != other.addr);
// // }
