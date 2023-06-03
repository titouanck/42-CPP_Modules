/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:45:50 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/03 15:48:17 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
	#define CURE_HPP

	#include "AMateria.hpp"
	#include "ICharacter.hpp"
	
	class Cure : public AMateria
	{
		public:
			Cure(void);
			Cure(const Cure &obj);
			~Cure(void);
			Cure	&operator=(const Cure &obj);
			
			void 		use(ICharacter& target);
			AMateria	*clone() const;
	};


#endif
