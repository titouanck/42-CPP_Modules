/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:55:07 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/04 22:38:14 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : Form("Presidential Pardon", 25, 5, obj._target)
{
	*this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	(void)	obj;

	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	try {
		_readyToExecute(executor);
	}
	catch (std::exception &e) {
		throw;
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
