/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 07:18:59 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 09:06:21 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*ptr;
	int		N = 4;

	ptr = zombieHorde(N, "Maxime");
	if (ptr)
	{
		for (int i = 0; i < N; i++)
			ptr[i].announce();
		delete[] ptr;
	}
	return (0);
}