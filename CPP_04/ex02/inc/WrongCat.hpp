/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:34:56 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 01:33:36 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
	#define WRONGCAT_HPP

	#include "WrongAnimal.hpp"

	class WrongCat : public WrongAnimal
	{
		public:
			WrongCat();
			WrongCat(const WrongCat &src);
			~WrongCat();
			WrongCat	&operator=(const WrongCat &src);

			void	makeSound(void) const;
	};

#endif
