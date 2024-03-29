/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:29:30 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/26 11:38:25 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
	#define ARRAY_TPP

/* ************************************************************************** */

template <typename T>
Array<T>::Array()
{
	this->allocate(0);
}

template <typename T>
Array<T>::Array(const Array &copy)
{
	this->_array = NULL;
	*this = copy;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &copy)
{
	if (this->_array)
		delete[] this->_array;
	this->allocate(copy.size());
	if (this->_array)
	{
		for (size_t i = 0; i < this->_length; i++)
		{
			this->_array[i] = copy._array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (this->_array)
		delete[] this->_array;
}

/* ************************************************************************** */

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->allocate(n);
}

/* ************************************************************************** */

template <typename T>
T &Array<T>::operator[](size_t pos)
{
	if (pos >= this->_length)
		throw std::runtime_error("Array: index is out of bounds");
	return this->_array[pos];
}

/* ************************************************************************** */

template <typename T>
void	Array<T>::allocate(unsigned int n)
{
	this->_array = new T[n]();
	
	if (this->_array)
		this->_length = n;
	else
		this->_length = 0;
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return this->_length;
}

/* ************************************************************************** */

#endif
