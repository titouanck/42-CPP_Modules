/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:54:29 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/04 16:54:14 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : Form("Robotomy Request", 72, 45, obj._target)
{
	*this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	(void)	obj;

	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	time_t		rawTime;

	try
	{
		_readyToExecute(executor);
	}
	catch (std::exception &e)
	{
		throw;
	}
	
	std::cout << "* Vvvvvvrrrrrrrrrrrrrrrrr... *" << std::endl;
	rawTime = time(&rawTime);
	if (rawTime % 2)
		std::cout << _target << " could not be robotomised :(" << std::endl;
	else
		std::cout << _target << " has been successfully robotomised :)" << std::endl;
}
