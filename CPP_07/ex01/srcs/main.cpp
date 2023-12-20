/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:37:39 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/20 15:13:32 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	printString(std::string str);
void	printInt(int nbr);
void	printChar(char c);
void	printFloat(float flt);

template <typename T>
void	print(T toPrint);

/* ************************************************************************** */

int	main(void)
{
	std::string	tabStr[]	= {"Podasai", "Snayzy"};
	int			tabNbr[]	= {29, 9};
	char		tabChar[]	= {'#', 'M', '8', 'W', 'I', 'N'};
	float		tabFlt[]	= {29.0f, 9.0f};
	
	std::cout << "/* ********************** */"<< std::endl << std::endl;

	iter(tabStr, sizeof(tabStr) / sizeof(tabStr[0]), printString);
	std::cout << std::endl << std::endl;
	
	iter(tabNbr, sizeof(tabNbr) / sizeof(tabNbr[0]), printInt);
	std::cout << std::endl << std::endl;

	iter(tabChar, sizeof(tabChar) / sizeof(tabChar[0]), printChar);
	std::cout << std::endl << std::endl;

	iter(tabFlt, sizeof(tabFlt) / sizeof(tabFlt[0]), printFloat);
	std::cout << std::endl;
	
	std::cout << std::endl << "/* ********************** */"<< std::endl << std::endl;

	iter(tabStr, sizeof(tabStr) / sizeof(tabStr[0]), print);
	std::cout << std::endl << std::endl;
	
	iter(tabNbr, sizeof(tabNbr) / sizeof(tabNbr[0]), print);
	std::cout << std::endl << std::endl;

	iter(tabChar, sizeof(tabChar) / sizeof(tabChar[0]), print);
	std::cout << std::endl << std::endl;

	iter(tabFlt, sizeof(tabFlt) / sizeof(tabFlt[0]), print);
	std::cout << std::endl;

	std::cout << std::endl << "/* ********************** */"<< std::endl;
}

/* ************************************************************************** */

void	printString(std::string str)
{
	std::cout << str << ", ";
}

void	printInt(int nbr)
{
	std::cout << nbr << ", ";
}

void	printChar(char c)
{
	std::cout << c << ", ";
}

void	printFloat(float flt)
{
	std::cout << flt << ", ";
}

/* ************************************************************************** */

template <typename T>
void	print(T toPrint)
{
	std::cout << toPrint << ", ";
}

/* ************************************************************************** */
