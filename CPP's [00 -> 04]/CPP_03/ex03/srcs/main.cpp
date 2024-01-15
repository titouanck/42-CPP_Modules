/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:59:03 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/31 15:42:03 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	
	DiamondTrap	firstOne("Titouan");
	DiamondTrap	firstOneClone(firstOne);
	
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	
	for (int i = 0; i < 50; i++)
		firstOneClone.attack("Isaac");
	firstOneClone.attack("Isaac");
	firstOneClone.whoAmI();

	std::cout << "-----------------------------------------------------------------------------" << std::endl;

	DiamondTrap	anotherOne("Victor");

	for (int i = 0; i < 10; i++)
		anotherOne.takeDamage(10);	
	anotherOne.takeDamage(10);	
	anotherOne.highFivesGuys();
	anotherOne.whoAmI();

	std::cout << "-----------------------------------------------------------------------------" << std::endl;

	DiamondTrap	andAnotherOne("Pierre");

	andAnotherOne.whoAmI();
	
	std::cout << "-----------------------------------------------------------------------------" << std::endl;

	DiamondTrap	theLastOne("Nicolas");

	theLastOne.takeDamage(42);
	for (int i = 0; i < 50; i++)
		theLastOne.beRepaired(42);
	theLastOne.beRepaired(42);
	theLastOne.whoAmI();
	
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	return (0);
}