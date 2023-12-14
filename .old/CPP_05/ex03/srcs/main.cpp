/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:59:05 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/05 00:08:14 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Bureaucrat	lvl150("Some bureaucrat lvl 150", 150);
Bureaucrat	lvl42("Some bureaucrat lvl 42", 42);
Bureaucrat	lvl1("Some bureaucrat lvl 1", 1);

void	ShrubberyCreationMain(void)
{
	Intern	someRandomIntern;
	Form* 	rrf;
	
	rrf = someRandomIntern.makeForm("shrubbery creation", "garden");
	if (!rrf)
		return ;

	try
	{
		rrf->execute(lvl1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	lvl1.executeForm(*rrf);
	std::cout << std::endl;

	try
	{
		rrf->beSigned(lvl150);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	lvl150.signForm(*rrf);
	std::cout << std::endl;

	lvl42.signForm(*rrf);
	lvl42.executeForm(*rrf);

	delete rrf;
}

void	RobotomyRequestMain(void)
{
	Intern	someRandomIntern;
	Form* 	rrf;
	
	rrf = someRandomIntern.makeForm("robotomy request", "some guy");
	if (!rrf)
		return ;
	try
	{
		rrf->execute(lvl1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	lvl1.executeForm(*rrf);
	std::cout << std::endl;

	try
	{
		rrf->beSigned(lvl150);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	lvl150.signForm(*rrf);
	std::cout << std::endl;

	lvl42.signForm(*rrf);
	lvl42.executeForm(*rrf);

	delete rrf;
}

void	PresidentialPardonMain(void)
{
	Intern	someRandomIntern;
	Form* 	rrf;

	rrf = someRandomIntern.makeForm("presidential pardon", "some girl");
	if (!rrf)
		return ;

	try
	{
		rrf->execute(lvl1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	lvl1.executeForm(*rrf);
	std::cout << std::endl;

	try
	{
		rrf->beSigned(lvl42);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	lvl42.signForm(*rrf);
	std::cout << std::endl;

	lvl1.signForm(*rrf);
	lvl1.executeForm(*rrf);

	delete rrf;
}

int	main(void)
{	
	std::cout << "---" << std::endl;

	ShrubberyCreationMain();

	std::cout << "---" << std::endl;

	RobotomyRequestMain();

	std::cout << "---" << std::endl;

	PresidentialPardonMain();

	std::cout << "---" << std::endl;

	Intern	someRandomIntern;
	Form* 	rrf;

	rrf = someRandomIntern.makeForm("non-existing form", "someone");
	if (rrf)
		delete rrf;

	std::cout << "---" << std::endl;
	
}
