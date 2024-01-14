/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:23:32 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 07:03:22 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_TPP
	#define PAIR_TPP

/* ************************************************************************** */

template <typename T>
Pair<T>::Pair()
{
}

template <typename T>
Pair<T>::Pair(const Pair<T> &copy)
{
	*this = copy;
}

template <typename T>
Pair<T>	Pair<T>::operator=(const Pair<T> &copy)
{
	this->_a = copy._a;
	this->_b = copy._b;
	return *this;
}

template <typename T>
Pair<T>::~Pair()
{
}

/* ************************************************************************** */

template <typename T>
Pair<T>::Pair(T a, T b)
{
	this->_a = a;
	this->_b = b;
}

/* ************************************************************************** */

template <typename T>
void	Pair<T>::sortDescending()
{
	T	tmp;

	if (this->_b > this->_a)
	{
		tmp = this->_b;
		this->_b = this->_a;
		this->_a = tmp;
	}
}

/* ************************************************************************** */

template <typename T>
bool Pair<T>::operator<(const Pair &other) const
{
	return (this->_a < other._a);
}

template <typename T>
bool Pair<T>::operator<=(const Pair &other) const
{
	return (this->_a <= other._a);
}

template <typename T>
bool Pair<T>::operator>(const Pair &other) const
{
	return (this->_a > other._a);
}

template <typename T>
bool Pair<T>::operator>=(const Pair &other) const
{
	return (this->_a >= other._a);
}

template <typename T>
bool Pair<T>::operator==(const Pair &other) const
{
	return (this->_a == other._a);
}

/* ************************************************************************** */

#endif
