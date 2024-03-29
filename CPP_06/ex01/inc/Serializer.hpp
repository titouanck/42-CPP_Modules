/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:17:42 by tchevrie          #+#    #+#             */
/*   Updated: 2023/12/19 15:35:12 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
	#define SERIALIZER_HPP

	#include <iostream>
	#include <string>
	#include <stdint.h>
	#include "Data.hpp"

/* ************************************************************************** */

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &copy);
		~Serializer();

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data			*deserialize(uintptr_t raw);
};

/* ************************************************************************** */

#endif
