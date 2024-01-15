/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:34:56 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 01:42:12 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
	#define CAT_HPP

	#include "Animal.hpp"

	class Cat : public Animal
	{
		public:
			Cat();
			Cat(const Cat &src);
			~Cat();
			Cat	&operator=(const Cat &src);

			void	makeSound(void) const;
	};

#endif
