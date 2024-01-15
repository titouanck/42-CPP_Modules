/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:34:16 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 01:38:16 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
	#define WRONGANIMAL_HPP

	#include <iostream>
	#include <string>

	class WrongAnimal
	{
		protected:
			std::string	_type;

		public:
			WrongAnimal(void);
			WrongAnimal(std::string type);
			WrongAnimal(const WrongAnimal &src);
			virtual ~WrongAnimal();
			WrongAnimal	&operator=(const WrongAnimal &src);
			
			std::string		getType(void) const;
			virtual void	makeSound(void) const;
	};

#endif
