/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:59:05 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/04 16:54:57 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	lvl150("some bureaucrat lvl 150", 150);
	Bureaucrat	lvl42("some bureaucrat lvl 42", 42);
	Bureaucrat	lvl1("some bureaucrat lvl 1", 1);
	
	Form		someForm("3916 - 3916 bis", 42, 142);

	std:: cout << someForm << std::endl;
	std::cout << std::endl;

	lvl150.signForm(someForm);
	std::cout << std::endl;

	lvl42.signForm(someForm);
	std::cout << std::endl;

	lvl1.signForm(someForm);
	std::cout << std::endl;

	try
	{
		someForm.beSigned(lvl1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
