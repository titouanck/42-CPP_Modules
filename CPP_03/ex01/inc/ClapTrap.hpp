/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:53:34 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/30 18:28:26 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
	#define CLAPTRAP_HPP

	#include <string>
	#include <climits>
	#include <iostream>

	#define RED "\033[0;31m"
	#define GREEN "\033[0;32m"
	#define YELLOW "\033[33m"
	#define BLUE "\033[0;34m"
	#define NC "\033[0m"

class ClapTrap
{
	private:
		std::string	_name;
		int		_hitPoints;
		int		_energyPoints;
		int		_attackDamage;

		void	_noEnergy(void);
		void	_noHitPoints(void);

	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &src);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &src);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
