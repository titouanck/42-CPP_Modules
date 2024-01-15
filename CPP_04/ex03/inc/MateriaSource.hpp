/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:29:10 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/03 18:20:51 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
	#define MATERIASOURCE_HPP

	#include "IMateriaSource.hpp"

	class MateriaSource : public IMateriaSource
	{
		protected:
			AMateria	*_materias[4];

		public:
			MateriaSource(void);
			MateriaSource(const MateriaSource &obj);
			~MateriaSource(void);
			MateriaSource	&operator=(const MateriaSource &obj);

			void 		learnMateria(AMateria*);
			AMateria	*createMateria(std::string const & type);
	};

#endif
