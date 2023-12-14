/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:53:11 by tchevrie          #+#    #+#             */
/*   Updated: 2023/12/13 20:33:55 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */

int	main(void)
{
	Intern	someRandomIntern;

	AForm *firstForm = someRandomIntern.makeForm("shrubbery creation", "Bender's garden");
	if (firstForm)
		std::cout << *firstForm << std::endl;

	std::cout << std::endl;

	AForm *secondForm = someRandomIntern.makeForm("robotomy request", "Bender's brain");
	if (secondForm)
		std::cout << *secondForm << std::endl;

	std::cout << std::endl;

	AForm *thirdForm = someRandomIntern.makeForm("presidential pardon", "Bender");
	if (thirdForm)
		std::cout << *thirdForm << std::endl;

	std::cout << std::endl;

	AForm *fourthForm = someRandomIntern.makeForm("A38", "some target");
	if (fourthForm)
		std::cout << *fourthForm << std::endl;
}
