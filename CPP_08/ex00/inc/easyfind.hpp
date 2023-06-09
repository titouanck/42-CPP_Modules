/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:25:10 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/09 14:14:40 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
	#define EASYFIND_HPP

	template <typename T>
	typename T::iterator	easyfind(T &container, int nb)
	{
		typename T::iterator	it;

		for (it = container.begin(); it != container.end(); it++)
		{
			if (*it == nb)
				return (it);
		}
		return (container.end());
	}

#endif
