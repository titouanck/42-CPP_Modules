/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:34:16 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 19:01:24 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
	#define ANIMAL_HPP

	#include <iostream>
	#include <string>

	class Animal
	{
		protected:
			std::string	_type;

		public:
			Animal(void);
			Animal(std::string type);
			Animal(const Animal &src);
			virtual ~Animal();
			Animal	&operator=(const Animal &src);
			
			std::string		getType(void) const;
			virtual void	makeSound(void) const = 0;
			virtual void	newIdea(std::string idea) = 0;
	};

#endif
