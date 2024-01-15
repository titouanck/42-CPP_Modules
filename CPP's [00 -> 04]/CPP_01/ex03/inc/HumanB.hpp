/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:12:00 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 11:11:43 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
	#define HUMANB_HPP

	#include <iostream>
	#include <string>
	#include <climits>
	#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;

	public:
		void	attack();
		void	setWeapon( Weapon &newWeapon );

		HumanB( std::string newName );
		HumanB( std::string newName, Weapon &newWeapon );
};

#endif