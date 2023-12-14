/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:16:51 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/05 18:26:50 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{}

Intern::Intern(const Intern &obj)
{
	*this = obj;
}

Intern::~Intern(void)
{}

Intern	&Intern::operator=(const Intern &obj)
{
	(void)	obj;
	return (*this);
}

Form	*Intern::makeForm(std::string type, std::string target)
{
	std::string	forms[] 							= {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form		*(*selectInstance[])(std::string)	= {&ShrubberyCreationForm::createInstance, &RobotomyRequestForm::createInstance, &PresidentialPardonForm::createInstance};
	Form		*formObj;
	size_t		i;
	size_t		tabSize;

	tabSize = sizeof(selectInstance) / sizeof(selectInstance[0]);
	i = 0;
	while (i < tabSize)
	{
		if (forms[i] == type)
		{
			formObj = selectInstance[i](target);
			if (formObj)
				return (std::cout << "Intern creates " << type << std::endl, formObj);
			else
				break ;
		}
		i++;
	}
	std::cout << "Intern could not create " << type << std::endl;
	return (0);
}
