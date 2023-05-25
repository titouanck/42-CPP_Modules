/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:24:38 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 11:15:51 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string newName ) : name(newName)
{
	weapon = NULL;
}

HumanB::HumanB( std::string newName, Weapon &newWeapon ) : name(newName), weapon(&newWeapon)
{
	;
}


void	HumanB::setWeapon( Weapon &newWeapon )
{
	weapon = &newWeapon;
}


void	HumanB::attack()
{
	if (!weapon)
		std::cout << name << " can't attack due to the lack of a weapon" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
