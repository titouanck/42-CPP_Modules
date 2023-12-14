/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:37:07 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/12 22:21:48 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */

Form::Form() : _name ("someForm"), _gradeRequiredToSign(1), _gradeRequiredToExecute(100)
{
	this->_signed = false;
}

Form::Form(const Form &copy) : _name(copy._name), _gradeRequiredToSign(copy._gradeRequiredToSign), _gradeRequiredToExecute(copy._gradeRequiredToExecute)
{
	*this = copy;
}

Form	&Form::operator=(const Form &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

Form::~Form()
{
}

/* ************************************************************************** */

Form::Form(std::string name) : _name(name), _gradeRequiredToSign(1), _gradeRequiredToExecute(100)
{
	this->_signed = false;
}

Form::Form(int gradeRequiredToSign, int gradeRequiredToExecute) : _name("someForm"), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
}

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) : _name(name), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
}

/* ************************************************************************** */

std::string	Form::getName() const
{
	return this->_name;
}

int	Form::getGradeToSign() const
{
	return this->_gradeRequiredToSign;
}

int	Form::getGradeToExecute() const
{
	return this->_gradeRequiredToExecute;
}

bool	Form::isSigned() const
{
	return this->_signed;
}

bool	Form::beSigned(const Bureaucrat &bureaucrat)
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

/* ************************************************************************** */

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("[!] Form grade too high [!]");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("[!] Form grade too low [!]");
}

/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &os, const Form &form)
{
	std::string	isSigned;
	
	isSigned = form.isSigned() ? "signed" : "unsigned";
	os << form.getName() << ", " << isSigned << " form requiring a grade of " << form.getGradeToSign() << " to sign, and " << form.getGradeToExecute() << " to execute";
	return os;
}
