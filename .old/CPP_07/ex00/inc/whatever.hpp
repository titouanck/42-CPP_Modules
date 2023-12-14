/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:01:28 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/08 13:16:09 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
	#define WHATEVER_HPP

	#include <iostream>
	
	template <typename T>
	void	swap(T &a, T &b)
	{
		T	tmp;

		tmp = a;
		a = b;
		b = tmp;
	}

	template <typename T>
	T	min(T a, T b)
	{
		if (a < b)
			return (a);
		else
			return (b);
	}

	template <typename T>
	T	max(T a, T b)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}

#endif
