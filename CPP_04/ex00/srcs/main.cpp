/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:30:59 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/02 01:48:14 by tchevrie         ###   ########.fr       */
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

	const WrongAnimal	*wrongOne = new WrongCat();

	std::cout << "---" << std::endl;

	std::cout << wrongOne->getType() << " " << std::endl;
	wrongOne->makeSound();

	std::cout << "---" << std::endl;

	delete wrongOne;
}
