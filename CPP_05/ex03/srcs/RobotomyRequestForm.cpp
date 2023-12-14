/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:02:16 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/13 20:22:50 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include  <cstdlib>
#include <sys/time.h>

/* ************************************************************************** */

bool RobotomyRequestForm::_srandInit = false;

/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45, target)
{
}

/* ************************************************************************** */

AForm	*RobotomyRequestForm::createInstance(std::string target)
{
	RobotomyRequestForm	*form;
	
	form = new RobotomyRequestForm(target);
	return form;
}

bool	RobotomyRequestForm::executeForm(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		std::cout << executor.getName() << " couldn’t execute " << this->getName() << " because he is too low in the hierarchy" << std::endl;
	else
	{
		if (this->_srandInit == false)
		{
			struct timeval tp;
			gettimeofday(&tp, NULL);
			srand(tp.tv_usec);
			_srandInit = true;
		}
		if (rand() % 2)
		{
			std::cout << this->getTarget() << " has been robotomized" << std::endl;
			return true;
		}
		std::cout << this->getTarget() << " has NOT been robotomized" << std::endl;
	}
	return false;
}
