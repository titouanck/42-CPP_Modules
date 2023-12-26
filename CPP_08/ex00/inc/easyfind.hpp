/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:07:15 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/26 15:40:17 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
	#define EASYFIND_HPP

	#include <vector>
	#include <deque>
	#include <list>
	#include <string>
	#include <iostream>

/* ************************************************************************** */

template <typename T>
int	&easyfind(T &container, int toFind);

/* ************************************************************************** */

	#include "easyfind.tpp"

#endif
