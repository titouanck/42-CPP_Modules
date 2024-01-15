/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 07:20:11 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 08:59:43 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string input ) : name(input)
{
	;
}

Zombie::Zombie( void )
{
	;	
}

Zombie::~Zombie()
{
	std::cout << "Successfuly eliminated " << name << "!" << std::endl;
}

void	Zombie::defName( std::string input )
{
	name = input;
}

void	Zombie::announce( void ) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
