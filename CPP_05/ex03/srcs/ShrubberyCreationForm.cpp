/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:01:18 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/13 20:23:42 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137, target)
{
}

/* ************************************************************************** */

AForm	*ShrubberyCreationForm::createInstance(std::string target)
{
	ShrubberyCreationForm	*form;
	
	form = new ShrubberyCreationForm(target);
	return form;
}

bool	ShrubberyCreationForm::executeForm(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		std::cout << executor.getName() << " couldn’t execute " << this->getName() << " because he is too low in the hierarchy" << std::endl;
	else
	{
		std::string	filename(this->getName() + "_shrubbery");
		std::ofstream myFile(filename.c_str(), std::ios::app);
		
		if(myFile)
		{
			myFile << \
			"          v .   ._, |_  .,			\n"
			"       `-._\\/  .  \\ /    |/_		\n"
			"           \\  _\\, y | \\//		\n"
			"     _\\_.___\\, \\/ -.\\||		\n"
			"       `7-,--.`._||  / / ,			\n"
			"       /'     `-. `./ / |/_.'		\n"
			"                 |    |//			\n"
			"                 |_    /			\n"
			"                 |-   |			\n"
			"                 |   =|			\n"
			"                 |    |			\n"
			"----------------/ ,  . \\--------._\n";
			std::cout << "trees were planted in " << this->getTarget() << std::endl;
			return true;
		}
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " due to a problem occurring when opening the file " << filename << std::endl;
	}
	return false;
}
