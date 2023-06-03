/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:30:59 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/04 00:12:51 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"

bool	g_logs;


void	subjectMain(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter	*bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
}

void	myMain(void)
{
	g_logs = true;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	(void) me;
	AMateria	*tmpIce;
	(void) tmpIce;

	std::cout << IBLUE "Mettre successivement 8 objets différents dans inventory[0] " NC << std::endl;
	std::cout << IBLUE "Attendu: 16/16 " NC << std::endl << std::endl;
	for (int i = 0; i < 8; i++)
	{
		tmpIce = src->createMateria("ice");
		me->equip(tmpIce);
		me->unequip(0);
		std::cout << std::endl;
	}
	
	std::cout << IBLUE "Ré-équipper et déséquipper 8 fois de suite le même objet dans inventory[0] " NC << std::endl;
	std::cout << IBLUE "Attendu: 16/16 " NC << std::endl << std::endl;
	for (int i = 0; i < 8; i++)
	{
		me->equip(tmpIce);
		me->unequip(0);
		std::cout << std::endl;
	}

	std::cout << IBLUE "Équipper davantage de materiaux qu'il n'y a de place dans inventory[] " NC << std::endl;
	std::cout << IBLUE "Attendu: 4/8 " NC << std::endl << std::endl;
	for (int i = 0; i < 8; i++)
	{
		tmpIce = src->createMateria("ice");
		me->equip(tmpIce);
		std::cout << std::endl;
	}

	ICharacter* someoneElse = new Character("someoneElse");
	AMateria	*tmpCure;

	std::cout << IBLUE "Mettre successivement 8 objets différents dans inventory[0] " NC << std::endl;
	std::cout << IBLUE "Attendu: 16/16 " NC << std::endl << std::endl;
	for (int i = 0; i < 8; i++)
	{
		tmpCure = src->createMateria("cure");
		someoneElse->equip(tmpCure);
		someoneElse->unequip(0);
		std::cout << std::endl;
	}
	
	std::cout << IBLUE "Ré-équipper et déséquipper 8 fois de suite le même objet dans inventory[0] " NC << std::endl;
	std::cout << IBLUE "Attendu: 16/16 " NC << std::endl << std::endl;
	for (int i = 0; i < 8; i++)
	{
		someoneElse->equip(tmpCure);
		someoneElse->unequip(0);
		std::cout << std::endl;
	}

	std::cout << IBLUE "Équipper davantage de materiaux qu'il n'y a de place dans inventory[] " NC << std::endl;
	std::cout << IBLUE "Attendu: 4/8 " NC << std::endl << std::endl;
	for (int i = 0; i < 8; i++)
	{
		tmpCure = src->createMateria("cure");
		someoneElse->equip(tmpCure);
		std::cout << std::endl;
	}

	std::cout << IBLUE "Vider les inventaires" NC << std::endl;
	std::cout << IBLUE "Attendu: 8/12 " NC << std::endl << std::endl;
	for (int i = -1; i < 5; i++)
	{
		me->unequip(i);
		someoneElse->unequip(i);
		std::cout << std::endl;
	}
	

	std::cout << IBLUE "Tenter d'assigner le même objet à deux personnes." NC << std::endl;
	std::cout << IBLUE "Attendu: 1/2 " NC << std::endl << std::endl;

	tmpCure = src->createMateria("cure");
	me->equip(tmpCure);
	std::cout << std::endl;
	someoneElse->equip(tmpCure);
	std::cout << std::endl;

	std::cout << IBLUE "Reposer un item au sol. Laisser une autre personne le ramasser." NC << std::endl;
	std::cout << IBLUE "Attendu: 2/2 " NC << std::endl << std::endl;

	me->unequip(0);
	std::cout << std::endl;
	someoneElse->equip(tmpCure);
	std::cout << std::endl;

	std::cout << IBLUE "Kick une personne. Laisser une autre personne ramasser un de ses objets." NC << std::endl;
	std::cout << IBLUE "Attendu: 1/1 " NC << std::endl << std::endl;

	delete someoneElse;
	me->equip(tmpCure);
	std::cout << std::endl;

	std::cout << IBLUE "Fin du programme, tous les objets font être lachés au sol puis supprimés." NC << std::endl << std::endl;
	
	delete me;
	delete src;
}

int main()
{
	g_logs = false;

	std::cout << "---> Main from the subject" << std::endl;
	subjectMain();
	std::cout << std::endl;

	std::cout << "---> Additional tests" << std::endl;
	myMain();
	
	return (0);
}
