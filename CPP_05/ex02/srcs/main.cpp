/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:59:05 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/04 17:17:57 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Bureaucrat	lvl150("Some bureaucrat lvl 150", 150);
Bureaucrat	lvl42("Some bureaucrat lvl 42", 42);
Bureaucrat	lvl1("Some bureaucrat lvl 1", 1);

void	RobotomyRequestMain(void)
{
	RobotomyRequestForm robotomyRequestFormObj("Some guy");

	try
	{
		robotomyRequestFormObj.execute(lvl1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	lvl1.executeForm(robotomyRequestFormObj);
	std::cout << std::endl;

	try
	{
		robotomyRequestFormObj.beSigned(lvl150);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	lvl150.signForm(robotomyRequestFormObj);
	std::cout << std::endl;

	lvl42.signForm(robotomyRequestFormObj);
	lvl42.executeForm(robotomyRequestFormObj);
}

void	PresidentialPardonMain(void)
{
	PresidentialPardonForm presidentialPardonFormObj("Some girl");

	try
	{
		presidentialPardonFormObj.execute(lvl1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	lvl1.executeForm(presidentialPardonFormObj);
	std::cout << std::endl;

	try
	{
		presidentialPardonFormObj.beSigned(lvl42);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	lvl42.signForm(presidentialPardonFormObj);
	std::cout << std::endl;

	lvl1.signForm(presidentialPardonFormObj);
	lvl1.executeForm(presidentialPardonFormObj);
}

int	main(void)
{	
	std::cout << "---" << std::endl;

	RobotomyRequestMain();

	std::cout << "---" << std::endl;

	PresidentialPardonMain();

	std::cout << "---" << std::endl;
}
