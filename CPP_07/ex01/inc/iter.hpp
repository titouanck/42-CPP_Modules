/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:36:54 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/29 15:54:28 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
	#define ITER_HPP

	#include <string>
	#include <iostream>
	#include <cstdlib>

/* ************************************************************************** */

template <typename T, typename F>
void	iter(T *tab, size_t length, F function)
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
