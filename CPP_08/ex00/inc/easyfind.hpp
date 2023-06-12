/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:25:10 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/12 15:11:32 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
	#define EASYFIND_HPP

	template <typename T>
	int	easyfind(T &container, int nb)
	{
		for (int i = 0; container.begin() + i != container.end(); i++)
		{
			if (container.begin()[i] == nb)
				return (i);
		}
		return (-1);
	}

#endif
