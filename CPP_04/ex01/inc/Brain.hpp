/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:37:57 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/02 14:14:25 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
	#define BRAIN_HPP

	#include <iostream>
	#include <string>

	class Brain
	{
		private:
			std::string	_ideas[100];	

		public:
			Brain(void);
			Brain(const Brain &src);
			~Brain(void);
			Brain	&operator=(const Brain &src);

			void		defIdea(std::string str, unsigned int idx);
			std::string	getIdea(unsigned int idx);
	};

#endif
