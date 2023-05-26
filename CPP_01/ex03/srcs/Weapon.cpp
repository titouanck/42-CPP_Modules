/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:12:53 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 10:59:01 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void )
{
	type = "";
}

Weapon::Weapon( std::string newType ) : type(newType)
{
	;
}

const std::string	&Weapon::getType()
{
	return (type);
}

void	Weapon::setType( std::string newType )
{
	type = newType;
	std::cout << "New type: " << type << std::endl;
}
