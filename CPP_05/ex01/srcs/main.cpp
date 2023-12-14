/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:53:11 by tchevrie          #+#    #+#             */
/*   Updated: 2023/12/12 22:27:09 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Form	form_1("Form A38");
		std::cout << form_1 << std::endl;
		
		Bureaucrat	bureaucrat("Tico", 2);
		std::cout << bureaucrat << std::endl;
		form_1.beSigned(bureaucrat);
		
		bureaucrat.promote();
		std::cout << bureaucrat << std::endl;
		form_1.beSigned(bureaucrat);

		std::cout << form_1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

/* ************************************************************************** */

	try
	{
		Form	form_4(42, 84);
		std::cout << form_4 << std::endl;

		Bureaucrat bureaucrat("tico", 1);
		bureaucrat.signForm(form_4);
		bureaucrat.signForm(form_4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

/* ************************************************************************** */

	try
	{
		Form	form_4(0, 84);
		std::cout << form_4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

/* ************************************************************************** */

	try
	{
		Form	form_4(42, 151);
		std::cout << form_4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
