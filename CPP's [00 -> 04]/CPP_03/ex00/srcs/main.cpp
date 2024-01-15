/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:59:03 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/31 13:56:22 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	
	ClapTrap	firstOne("Titouan");
	ClapTrap	firstOneClone(firstOne);
	
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	
	for (int i = 0; i < 10; i++)
		firstOneClone.attack("Pierre");
	firstOneClone.attack("Pierre");

	std::cout << "-----------------------------------------------------------------------------" << std::endl;

	ClapTrap	anotherOne("Victor");

	for (int i = 0; i < 5; i++)
		anotherOne.takeDamage(2);	
	anotherOne.takeDamage(2);	
	
	std::cout << "-----------------------------------------------------------------------------" << std::endl;

	ClapTrap	theLastOne("Nicolas");

	theLastOne.beRepaired(42);
	theLastOne.takeDamage(42);
	
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	return (0);
}