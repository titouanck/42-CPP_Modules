/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:38:30 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/20 14:27:50 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
	#define WHATEVER_HPP

	#include <string>
	#include <iostream>

/* ************************************************************************** */

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	&min(T &a, T &b)
{
	return (a < b ? a : b);
}

template <typename T>
T	&max(T &a, T &b)
{
	return (a > b ? a : b);
}

/* ************************************************************************** */

#endif
