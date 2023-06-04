/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:53:47 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/04 23:09:56 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : Form("Shrubbery Creation", 145, 137, obj._target)
{
	*this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	(void)	obj;

	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::string		filename;
	std::ofstream	file;

	try {
		_readyToExecute(executor);
	}
	catch (std::exception &e) {
		throw;
	}
	
	filename = _target + "_shrubbery";
	file.open(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Could not open file" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		file << "            .        +          .      .          ."		 << std::endl;
		file << "     .            _        .                    ."			 << std::endl;
		file << "  ,              /;-._,-.____        ,-----.__"			 << std::endl;
		file << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,"		 << std::endl;
		file << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /"		 << std::endl;
		file << "                      ,    `./  \\:. `.   )==-'  ."		 << std::endl;
		file << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ."	 << std::endl;
		file << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o"			 << std::endl;
		file << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ."		 << std::endl;
		file << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7"	 << std::endl;
		file << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/"	 << std::endl;
		file << "              \\:  `  X` _| _,\\/'   .-'"					 << std::endl;
		file << ".               \":._:`\\____  /:'  /      .           ."	 << std::endl;
		file << "                    \\::.  :\\/:'  /              +"		 << std::endl;
		file << "   .                 `.:.  /:'  }      ."					 << std::endl;
		file << "           .           ):_(:;   \\           ."			 << std::endl;
		file << "                      /:. _/ ,  |"							 << std::endl;
		file << "                   . (|::.     ,`                  ."		 << std::endl;
		file << "     .                |::.    {"							 << std::endl;
		file << "                      |::.\\  \\ `."						 << std::endl;
		file << "                      |:::(\\    |"						 << std::endl;
		file << "              O       |:::/{ }  |                  (o"		 << std::endl;
		file << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`"	 << std::endl;
		file << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
	}
	file.close();
}
