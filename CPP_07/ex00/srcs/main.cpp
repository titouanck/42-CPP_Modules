/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:38:04 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/20 14:35:43 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void mainFromSubject(void);
void myMain(void);

/* ************************************************************************** */

int	main(void)
{
	std::cout << "--- Main from subject ---" << std::endl << std::endl;
	mainFromSubject();
	
	std::cout << std::endl << "--- My main ---" << std::endl << std::endl;
	myMain();
}

/* ************************************************************************** */

void mainFromSubject(void)
{
	int a = 2;
	int b = 3;
	
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
}

/* ************************************************************************** */

void	myMain(void)
{
	std::cout << "/* SWAP *************************************************** */" << std::endl << std::endl;

	std::string	player_1;
	std::string	player_2;

	player_1 = "Podasai";
	player_2 = "Snayzy";
	
	std::cout << "Before swap: " \
	<< player_1 << " & " << player_2 << std::endl;

	swap(player_1, player_2);

	std::cout << "After swap:  " \
	<< player_1 << " & " << player_2 << std::endl;

	std::cout << std::endl << "/* MIN **************************************************** */" << std::endl << std::endl;

	char	a;
	char	b;
	void	*r1;
	
	/* a is the lowest ******************************************* */
	
	a = '2';
	b = '4';

	r1 = &min(a, b);
	std::cout << "min(a = 2, b = 4): " \
	<< (r1 == &a ? "a" : "") << (r1 == &b ? "b" : "") << std::endl;

	/* b is the lowest ******************************************* */
	
	a = '4';
	b = '2';
	
	r1 = &min(a, b);
	std::cout << "min(a = 4, b = 2): " \
	<< (r1 == &a ? "a" : "") << (r1 == &b ? "b" : "") << std::endl;

	/* a == b **************************************************** */
	
	a = '0';
	b = '0';
	
	r1 = &min(a, b);
	std::cout << "min(a = 0, b = 0): " \
	<< (r1 == &a ? "a" : "") << (r1 == &b ? "b" : "") << std::endl;
	
	std::cout << std::endl << "/* MAX **************************************************** */" << std::endl << std::endl;

	char	c;
	char	d;
	void	*r2;
	
	/* a is the highest ****************************************** */
	
	c = '4';
	d = '2';

	r2 = &max(c, d);
	std::cout << "max(c = 4, d = 2): " \
	<< (r2 == &c ? "c" : "") << (r2 == &d ? "d" : "") << std::endl;

	/* b is the highest ****************************************** */
	
	c = '2';
	d = '4';
	
	r2 = &max(c, d);
	std::cout << "max(c = 2, d = 4): " \
	<< (r2 == &c ? "c" : "") << (r2 == &d ? "d" : "") << std::endl;

	/* c == b **************************************************** */
	
	c = '0';
	d = '0';
	
	r2 = &max(c, d);
	std::cout << "max(c = 0, d = 0): " \
	<< (r2 == &c ? "c" : "") << (r2 == &d ? "d" : "") << std::endl;
}

/* ************************************************************************** */
