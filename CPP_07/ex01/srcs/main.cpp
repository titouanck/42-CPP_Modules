/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:37:39 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/29 17:11:57 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define BLUE "\033[34m"
#define NC "\033[0m"

/* PROTOTYPES *************************************************************** */

void	myPrintString(std::string str);
void	myPrintFloat(float flt);

template <typename T>
void	myPrint(T toPrint);

void	mainFromSubject();
void	myMain();

/* MAIN ********************************************************************* */

int	main(void)
{
	std::cout << BLUE "/* Main from subject */" NC "\n" << std::endl;
	mainFromSubject();

	std::cout << "\n" BLUE "/* My main */" NC "\n" << std::endl;
	myMain();
}

/* MAIN FROM THE SUBJECT **************************************************** */

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

void	mainFromSubject()
{
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );
}

/* MY OWN MAIN ************************************************************** */

void	myMain(void)
{
	std::string	tabStr[]	= {"Podasai", "Snayzy"};
	float		tabFlt[]	= {29.0f, 9.0f};
	
	iter(tabStr, sizeof(tabStr) / sizeof(tabStr[0]), myPrintString);
	std::cout << std::endl;
	
	iter(tabFlt, sizeof(tabFlt) / sizeof(tabFlt[0]), myPrintFloat);
	std::cout << std::endl;
	
	std::cout << std::endl << "/* ********************** */"<< std::endl << std::endl;

	iter(tabStr, sizeof(tabStr) / sizeof(tabStr[0]), myPrint<std::string>);
	std::cout << std::endl;

	iter(tabFlt, sizeof(tabFlt) / sizeof(tabFlt[0]), myPrint<float>);
	std::cout << std::endl;
}

/* ************************************************************************** */

void	myPrintString(std::string str)
{
	std::cout << str << ", ";
}

void	myPrintFloat(float flt)
{
	std::cout << flt << ", ";
}

template <typename T>
void	myPrint(T toPrint)
{
	std::cout << toPrint << ", ";
}

/* ************************************************************************** */
