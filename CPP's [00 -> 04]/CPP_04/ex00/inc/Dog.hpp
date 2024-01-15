/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:34:56 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 01:33:41 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
	#define DOG_HPP

	#include "Animal.hpp"

	class Dog : public Animal
	{
		public:
			Dog();
			Dog(const Dog &src);
			~Dog();
			Dog	&operator=(const Dog &src);

			void	makeSound(void) const;
	};

#endif
