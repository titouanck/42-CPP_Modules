/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:41:46 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/05/31 15:38:28 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
	#define DIAMONDTRAP_HPP

	#include "FragTrap.hpp"
	
class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
		
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &src);
		~DiamondTrap();

		void	whoAmI();

		DiamondTrap	&operator=(const DiamondTrap &src);
};

#endif
