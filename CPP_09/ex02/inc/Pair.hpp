/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:21:42 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 18:45:22 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
	#define PAIR_HPP

	#include <string>
	#include <iostream>

/* ************************************************************************** */

template <typename T>
class Pair
{
	private:
		Pair();

	public:
		Pair(T &a, T &b);
		Pair(const Pair &copy);
		Pair &operator=(const Pair &copy);
		~Pair();

		T	*_a;
		T	*_b;
		
		void	sortDescending();
		T		&get_a() const;
		T		&get_b() const;

		bool operator<(const Pair &other) const;
		bool operator<=(const Pair &other) const;
		bool operator>(const Pair &other) const;
		bool operator>=(const Pair &other) const;
		bool operator==(const Pair &other) const;
};

template <typename T>
std::ostream	&operator<<(std::ostream &os, const Pair<T> &src);

/* ************************************************************************** */

	#include "Pair.tpp"

#endif
