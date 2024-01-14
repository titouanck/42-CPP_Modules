/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:21:42 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 07:02:24 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
	#define PAIR_HPP

/* ************************************************************************** */

template <typename T>
class Pair
{
	public:
		Pair();
		Pair(const Pair &copy);
		Pair operator=(const Pair &copy);
		~Pair();

		Pair(T a, T b);

		void	sortDescending();
		T		_a;
		T		_b;

		bool operator<(const Pair &other) const;
		bool operator<=(const Pair &other) const;
		bool operator>(const Pair &other) const;
		bool operator>=(const Pair &other) const;
		bool operator==(const Pair &other) const;
};

/* ************************************************************************** */

	#include "Pair.tpp"

#endif
