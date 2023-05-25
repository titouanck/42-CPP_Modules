/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:12:00 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 10:55:30 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
	#define HUMANA_HPP

	#include <iostream>
	#include <string>
	#include <climits>
	#include "Weapon.hpp"


class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;

	public:
		void	attack();

		HumanA( std::string newName, Weapon &newWeapon );
};

#endif