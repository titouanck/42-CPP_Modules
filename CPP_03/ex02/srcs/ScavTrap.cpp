/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:46:53 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/05/31 13:51:56 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap default constructor called for " << _name << ".\n";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src._name)
{
	std::cout << "ScavTrap copy constructor called for " << _name << ".\n";
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << _name << ".\n";
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
		this->_noHitPoints();
	else if (_energyPoints <= 0)
		this->_noEnergy();
	else
	{
		_energyPoints -= 1;
		std::cout << "🪓 ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	static bool	gateKeeper;

	if (_hitPoints <= 0)
		this->_noHitPoints();
	else if (!gateKeeper)
	{
		gateKeeper = true;
		std::cout << "🛡️  ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
	}
	else if (gateKeeper)
	{
		gateKeeper = false;
		std::cout << "🛡️  ScavTrap " << _name << " is no longer in Gate keeper mode." << std::endl;
	}
}

void	ScavTrap::_noHitPoints()
{
	std::cout << "💀 ScavTrap " << _name << " is no longer with us." << std::endl;
}

void	ScavTrap::_noEnergy()
{
	std::cout << "🔋 ScavTrap " << _name << " is short on energy points." << std::endl;
}