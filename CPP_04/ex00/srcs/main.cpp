/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:30:59 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 01:51:59 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << "---" << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound(); // will output the dog sound!
	meta->makeSound();

	std::cout << "---" << std::endl;

	delete meta; delete j, delete i;

	std::cout << "---" << std::endl;

	const WrongAnimal	*wrongAngryAnimal = new WrongAnimal();
	const WrongAnimal	*wrongAngryCat = new WrongCat();

	std::cout << "---" << std::endl;

	std::cout << wrongAngryCat->getType() << " " << std::endl;
	wrongAngryAnimal->makeSound();
	wrongAngryCat->makeSound();

	std::cout << "---" << std::endl;

	delete wrongAngryAnimal; delete wrongAngryCat;
}
