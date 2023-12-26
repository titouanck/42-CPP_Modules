/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:08:32 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/26 15:44:15 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
	#define EASYFIND_TPP

/* ************************************************************************** */

template <typename T>
int	&easyfind(T &container, int toFind)
{
	typename T::iterator	it;
	for (it = container.begin(); it != container.end(); it++)
	{
		if (*it == toFind)
			return *it;
	}
	throw std::runtime_error("easyfind: could not find this number");
}

/* ************************************************************************** */

#endif
