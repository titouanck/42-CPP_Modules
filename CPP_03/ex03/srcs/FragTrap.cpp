/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:02:27 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/05/31 14:30:54 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap default constructor called for " << _name << ".\n";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src._name)
{
	std::cout << "FragTrap copy constructor called for " << _name << ".\n";
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << _name << ".\n";
}

FragTrap	&FragTrap::operator=(const FragTrap &src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (_hitPoints <= 0)
		std::cout << "💀 FragTrap " << _name << " cannot make a high fives, because he is no longer with us :(" << std::endl;
	else
		std::cout << "🙏 FragTrap " << _name << " would really appreciate a high fives :)))" << std::endl;
		
}
