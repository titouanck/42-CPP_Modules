/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:30:59 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/03 18:58:34 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"

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
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	Character me("me");
	AMateria	*tmp;

	/*
		Création de 8 Materiaux.
		Puis pour chaque matériaux crée:
			On déséquippe le précédent.
			On équipe le nouveau.

		Le but est de vérifier que les anciens materiaux 
		seront biens delete d'ici la fin du programme.
	*/
	for (int i = 0; i < 8; i++)
	{
		tmp = src->createMateria("ice");
		me.unequip(0);
		me.equip(tmp);
	}
	
	std::cout << "--- FOR LOOP ---" << std::endl;

	/*
		On va, 8 fois de suite, déséquiper et rééquiper un materiaux.

		Le but est de vérifier que les materiaux ne seront biens
		delete qu'une seule fois, et non plusieurs.
	*/
	for (int i = 0; i < 8; i++)
	{
		me.unequip(0);
		me.equip(tmp);
	}

	std::cout << "--- FOR LOOP ---" << std::endl;
	
	/*
		On va équipper plus de materiaux (8) qu'il n'y a de place dans
		l'inventaire (4). A partir du 5eme, ce ne devrait plus être possible.
	*/
	me.unequip(0);
	for (int i = 0; i < 8; i++)
		me.equip(tmp);

	// ICharacter	*jim = new Character("jim");
	
	// std::cout << "original:" << std::endl;
	// me.use(0, *jim);
	
	// Character copyMe(me);
	// std::cout << "copy:" << std::endl;
	// copyMe.use(0, *jim);
	
	// /* 
	// 	On va vérifier que <copyMe> n´a rien à utiliser.
	// */
	// copyMe.unequip(0);
	// copyMe.use(0, *jim);
	
	/* 
		On va vérifier que tmp ne pourras pas être équipper 
		par <copyMe> car déjà en cours d'usage par <me>.
	*/
	// copyMe.equip(tmp);

	// delete jim;
	delete src;
}

void victorMain(void)
{
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	ICharacter* meBis = new Character("meBis");
	AMateria* tmp1;
	AMateria* tmp2;

	tmp1 = src->createMateria("ice");
	me->equip(tmp1);

	tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);
	
	meBis->equip(tmp2);
	meBis->use(0, *bob);
	
	delete bob;
	delete me;
	delete meBis;
	delete src;
}

int main()
{
	std::cout << "---" << std::endl;

	// subjectMain();

	std::cout << "---" << std::endl;

	myMain();
	
	std::cout << "---" << std::endl;

	// victorMain();
	
	std::cout << "---" << std::endl;
	
	return (0);
}
