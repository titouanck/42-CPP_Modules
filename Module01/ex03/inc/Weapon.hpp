/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:12:00 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 10:29:49 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
	#define WEAPON_HPP

	#include <iostream>
	#include <string>
	#include <climits>

class Weapon
{
	private:
		std::string	type;

	public:
		const std::string	&getType();
		void				setType( std::string newType );

		Weapon( void );
		Weapon( std::string newType );
};

#endif