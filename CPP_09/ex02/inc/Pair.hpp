/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:21:42 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 10:12:11 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
	#define PAIR_HPP

	#ifndef NULL
		#define NULL 0
	#endif

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
