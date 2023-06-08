/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:56:16 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/08 13:41:36 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void )
{
	int			tab[] = {4, 8, 15, 16, 23, 42};
	size_t		tabSize = (sizeof(tab) / sizeof(tab[0]));
	std::string strTab[] = {"Lorem",  "ipsum",  "dolor",  "sit",  "amet", "consectetur", "adipiscing", "elit."};
	size_t		strTabSize = (sizeof(strTab) / sizeof(strTab[0]));

	iter(tab, tabSize, &print);
	
	std::cout << std::endl << std::endl;
	std::cout << "Let's add +1 to each element" << std::endl;
	iter(tab, tabSize, &addOne);
	iter(tab, tabSize, &print);

	std::cout << std::endl << std::endl;
	std::cout << "Let's set the tab to zero" << std::endl;
	iter(tab, tabSize, &setToZero);
	iter(tab, tabSize, &print);

	std::cout << std::endl << std::endl;
	std::cout << "Let's print strTab[]" << std::endl;
	iter(strTab, strTabSize, &print);
	std::cout << std::endl;
}
