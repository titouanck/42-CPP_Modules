/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 07:26:01 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 09:07:41 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie	*ptr;

	if (N < 1 || N > INT_MAX)
		return (NULL);
	ptr = new Zombie[N];
	if (!ptr)
		return (NULL);
	for (int i = 0; i < N; i++)
		ptr[i].defName(name);
	return (ptr);
}
