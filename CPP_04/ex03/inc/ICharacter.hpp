/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:49:37 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/03 18:21:03 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
	#define ICHARACTER_HPP

	#include <iostream>
	#include <string>

	class AMateria;

	class ICharacter
	{
		public:
			virtual ~ICharacter() {}
			virtual std::string	const & getName() const = 0;
			virtual void		equip(AMateria* m) = 0;
			virtual void		unequip(int idx) = 0;
			virtual void		use(int idx, ICharacter& target) = 0;
	};

#endif
