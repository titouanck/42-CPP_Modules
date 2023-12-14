/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:56:16 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/08 15:51:54 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void )
{
	std::cout << "Construction with no parameter: Creates an empty array" << std::endl;
	Array<int>			emptyInt;
	Array<char>			emptyChar;
	Array<std::string>	emptyString;

	std::cout << '\t' << "Size of emptyInt		= " << emptyInt.size() << std::endl;
	std::cout << '\t' << "Size of emptyChar		= " << emptyChar.size() << std::endl;
	std::cout << '\t' << "Size of emptyString		= " << emptyString.size() << std::endl;

	try
	{
		std::cout << std::endl << '\t' << "(Array<int>) emptyInt[0] = " << emptyInt[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "Construction with an unsigned int n as a parameter: " << std::endl;
	std::cout << "Creates an array of n elements initialized by default." << std::endl;
	Array<int>			someInt(4);
	Array<char>			someChar(8);
	Array<std::string>	someString(15);
	Array<double>		someDouble(16);
	Array<float>		someFloat(23);
	Array<size_t>		someSizeT(42);

	try
	{
		std::cout << '\t' << "(Array<int>) someInt : ";
		for (size_t i = 0; i < someInt.size(); i++)
			std::cout << someInt[i] << "; ";
		std::cout << std::endl << '\t' << "(Array<char>) someChar : ";
		for (size_t i = 0; i < someChar.size(); i++)
			std::cout << '\'' << someChar[i] << '\'' << "; ";
		std::cout << std::endl << '\t' << "(Array<string>) someString : ";
		for (size_t i = 0; i < someString.size(); i++)
			std::cout << "\"" << someString[i] << "\"" << "; ";
		std::cout << std::endl << '\t' << "(Array<double>) someDouble : ";
		for (size_t i = 0; i < someDouble.size(); i++)
			std::cout << someDouble[i] << "; ";
		std::cout << std::endl << '\t' << "(Array<float>) someFloat : ";
		for (size_t i = 0; i < someFloat.size(); i++)
			std::cout << someFloat[i] << "; ";
		std::cout << std::endl << '\t' << "(Array<size_t>) someSizeT : ";
		for (size_t i = 0; i < someSizeT.size(); i++)
			std::cout << someSizeT[i] << "; ";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Construction by copy and assignment operator." << std::endl;
	Array<int>			anotherInt(someInt);
	Array<char>			anotherChar(someChar);
	Array<std::string>	anotherString(someString);
	Array<double>		anotherDouble(someDouble);
	Array<float>		anotherFloat(someFloat);
	Array<size_t>		anotherSizeT(someSizeT);

	try
	{
		std::cout << '\t' << "(Array<int>) anotherInt : ";
		for (size_t i = 0; i < anotherInt.size(); i++)
			std::cout << anotherInt[i] << "; ";
		std::cout << std::endl << '\t' << "(Array<char>) anotherChar : ";
		for (size_t i = 0; i < anotherChar.size(); i++)
			std::cout << '\'' << anotherChar[i] << '\'' << "; ";
		std::cout << std::endl << '\t' << "(Array<string>) anotherString : ";
		for (size_t i = 0; i < anotherString.size(); i++)
			std::cout << "\"" << anotherString[i] << "\"" << "; ";
		std::cout << std::endl << '\t' << "(Array<double>) anotherDouble : ";
		for (size_t i = 0; i < anotherDouble.size(); i++)
			std::cout << anotherDouble[i] << "; ";
		std::cout << std::endl << '\t' << "(Array<float>) anotherFloat : ";
		for (size_t i = 0; i < anotherFloat.size(); i++)
			std::cout << anotherFloat[i] << "; ";
		std::cout << std::endl << '\t' << "(Array<size_t>) anotherSizeT : ";
		for (size_t i = 0; i < anotherSizeT.size(); i++)
			std::cout << anotherSizeT[i] << "; ";
	
		std::cout << std::endl << std::endl;
		std::cout << "In both cases, modifying either the original array or its copy after copying musn't affect the other array." << std::endl;
		
		someInt[0] = 42; anotherInt[0] = -42;
		std::cout << '\t' << "someInt[0]\t= " << someInt[0] << "\t;   " << "anotherInt[0]\t= " << anotherInt[0] << std::endl;
		
		someChar[0] = '+'; anotherChar[0] = '-';
		std::cout << '\t' << "someChar[0]\t= " << someChar[0] << "\t;   " << "anotherChar[0]\t= " << anotherChar[0] << std::endl;
		
		someString[0] = "Hi"; anotherString[0] = "Bye";
		std::cout << '\t' << "someString[0]\t= " << someString[0] << "\t;   " << "anotherString[0]\t= " << anotherString[0] << std::endl;
		
		someDouble[0] = 42.42; anotherDouble[0] = -42.42;
		std::cout << '\t' << "someDouble[0]\t= " << someDouble[0] << "\t;   " << "anotherDouble[0]\t= " << anotherDouble[0] << std::endl;
		
		someFloat[0] = 42.42f; anotherFloat[0] = -42.42f;
		std::cout << '\t' << "someFloat[0]\t= " << someFloat[0] << "\t;   " << "anotherFloat[0]\t= " << anotherFloat[0] << std::endl;
		
		someSizeT[0] = 1024; anotherSizeT[0] = 2048;
		std::cout << '\t' << "someSizeT[0]\t= " << someSizeT[0] << "\t;   " << "anotherSizeT[0]\t= " << anotherSizeT[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	


	std::cout << std::endl;
	std::cout << "Elements can be accessed through the subscript operator: [ ]" << std::endl;
	std::cout << "When accessing an element with the [ ] operator, " << std::endl;
	try
	{
		std::cout << '\t' << "anotherInt[0] = " << anotherInt[0] << std::endl;
		anotherInt[0] += 1;
		std::cout << '\t' << "(Operation += 1)" << std::endl;
		std::cout << '\t' << "anotherInt[0] = " << anotherInt[0] << std::endl;
		anotherInt[0] *= 2;
		std::cout << '\t' << "(Operation *= 2)" << std::endl;
		std::cout << '\t' << "anotherInt[0] = " << anotherInt[0] << std::endl;

		std::cout << std::endl;
		std::cout << "if its index is out of bounds, an std::exception is thrown" << std::endl;
		std::cout << '\t' << "someInt[150] = " << someInt[150] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "A member function size() that returns the number of elements in the array" << std::endl;
	std::cout << '\t' << "Size of someInt		= " << someInt.size() << std::endl;
	std::cout << '\t' << "Size of someChar	= " << someChar.size() << std::endl;
	std::cout << '\t' << "Size of someString	= " << someString.size() << std::endl;
	std::cout << '\t' << "Size of someDouble	= " << someDouble.size() << std::endl;
	std::cout << '\t' << "Size of someFloat	= " << someFloat.size() << std::endl;
	std::cout << '\t' << "Size of someSizeT	= " << someSizeT.size() << std::endl;

	std::cout << std::endl;

	std::cout << '\t' << "Size of anotherInt	= " << anotherInt.size() << std::endl;
	std::cout << '\t' << "Size of anotherChar	= " << anotherChar.size() << std::endl;
	std::cout << '\t' << "Size of anotherString	= " << anotherString.size() << std::endl;
	std::cout << '\t' << "Size of anotherDouble	= " << anotherDouble.size() << std::endl;
	std::cout << '\t' << "Size of anotherFloat	= " << anotherFloat.size() << std::endl;
	std::cout << '\t' << "Size of anotherSizeT	= " << anotherSizeT.size() << std::endl;
}
