/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:28:48 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/03 19:04:04 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
	#define CHARACTER_HPP

	#include "ICharacter.hpp"

	typedef struct s_address
	{
		void				*addr;
		struct s_address	*next;
	}						t_address;

	class Character : public ICharacter
	{
		private:
			Character(void) {}

			static unsigned int	_nbObjs;
			static t_address	_unequipped;
			static t_address	_equipped;

			std::string	_name;
			AMateria	*_inventory[4];
			void		lstAddUnequipped(AMateria *addr);
			void		lstAddEquipped(AMateria *addr);

		public:
			Character(std::string name);
			Character(const Character &obj);
			~Character(void);
			Character	&operator=(const Character &obj);
			
			std::string const	&getName() const;
			void				equip(AMateria* m);
			void				unequip(int idx);
			void				use(int idx, ICharacter& target);
	};

#endif
