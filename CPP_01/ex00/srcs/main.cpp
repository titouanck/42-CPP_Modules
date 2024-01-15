/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 07:18:59 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 09:04:56 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*foo;

	foo = newZombie("foo");
	if (foo)
		foo->announce();

	randomChump("bar");
	randomChump("baz");
	
	delete foo;
	return (0);
}