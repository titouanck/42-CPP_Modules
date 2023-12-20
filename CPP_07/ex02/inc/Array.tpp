/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:29:30 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/20 16:21:15 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
	#define ARRAY_TPP

/* ************************************************************************** */

template <typename T>
Array<T>::Array()
{
}

template <typename T>
Array<T>::Array(const Array &copy)
{
	(void)	copy;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &copy)
{
	(void)	copy;
	return *this;
}

template <typename T>
Array<T>::~Array()
{
}

/* ************************************************************************** */

#endif
