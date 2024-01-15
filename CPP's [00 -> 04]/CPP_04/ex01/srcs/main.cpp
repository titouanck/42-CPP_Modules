/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:30:59 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 18:55:22 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define TAB_SIZE 4

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}

	std::cout << "---" << std::endl;

	Animal	*animalTab[TAB_SIZE];

	// On remplit la moitie du tableau avec des Dog
	for (int i = 0; i < (TAB_SIZE / 2); i++)
		animalTab[i] = new Dog();

	std::cout << "---" << std::endl;

	// On remplit la moitie du tableau avec des Cat
	for (int i = TAB_SIZE / 2; i < TAB_SIZE; i++)
		animalTab[i] = new Cat();

	std::cout << "---" << std::endl;

	/* On va verifier que tous les Cat et Dog sont des copies profondes, 
	en s'assurant qu'ils possedent leurs propres consciences */
	{
		// D'abord en comparant les idees de deux Dog du tableau
		animalTab[0]->newIdea("I don't think our fellow cats are bad people. We should protect them.");
		animalTab[1]->newIdea("Cats are inherently bad, and if they have problems, we shouldn't intervene.");
		animalTab[0]->makeSound();
		animalTab[1]->makeSound();
		std::cout << "<main> Two dogs, two beasts, two opposing opinions, definitely not the same brain here and there.. <main>" << std::endl;

		std::cout << "---" << std::endl;
		
		// Puis en comparant les idees de deux chats tout fraichements crees, dont l'un a partir de l'autre
		Cat	firstOne;
		Cat	secondOne(firstOne);

		std::cout << "---" << std::endl;

		firstOne.newIdea("I don't think our fellow dogs are bad people. We should protect them.");
		secondOne.newIdea("Dogs are inherently bad, and if they have problems, we shouldn't intervene.");
		firstOne.makeSound();
		secondOne.makeSound();
		std::cout << "<main> Two cats, two beasts, two opposing opinions, definitely not the same brain here and there.. <main>" << std::endl;
		
		std::cout << "---" << std::endl;

		firstOne = secondOne;
		firstOne.makeSound();
		secondOne.makeSound();
		std::cout << "<main> In the end they agreed on a speech of hate. <main>" << std::endl;
		
		std::cout << "---" << std::endl;
	}
	std::cout << "---" << std::endl;

	// On delete chaque element du tableau pour eviter les leaks
	for (int i = 0; i < TAB_SIZE; i++)
		delete (Animal *) animalTab[i];
}
