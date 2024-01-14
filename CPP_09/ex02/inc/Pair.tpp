/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:23:32 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 09:45:10 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_TPP
	#define PAIR_TPP

/* PRIVATE ****************************************************************** */

template <typename T>
Pair<T>::Pair() : _a(NULL), _b(NULL)
{
}

/* PUBLIC ******************************************************************* */

template <typename T>
Pair<T>::Pair(T &a, T &b) : _a(&a), _b(&b)
{
}

template <typename T>
Pair<T>::Pair(const Pair<T> &copy) : _a(copy._a), _b(copy._b)
{
}

template <typename T>
Pair<T>	&Pair<T>::operator=(const Pair<T> &copy)
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
void	Pair<T>::sortDescending()
{
	if (*(this->_b) > *(this->_a))
		std::swap(*(this->_b), *(this->_a));
}

template <typename T>
T	&Pair<T>::get_a() const
{
	return *(this->_a);
}

template <typename T>
T	&Pair<T>::get_b() const
{
	return *(this->_b);
}

/* ************************************************************************** */

template <typename T>
bool Pair<T>::operator<(const Pair &other) const
{
	return *(this->_a) < *(other._a);
}

template <typename T>
bool Pair<T>::operator<=(const Pair &other) const
{
	return *(this->_a) <= *(other._a);
}

template <typename T>
bool Pair<T>::operator>(const Pair &other) const
{
	return *(this->_a) > *(other._a);
}

template <typename T>
bool Pair<T>::operator>=(const Pair &other) const
{
	return *(this->_a) >= *(other._a);
}

template <typename T>
bool Pair<T>::operator==(const Pair &other) const
{
	return *(this->_a) == *(other._a);
}

/* ************************************************************************** */

template <typename T>
std::ostream	&operator<<(std::ostream &os, const Pair<T> &src)
{
	os << "[" << src.get_a() << ", " << src.get_b() << "]";
	return os;
}

/* ************************************************************************** */

#endif
