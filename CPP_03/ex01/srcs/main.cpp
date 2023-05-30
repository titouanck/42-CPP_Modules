/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:59:03 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/30 18:48:34 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	t("Titouan");
	ClapTrap	v("Victor");
	ClapTrap	n("Nico");
	ClapTrap	p("Pierre");

	t.attack("Victor");

	v.takeDamage(0);
	
	n.takeDamage(9);
	n.beRepaired(5);
	n.takeDamage(9);
	n.beRepaired(5);
	n.attack("Titouan");
	
	p.beRepaired(200);
	p.beRepaired(200);
	p.beRepaired(200);
	p.beRepaired(200);
	p.beRepaired(200);
	p.beRepaired(200);
	p.beRepaired(200);
	p.beRepaired(200);
	p.beRepaired(200);
	p.beRepaired(200);
	p.beRepaired(200);
	
	return (0);
}