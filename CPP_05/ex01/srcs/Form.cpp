/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:24:52 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/04 15:44:58 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int minGradeToSign, int minGradeToExecute) : _name(name), \
	_minGradeToSign(minGradeToSign), \
	_minGradeToExecute(minGradeToExecute)
{
	if (_minGradeToSign < 1)
		throw (Form::GradeTooHighException("GradeToSign is too high (< 1)"));
	else if (_minGradeToExecute < 1)
		throw (Form::GradeTooHighException("GradeToExecute is too high (< 1)"));
	else if (_minGradeToSign > 150)
		throw (Form::GradeTooHighException("GradeToSign is too low (> 150)"));
	else if (_minGradeToExecute > 150)
		throw (Form::GradeTooHighException("GradeToExecute is too low (> 150)"));
	_signed = false;
}

Form::Form(const Form &obj) : _name(obj._name), \
	_minGradeToSign(obj._minGradeToSign), \
	_minGradeToExecute(obj._minGradeToExecute)
{
	if (_minGradeToSign < 1)
		throw (Form::GradeTooHighException("GradeToSign is too high (< 1)"));
	else if (_minGradeToExecute < 1)
		throw (Form::GradeTooHighException("GradeToExecute is too high (< 1)"));
	else if (_minGradeToSign > 150)
		throw (Form::GradeTooHighException("GradeToSign is too low (> 150)"));
	else if (_minGradeToExecute > 150)
		throw (Form::GradeTooHighException("GradeToExecute is too low (> 150)"));
	_signed = false;
}

Form::~Form(void)
{}

Form	&Form::operator=(const Form &obj)
{
	(void)	obj;

	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

int			Form::getMinGradeToSign(void) const
{
	return (this->_minGradeToSign);
}

int			Form::getMinGradeToExecute(void) const
{
	return (this->_minGradeToExecute);
}

bool		Form::isSigned(void) const
{
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat &bureaucratObj)
{
	if (_signed == true)
		throw (Form::AlreadySigned("Form already signed."));
	else if (bureaucratObj.getGrade() <= _minGradeToSign)
		_signed = true;
	else
		throw (Form::GradeTooLowException("Insufficient permission to sign."));
}

Form::GradeTooHighException::GradeTooHighException(const char *e) : _e(e)
{}

Form::GradeTooLowException::GradeTooLowException(const char *e) : _e(e)
{}

Form::AlreadySigned::AlreadySigned(const char *e) : _e(e)
{}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return (_e);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return (_e);
}

const char *Form::AlreadySigned::what(void) const throw()
{
	return (_e);
}

std::ostream	&operator<<(std::ostream &os, const Form &obj)
{
	os << "Form N° " << obj.getName() \
	<< " ; minGradeToSign: " << obj.getMinGradeToSign() \
	<< " ; minGradeToExecute: " << obj.getMinGradeToExecute() << std::boolalpha \
	<< " ; signed: " << obj.isSigned() << ';';

	return (os);
}
