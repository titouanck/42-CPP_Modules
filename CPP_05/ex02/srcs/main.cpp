/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:53:11 by tchevrie          #+#    #+#             */
/*   Updated: 2023/12/13 17:32:29 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */

int	main(void)
{
	int x = 0;

	std::cout << "" << ++x << ") /* ************************************************************************** */\n" << std::endl;
	try
	{
		ShrubberyCreationForm	shrubberyCreation;
		RobotomyRequestForm		robotomyRequest;
		PresidentialPardonForm	presidentialPardon;

		std::cout << shrubberyCreation << std::endl;
		std::cout << robotomyRequest << std::endl;
		std::cout << presidentialPardon << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n" << ++x << ") /* ************************************************************************** */\n" << std::endl;

	try
	{
		ShrubberyCreationForm	shrubberyCreation("tic");
		RobotomyRequestForm		robotomyRequest("tac");
		PresidentialPardonForm	presidentialPardon("toc");

		std::cout << shrubberyCreation << std::endl;
		std::cout << robotomyRequest << std::endl;
		std::cout << presidentialPardon << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\n" << ++x << ") /* ************************************************************************** */\n" << std::endl;

	try
	{
		ShrubberyCreationForm	shrubberyCreation("nicolas' home");
		RobotomyRequestForm		robotomyRequest("nicolas' brain");
		PresidentialPardonForm	presidentialPardon("nicolas");

		Bureaucrat boss("BOSS", 1);
		Bureaucrat intern("intern", 150);

		shrubberyCreation.beSigned(intern);
		robotomyRequest.beSigned(intern);
		presidentialPardon.beSigned(intern);

		std::cout << "\n" << ++x << ") /* ************************************************************************** */\n" << std::endl;

		shrubberyCreation.beSigned(boss);
		robotomyRequest.beSigned(boss);
		presidentialPardon.beSigned(boss);
	
		std::cout << std::endl;
	
		shrubberyCreation.beSigned(boss);
		robotomyRequest.beSigned(boss);
		presidentialPardon.beSigned(boss);

		std::cout << "\n" << ++x << ") /* ************************************************************************** */\n" << std::endl;
	
		shrubberyCreation.execute(intern);
		robotomyRequest.execute(intern);
		presidentialPardon.execute(intern);

		std::cout << std::endl;
	
		shrubberyCreation.execute(boss);
		robotomyRequest.execute(boss);
		presidentialPardon.execute(boss);

		std::cout << std::endl;
	
		boss.executeForm(shrubberyCreation);
		boss.executeForm(robotomyRequest);
		boss.executeForm(presidentialPardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
