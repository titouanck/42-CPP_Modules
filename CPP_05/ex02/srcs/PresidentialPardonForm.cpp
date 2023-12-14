/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:02:51 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/13 17:49:09 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	AForm::operator=(copy);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5, target)
{
}

/* ************************************************************************** */

bool	PresidentialPardonForm::executeForm(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		std::cout << executor.getName() << " couldn’t execute " << this->getName() << " because he is too low in the hierarchy" << std::endl;
	else
	{
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		return true;
	}
	return false;
}
