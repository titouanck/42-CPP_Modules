/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:17:31 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/07 22:01:37 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Data Serializer::_lstData = {};

Serializer::Serializer(Data *ptr)
{
	Serializer::serialize(ptr);
}

Serializer::Serializer(const Serializer &obj)
{
	(void) obj;
} 

Serializer::~Serializer(void)
{
	
}

Serializer	&Serializer::operator=(const Serializer &obj)
{
	(void)	obj;
	return (*this);
}

unsigned long int	Serializer::serialize(Data *ptr)
{
	Data	*current;

	if (ptr)
	{
		current = &_lstData;
		while (current->next)
		{
			if (current->next == ptr)
				return (ptr->serialNumber);
			current = current->next;
		}
		current->next = ptr;
		current->next->next = NULL;
		return (ptr->serialNumber);
	}
	else
		throw (Serializer::NullPointer("Function takes the address of a Data element as argument."));
}

Data	*Serializer::deserialize(unsigned long int serialNumber)
{
	Data	*current;

		current = &_lstData;
		while (current->next)
		{
			if (current->next->serialNumber == serialNumber)
				return (current->next);
			current = current->next;
		}
		return (NULL);	
}

Serializer::NullPointer::NullPointer(const char *exception) : _exception(exception)
{}

const char	*Serializer::NullPointer::what(void) const throw()
{
	return (_exception);
}
