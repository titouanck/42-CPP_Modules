/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:36:54 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/20 15:17:57 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
	#define ITER_HPP

	#include <string>
	#include <iostream>
	#include <cstdlib>

/* ************************************************************************** */

template <typename T>
void	iter(T *tab, size_t length, void (function)(T))
{
	size_t	i;

	if (tab == NULL)
		return ;
	
	i = 0;
	while (i < length && i < static_cast<size_t>(-1))
	{
		function(tab[i]);
		i++;
	}
}

/* ************************************************************************** */

#endif
