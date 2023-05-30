/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:59:23 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/30 18:40:26 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "ClapTrap default constructor called.\n";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap &src) : _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage)
{
	std::cout << "ClapTrap copy constructor called.\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called.\n";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

void	ClapTrap::_noHitPoints()
{
	std::cout << "💀 ClapTrap " << _name << " is no longer with us." << std::endl;
}

void	ClapTrap::_noEnergy()
{
	std::cout << "🔋 ClapTrap " << _name << " is short on energy points." << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
		this->_noHitPoints();
	else if (_energyPoints <= 0)
		this->_noEnergy();
	else
	{
		_energyPoints -= 1;
		std::cout << "🪓 ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
		this->_noHitPoints();
	else if (_energyPoints <= 0)
		this->_noEnergy();
	else
	{
		std::cout << "💔 ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
		this->_noHitPoints();
	else if (_energyPoints <= 0)
		this->_noEnergy();
	else
	{
		std::cout << "⛏️  ClapTrap " << _name << " restore " << amount << " points of life." << std::endl;
		_energyPoints -= 1;
		_hitPoints += amount;
	}
}
