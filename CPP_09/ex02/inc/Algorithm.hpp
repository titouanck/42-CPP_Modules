/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:13:44 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/15 10:36:02 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
	#define ALGORITHM_HPP

	#include <vector>
	#include <deque>
	#include "Pair.hpp"
	#include "binarySearch.hpp"

/* ************************************************************************** */

template <unsigned int N>
class Algorithm
{
	public:
		template <typename T>
		static void	fordJohnson(std::vector<T> &argContainer);

		template <typename T>
		static void	fordJohnson(std::deque<T> &argContainer);

		static int	jacobsthal(int n1, int n2);
		
		virtual ~Algorithm() = 0;
};

/* ************************************************************************** */

	#include "Algorithm.tpp"

#endif
