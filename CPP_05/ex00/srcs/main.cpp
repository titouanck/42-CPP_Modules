/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:53:11 by tchevrie          #+#    #+#             */
/*   Updated: 2023/12/12 20:36:23 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	bureaucrat(149);

		std::cout << bureaucrat << std::endl;
		bureaucrat.demote();
		std::cout << bureaucrat << std::endl;
		bureaucrat.demote();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << '\n';
	}

/* ************************************************************************** */
	
	try
	{
		Bureaucrat	bureaucrat(2);

		std::cout << bureaucrat << std::endl;
		bureaucrat.promote();
		std::cout << bureaucrat << std::endl;
		bureaucrat.promote();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << '\n';
	}

/* ************************************************************************** */

	try
	{
		Bureaucrat	bureaucrat(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	bureaucrat(151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
