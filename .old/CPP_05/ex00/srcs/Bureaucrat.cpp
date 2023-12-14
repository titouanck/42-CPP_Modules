/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:58:52 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/04 14:10:07 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException("Grade Too High ! Please stay in range [1 - 150]"));
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException("Grade Too Low ! Please stay in range [1 - 150]"));
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj.getName())
{
	*this = obj;
}

Bureaucrat::~Bureaucrat(void)
{}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	this->_grade = obj._grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::promote(void)
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException("Impossible to promote the boss. And by the way, started from the bottom, now we here.");
	else
		this->_grade -= 1;
}

void	Bureaucrat::demote(void)
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException("Impossible to demote him, he's already at the lowest rank.");
	else
		this->_grade += 1;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *e) : _e(e)
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *e) : _e(e)
{}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (_e);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (_e);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) 
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << '.';
	return (os);
}
