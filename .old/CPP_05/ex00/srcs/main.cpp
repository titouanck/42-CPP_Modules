/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:59:05 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/04 14:22:48 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "\n>> Let's try to create a bureaucrat with a grade out of range\n..." << std::endl;
	try
	{
		Bureaucrat	someBureaucrat("someBureaucrat", -42);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n>> Let's try again with a grade inside the range\n..." << std::endl;
	try
	{
		Bureaucrat	someBureaucrat("someBureaucrat", 150);

		std::cout << "\nI've heard there's a new bureaucrat in the area, who is it?" << std::endl;
		std::cout << someBureaucrat << std::endl;

		std::cout << "\n>> Let's try to demote him\n..." << std::endl;
		try
		{
			someBureaucrat.demote();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << "\n>> Let's try to promote him to lvl 1\n..." << std::endl;
		while (someBureaucrat.getGrade() > 1)
		{
			try
			{
				someBureaucrat.promote();
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << "\n>> Let's try to promote him one last time\n..." << std::endl;
		try
		{
			someBureaucrat.promote();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
}
