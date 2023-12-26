/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:21:43 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/26 11:54:04 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define BLUE "\033[34m"
#define ITALIC "\033[3m"
#define NC "\033[0m"

/* ************************************************************************** */

int	main(void)
{
	std::cout << BLUE "/* Construction with no parameter: Creates an empty array. */\n" NC << std::endl;
	
	Array<int>	emptyArray;
	
	std::cout << "emptyArray.size() = " << emptyArray.size() << std::endl;

	/* ********************************************************************** */

	std::cout << BLUE "\n/* Construction with an unsigned int n as a parameter: " \
	<< "Creates an array of n elements initialized by default */\n" NC << std::endl;
	
	Array<int>	filledArray(42);
	
	std::cout << "filledArray.size() = " << filledArray.size() << std::endl;
	std::cout << "{";
	for (unsigned int i = 0; i < filledArray.size(); i++)
	{
		std::cout << filledArray[i];
		if (i < filledArray.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;

	/* ********************************************************************** */

	std::cout << BLUE "\n/* Construction by copy and assignment operator. " \
	<< "In both cases, modifying either the original array or its copy after copying musn’t affect the other array. */\n" NC << std::endl;

	Array<int>	originalArray(6);
	originalArray[0] = 4;
	originalArray[1] = 8;
	originalArray[2] = 15;
	originalArray[3] = 16;
	originalArray[4] = 23;
	originalArray[5] = 42;
	
	Array<int>	copyArray(originalArray);

	std::cout << "originalArray = {";
	for (unsigned int i = 0; i < originalArray.size(); i++)
	{
		std::cout << originalArray[i];
		if (i < originalArray.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
	std::cout << "copyArray     = {";
	for (unsigned int i = 0; i < copyArray.size(); i++)
	{
		std::cout << copyArray[i];
		if (i < copyArray.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}\n" << std::endl;

	std::cout << ITALIC "*** modification of the copy array ***\n" NC << std::endl;
	copyArray[0] = 42;
	std::cout << "originalArray[0] = " << originalArray[0] << std::endl;
	std::cout << "copyArray[0]     = " << copyArray[0] << std::endl;

	/* ********************************************************************** */
	
	std::cout << BLUE "\n/* You MUST use the operator new[] to allocate memory. " \
	<< "Preventive allocation (allocating memory in advance) is forbidden.  */\n" NC << std::endl;

	std::cout << ITALIC "> see code <" << std::endl;

	/* ********************************************************************** */
	
	std::cout << BLUE "\n/* Elements can be accessed through the subscript operator: [ ]. */\n" NC << std::endl;

	std::cout << ITALIC "> see code <" << std::endl;

	/* ********************************************************************** */
	
	std::cout << BLUE "\n/* When accessing an element with the [ ] operator, " \
	<< "if its index is out of bounds, an std::exception is thrown. */\n" NC << std::endl;

	try
	{
		std::cout << emptyArray[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << originalArray[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << originalArray[6] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/* ********************************************************************** */
	
	std::cout << BLUE "\n/* A member function size() that returns the number of elements in the array. " \
	<< "This member function takes no parameter and musn’t modify the current instance. */\n" NC << std::endl;

	std::cout << "emptyArray.size()    = " << emptyArray.size() << std::endl;
	std::cout << "filledArray.size()   = " << filledArray.size() << std::endl;
	std::cout << "originalArray.size() = " << originalArray.size() << std::endl;
	std::cout << "copyArray.size()     = " << copyArray.size() << std::endl;
}
