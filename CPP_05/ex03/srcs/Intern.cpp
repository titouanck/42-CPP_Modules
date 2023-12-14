/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:54:31 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/13 20:28:07 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
}	

Intern	&Intern::operator=(const Intern &copy)
{
	(void) copy;
	return *this;
}

Intern::~Intern()
{
}

/* ************************************************************************** */

AForm	*Intern::makeForm(std::string name, std::string target)
{
	const std::string	forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm				*(*selectInstance[])(std::string) = {&ShrubberyCreationForm::createInstance, &RobotomyRequestForm::createInstance, &PresidentialPardonForm::createInstance};
	AForm				*form;
	int					i;

	i = 0;
	while (i < 3)
	{
		if (name.compare(forms[i]) == 0)
		{
			form = selectInstance[i](target);
			if (form)
			{
				std::cout << "Intern creates " << name << std::endl;
				return form;
			}
			else
				break ;
		}
		i++;
	}
	std::cout << "Intern could not create " << name << std::endl;
	return (NULL);
}
