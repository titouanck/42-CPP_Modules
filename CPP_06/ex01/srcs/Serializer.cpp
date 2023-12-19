/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:17:31 by tchevrie          #+#    #+#             */
/*   Updated: 2023/12/19 17:02:57 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* PRIVATE ****************************************************************** */

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
	(void)	copy;
	return *this;
}

Serializer::~Serializer()
{
}

/* PUBLIC ******************************************************************* */

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	r;

	r = reinterpret_cast<uintptr_t>(ptr);
	return r;
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*r;

	r = reinterpret_cast<Data *>(raw);
	return r;
}

/* ************************************************************************** */
