/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:29:48 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/04 00:09:59 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

unsigned int Character::_nbObjs = 0;
t_address Character::_unequipped = {0, 0};
t_address Character::_equipped = {0, 0};

extern bool g_logs;

Character::Character(std::string name)
{
	if (g_logs)
		std::cout << ">> Constructor: [+] added <" << name << ">" << std::endl << std::endl;
	this->_nbObjs += 1;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
}

Character::Character(const Character &obj)
{
	_nbObjs += 1;
	this->_name = obj.getName();
	*this = obj;
	if (g_logs)
		std::cout << ">> Constructor: [+] added <" << getName() << ">" << std::endl << std::endl; 
}

Character::~Character()
{
	t_address	*elem;
	t_address	*next;

	_nbObjs -= 1;
	if (g_logs)
		std::cout << ">> Destructor: [-] removed <" << getName() << ">" << std::endl << std::endl;
	for (int idx = 0; idx < 4; idx++)
		if (_inventory[idx])
			unequip(idx);
	if (g_logs)
		std::cout << std::endl;

	if (_nbObjs == 0)
	{
		if (_unequipped.next)
		{
			elem = _unequipped.next;
			while (elem)
			{
				next = elem->next;			
				delete (AMateria *) elem->addr;
				delete elem;
				elem = next;
			}
		}
		_unequipped.addr = 0;
		_unequipped.next = 0;

		if (_equipped.next)
		{
			elem = _equipped.next;
			while (elem)
			{
				next = elem->next;
				delete elem;
				elem = next;
			}
		}
		_equipped.addr = 0;
		_equipped.next = 0;
	}
}

Character	&Character::operator=(const Character &obj)
{
	if (&obj == this)
		return (*this);
	std::cout << "ici" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (!obj._inventory[i])
			this->_inventory[i] = 0;
		else
		{
			std::cout << "else" << std::endl;
			if (this->_inventory[i])
				unequip(i);
			equip(obj._inventory[i]->clone());
		}
	}
	return (*this);
}

const std::string	&Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* addr)
{
	int	idx;

	if (_isEquipped(addr))
	{
		if (g_logs)
			std::cout << BRED "[FAILURE]" GREEN " [+0 item] " NC << addr << " (item not on the ground)" << std::endl;
		return ;
	}
	
	for (idx = 0; idx < 4; idx++)
		if (!_inventory[idx])
			break ;
	if (idx >= 4)
	{
		this->_lstUnequip(addr);
		if (g_logs)
			std::cout << BRED "[FAILURE]" GREEN " [+0 item] " NC << addr << " (inventory full)" << std::endl;
		return ;
	}
	else
	{
		_inventory[idx] = addr;
		this->_lstEquip(addr);
		if (g_logs)
			std::cout << BGREEN "[SUCCESS]" GREEN " [+1 item] " NC << addr << std::endl;
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0)
	{
		if (g_logs)
			std::cout << BRED "[FAILURE]" RED " [-0 item] " NC << idx << " < 0 (out of range)" << std::endl;
		return ;
	}
	if (idx >= 4)
	{
		if (g_logs)
			std::cout << BRED "[FAILURE]" RED " [-0 item] " NC << idx << " > 3 (out of range)" << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		if (g_logs)
			std::cout << BRED "[FAILURE]" RED " [-0 item] " NC << _inventory[idx] << std::endl;
		return ;
	}
	else
	{
		if (g_logs)
			std::cout << BGREEN "[SUCCESS]" RED " [-1 item] " NC << _inventory[idx] << std::endl;
		this->_lstUnequip(_inventory[idx]);
		_inventory[idx] = 0;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx])
		_inventory[idx]->AMateria::use(target);
}

void		Character::_lstUnequip(AMateria *addr)
{
	t_address	*elem;
	
	if (_isUnequipped(addr))
		return ;
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

	if (_isEquipped(addr))
	{
		elem = &_equipped;
		while (elem->next)
		{
			if ((AMateria *) elem->next->addr == addr)
				elem->next->addr = 0; 
			elem = elem->next;
		}
	}
}

void		Character::_lstEquip(AMateria *addr)
{
	t_address	*elem;
	
	if (_isEquipped(addr))
		return ;
	elem = &_equipped;
	while (elem->next)
		elem = elem->next;
	elem->next = new t_address;
	if (elem->next)
	{
		elem = elem->next;
		elem->addr = addr;
		elem->next = 0;
	}

	if (_isUnequipped(addr))
	{
		elem = &_unequipped;
		while (elem->next)
		{
			if ((AMateria *) elem->next->addr == addr)
				elem->next->addr = 0; 
			elem = elem->next;
		}
	}
}

bool Character::_isEquipped(AMateria *addr)
{
	t_address	*elem;
	
	elem = &_equipped;
	while (elem->next)
	{
		if (elem->next->addr == addr)
			return (true);
		elem = elem->next;
	}
	return (false);
}

bool Character::_isUnequipped(AMateria *addr)
{
	t_address	*elem;
	
	elem = &_unequipped;
	while (elem->next)
	{
		if (elem->next->addr == addr)
			return (true);
		elem = elem->next;
	}
	return (false);
}
