/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:47:13 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/05/31 15:01:25 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
	#define SCAVTRAP_HPP

	#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		void	_noHitPoints();
		void	_noEnergy();

	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap();

		void	attack(const std::string &target);
		void	guardGate();

		ScavTrap	&operator=(const ScavTrap &src);
};

#endif
