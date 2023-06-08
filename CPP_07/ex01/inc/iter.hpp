/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:15:38 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/08 13:34:12 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
	#define ITER_HPP

	#include <iostream>

	template <typename T>
	void	addOne(T &a)
	{
		a += 1;
	}

	template <typename T>
	void	setToZero(T &a)
	{
		a = 0;
	}

	template <typename T>
	void	print(T &a)
	{
		std::cout << a << ' ';
	}

	template <typename T>
	void	iter(T *tab, size_t size, void (function)(T &))
	{
		size_t	i;

		if (!tab)
			return ;
		i = 0;
		while (i < size)
		{
			function(tab[i]);
			i++;
		}
	}

#endif
