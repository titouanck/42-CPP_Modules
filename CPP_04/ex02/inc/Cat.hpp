/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:34:56 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 14:18:38 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
	#define CAT_HPP

	#include "Animal.hpp"
	#include "Brain.hpp"

	class Cat : public Animal
	{
		private:
			Brain	*_brain;

		public:
			Cat();
			Cat(const Cat &src);
			~Cat();
			Cat	&operator=(const Cat &src);

			void	makeSound(void) const;
			void	newIdea(std::string idea);
	};

#endif
