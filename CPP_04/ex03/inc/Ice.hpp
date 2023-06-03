/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:45:33 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/03 15:17:10 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
	#define ICE_HPP

	#include "AMateria.hpp"
	#include "ICharacter.hpp"

	class Ice : public AMateria
	{
		public:
			Ice(void);
			Ice(const Ice &obj);
			~Ice(void);
			Ice	&operator=(const Ice &obj);
			
			void 		use(ICharacter& target);
			AMateria	*clone() const;
	};

#endif
