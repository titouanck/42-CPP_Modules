/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:06:35 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/08 14:49:44 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
	#define ARRAY_TPP

	template<typename T>
	Array<T>::Array(void)
	{
		_array = new T[0];
		_size = 0;
	}

	template<typename T>
	Array<T>::Array(const unsigned int n) : _size(n)
	{
		_array = new T[n];
		if (!_array)
			return ;
		for (size_t i = 0; i < n; i++)
			_array[i] = T();
	}

	template<typename T>
	Array<T>::Array(const Array &obj)
	{
		_array = NULL;
		*this = obj;
	}

	template<typename T>
	Array<T>::~Array(void)
	{
		if (_array)
			delete[] _array;
	}

	template<typename T>
	Array<T>	&Array<T>::operator=(const Array &obj)
	{
		if (this == &obj)
			return (*this);
		if (_array)
			delete[] (_array);
		_size = obj.size();
		_array = new T[_size];
		if (!_array)
			return (*this);
		if (obj._array)
		{
			for (size_t i = 0; i < _size; i++)
				_array[i] = obj._array[i];
		}
		else
		{
			for (size_t i = 0; i < _size; i++)
				_array[i] = T();
		}
		return (*this);
	}

	template<typename T>
	T	&Array<T>::operator[](size_t index)
	{
		if (index >= _size)
		{
			if (_size == 0)
				throw (Array<T>::OutOfRange("The array size is 0, so it is impossible to use the index operator."));
			else
				throw (Array<T>::OutOfRange("Index out of range, call .size() to find out the maximum index"));
		}
		return (_array[index]);
	}

	template<typename T>
	size_t	Array<T>::size(void) const
	{
		if (!_array)
			return (0);
		else
			return (_size);
	}

	template <typename T>
	Array<T>::OutOfRange::OutOfRange(const char *exception) : _exception(exception)
	{}

	template <typename T>
	const char	*Array<T>::OutOfRange::what(void) const throw()
	{
		return (_exception);
	}


#endif
