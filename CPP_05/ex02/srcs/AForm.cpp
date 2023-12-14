/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:37:07 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/12 22:21:48 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ************************************************************************** */

AForm::AForm() : _name ("someForm"), _gradeRequiredToSign(1), _gradeRequiredToExecute(100), _target("someTarget")
{
	this->_signed = false;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _gradeRequiredToSign(copy._gradeRequiredToSign), _gradeRequiredToExecute(copy._gradeRequiredToExecute), _target(copy._target)
{
	*this = copy;
}

AForm	&AForm::operator=(const AForm &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

AForm::~AForm()
{
}

/* ************************************************************************** */

AForm::AForm(std::string name) : _name(name), _gradeRequiredToSign(1), _gradeRequiredToExecute(100)
{
	this->_signed = false;
}

AForm::AForm(int gradeRequiredToSign, int gradeRequiredToExecute) : _name("someForm"), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw AForm::GradeTooLowException();
	this->_signed = false;
}

AForm::AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) : _name(name), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw AForm::GradeTooLowException();
	this->_signed = false;
}

AForm::AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute, std::string target) : _name(name), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute), _target(target)
{
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw AForm::GradeTooLowException();
	this->_signed = false;
}

/* ************************************************************************** */

std::string	AForm::getName() const
{
	return this->_name;
}

std::string	AForm::getTarget() const
{
	return this->_target;
}

int	AForm::getGradeToSign() const
{
	return this->_gradeRequiredToSign;
}

int	AForm::getGradeToExecute() const
{
	return this->_gradeRequiredToExecute;
}

bool	AForm::isSigned() const
{
	return this->_signed;
}

bool	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_signed == true)
		std::cout << bureaucrat.getName() << " couldn’t sign " << this->getName() << " because it has already been done" << std::endl;
	else if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
		std::cout << bureaucrat.getName() << " couldn’t sign " << this->getName() << " because he is too low in the hierarchy" << std::endl;
	else
	{
		this->_signed = true;
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		return true;
	}
	return false;
}

bool AForm::execute(const Bureaucrat &executor) const
{
	if (this->isSigned() == true)
		return this->executeForm(executor);
	else
	{
		std::cout << executor.getName() << " couldn’t execute " << this->getName() << " because he has not been signed yet" << std::endl;
		return false;
	}
}

/* ************************************************************************** */

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("[!] AForm grade too high [!]");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("[!] AForm grade too low [!]");
}

/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &os, const AForm &form)
{
	std::string	isSigned;
	
	isSigned = form.isSigned() ? "signed" : "unsigned";
	os << form.getName() << ", " << isSigned << " form requiring a grade of " << form.getGradeToSign() << " to sign, and " << form.getGradeToExecute() << " to execute";
	return os;
}
