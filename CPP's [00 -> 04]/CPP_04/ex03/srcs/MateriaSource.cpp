/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:29:31 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/03 17:15:18 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int idx = 0; idx < 4; idx++)
		_materias[idx] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	*this = obj;
}

MateriaSource::~MateriaSource()
{
	for (int idx = 0; idx < 4; idx++)
		delete _materias[idx];
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &obj)
{
	for (int idx = 0; idx < 4; idx++)
		this->_materias[idx] = obj._materias[idx];
	return (*this);
}

void MateriaSource::learnMateria(AMateria *src)
{
	int	idx;

	for (idx = 0; idx < 4; idx++)
		if (!_materias[idx])
			break ;
	if (idx >= 4)
	{
		delete src;
		return ;
	}
	_materias[idx] = src;
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	int	idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (_materias[idx] && _materias[idx]->getType().compare(type) == 0)
			return (_materias[idx]->clone());
	}
	return (0);
}
