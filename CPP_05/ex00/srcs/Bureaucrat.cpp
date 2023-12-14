/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:53:08 by tchevrie          #+#    #+#             */
/*   Updated: 2023/12/12 21:00:13 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */

Bureaucrat::Bureaucrat() : _name("someBureaucrat")
{
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& src)
{
	this->_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

/* ************************************************************************** */

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(int grade) : _name("someBureaucrat")
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

/* ************************************************************************** */

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::promote()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade -= 1;
}

void Bureaucrat::demote()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade += 1;
}

/* ************************************************************************** */

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[!] Bureaucrat grade too high [!]");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[!] Bureaucrat grade too low [!]");
}

/* ************************************************************************** */

std::string	getName(const Bureaucrat &bureaucrat)
{
	return (bureaucrat.getName());
}

int	getGrade(const Bureaucrat &bureaucrat)
{
	return (bureaucrat.getGrade());
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

