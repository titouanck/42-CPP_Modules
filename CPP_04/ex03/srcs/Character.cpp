/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:29:48 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/03 19:10:09 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

unsigned int Character::_nbObjs = 0;
t_address Character::_unequipped = {0, 0};
t_address Character::_equipped = {0, 0};


Character::Character(std::string name)
{
	this->_nbObjs += 1;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
}

Character::Character(const Character &obj)
{
	_nbObjs += 1;
	*this = obj;
}

Character::~Character()
{
	t_address	*elem;
	t_address	*checkDuplicate;
	t_address	*next;

	_nbObjs -= 1;
	if (_nbObjs == 0 && _unequipped.next)
	{
		elem = _unequipped.next;
		while (elem)
		{
			next = elem->next;
			
			checkDuplicate = elem->next;
			while (checkDuplicate)
			{
				if (checkDuplicate->addr == elem->addr)
					break ;
				checkDuplicate = checkDuplicate->next;
			}
			
			if (!checkDuplicate)
			{
				for (int idx = 0; idx < 4; idx++)
					if (_inventory[idx] == elem->addr)
						_inventory[idx] = 0;

				delete (AMateria *) elem->addr; 
			}
			delete elem;
			elem = next;
		}
	}

	if (_nbObjs == 0 && _equipped.next)
	{
		elem = _equipped.next;
		while (elem)
		{
			next = elem->next;
			delete elem;
			elem = next;
		}
	}

	for (int idx = 0; idx < 4; idx++)
	{
		std::cout << "delete: " << _inventory[idx] << std::endl;
		delete _inventory[idx];
	}
}

Character	&Character::operator=(const Character &obj)
{
	this->_name = obj.getName();
	for (int i = 0; i < 4; i++)
	{
		if (!obj._inventory[i])
			this->_inventory[i] = 0;
		else
			this->_inventory[i] = obj._inventory[i]->clone();
	}
	return (*this);
}

const std::string	&Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	int	idx;

	for (idx = 0; idx < 4; idx++)
		if (!_inventory[idx])
			break ;
	if (idx >= 4)
	{
		this->lstAddUnequipped(m);
		std::cout << _name << ": impossible to equip." << std::endl;
		return ;
	}
	_inventory[idx] = m;
		this->lstAddEquipped(m);
	std::cout << _name << ": successfully equipped." << std::endl;
}

void	Character::unequip(int idx)
{
	if (!_inventory[idx])
		return ;
	
	this->lstAddUnequipped(_inventory[idx]);
	_inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx])
		_inventory[idx]->AMateria::use(target);
}

void		Character::lstAddUnequipped(AMateria *addr)
{
	t_address	*elem;
	
	elem = &_unequipped;
	while (elem->next)
		elem = elem->next;
	elem->next = new t_address;
	if (elem->next)
	{
		elem = elem->next;
		elem->addr = addr;
		elem->next = 0;
	}

	elem = &_equipped;
	while (elem->next)
	{
		if (elem->next->addr == addr)
			elem->next->addr = 0; 
		elem = elem->next;
	}
}

void		Character::lstAddEquipped(AMateria *addr)
{
	t_address	*elem;
	
	elem = &_unequipped;
	while (elem->next)
		elem = elem->next;
	elem->next = new t_address;
	if (elem->next)
	{
		elem = elem->next;
		elem->addr = addr;
		elem->next = 0;
	}
}

