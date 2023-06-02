/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:34:56 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 14:19:24 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
	#define DOG_HPP

	#include "Animal.hpp"
	#include "Brain.hpp"

	class Dog : public Animal
	{
		private:
			Brain	*_brain;
		
		public:
			Dog();
			Dog(const Dog &src);
			~Dog();
			Dog	&operator=(const Dog &src);

			void	makeSound(void) const;
			void	newIdea(std::string idea);
	};

#endif
