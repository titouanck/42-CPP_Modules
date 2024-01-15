/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:28:48 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/03 23:36:44 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
	#define CHARACTER_HPP

	#include "ICharacter.hpp"

	#define RED "\033[0;31m"
	#define GREEN "\033[0;32m"
	#define BGREEN "\033[37;42m"
	#define BRED "\033[37;41m"
	#define BLUE "\033[0;34m"
	#define NC "\033[0m"
	#define IBLUE "\033[39;44;3m"

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
			void		_lstUnequip(AMateria *addr);
			void		_lstEquip(AMateria *addr);
			bool		_isEquipped(AMateria *addr);
			bool		_isUnequipped(AMateria *addr);

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
