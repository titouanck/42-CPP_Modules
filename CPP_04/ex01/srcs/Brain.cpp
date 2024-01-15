/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:38:35 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/02 14:16:04 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Constructor: New brain." << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Constructor: New brain, following in the footsteps of another." << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Destructor: The world loses a brain." << std::endl;
}

Brain	&Brain::operator=(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];

	return (*this);
}

void	Brain::defIdea(std::string str, unsigned int idx)
{
	if (idx >= 100)
		return ;

	this->_ideas[idx] = str;
}


std::string	Brain::getIdea(unsigned int idx)
{
	if (idx >= 100)
		return ("");

	return (this->_ideas[idx]);
}
