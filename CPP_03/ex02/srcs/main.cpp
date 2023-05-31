/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:59:03 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/31 14:37:19 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	
	FragTrap	firstOne("Titouan");
	FragTrap	firstOneClone(firstOne);
	
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	
	for (int i = 0; i < 100; i++)
		firstOneClone.attack("Isaac");
	firstOneClone.attack("Isaac");

	std::cout << "-----------------------------------------------------------------------------" << std::endl;

	FragTrap	anotherOne("Victor");

	for (int i = 0; i < 10; i++)
		anotherOne.takeDamage(10);	
	anotherOne.takeDamage(10);	
	anotherOne.highFivesGuys();

	std::cout << "-----------------------------------------------------------------------------" << std::endl;

	FragTrap	andAnotherOne("Pierre");

	andAnotherOne.highFivesGuys();
	
	std::cout << "-----------------------------------------------------------------------------" << std::endl;

	FragTrap	theLastOne("Nicolas");

	theLastOne.takeDamage(42);
	for (int i = 0; i < 100; i++)
		theLastOne.beRepaired(42);
	theLastOne.beRepaired(42);
	
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	return (0);
}