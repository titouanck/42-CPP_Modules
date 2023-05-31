/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:59:03 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/31 14:19:50 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	
	ScavTrap	firstOne("Titouan");
	ScavTrap	firstOneClone(firstOne);
	
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	
	for (int i = 0; i < 50; i++)
		firstOneClone.attack("Baptiste");
	firstOneClone.attack("Baptiste");

	std::cout << "-----------------------------------------------------------------------------" << std::endl;

	ScavTrap	anotherOne("Victor");

	for (int i = 0; i < 10; i++)
		anotherOne.takeDamage(10);	
	anotherOne.takeDamage(10);	

	std::cout << "-----------------------------------------------------------------------------" << std::endl;

	ScavTrap	andAnotherOne("Pierre");

	andAnotherOne.guardGate();
	andAnotherOne.guardGate();
	
	std::cout << "-----------------------------------------------------------------------------" << std::endl;

	ScavTrap	theLastOne("Nicolas");

	theLastOne.takeDamage(42);
	for (int i = 0; i < 50; i++)
		theLastOne.beRepaired(42);
	theLastOne.beRepaired(42);
	
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	return (0);
}