/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:35:30 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/03 18:03:35 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
	#define AMATERIA_HPP

	#include <iostream>
	#include <string>

	class ICharacter;

	class AMateria
	{
		private:
			AMateria(void) {}

		protected:
			std::string	_type;

		public:
			AMateria(std::string const & type);
			AMateria(const AMateria &obj);
			virtual ~AMateria(void);
			AMateria	&operator=(const AMateria &obj);
			
			std::string const 	&getType() const;
			virtual AMateria* 	clone() const = 0;
			virtual void 		use(ICharacter& target);

	};

#endif
