/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:35:34 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/12 21:41:28 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
	#define FORM_HPP

	#include <string>
	#include <iostream>
	#include "Bureaucrat.hpp"

/* ************************************************************************** */

class Form
{
	public:
		Form();
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();

		Form(std::string name);
		Form(int gradeRequiredToSign, int gradeRequiredToExecute);
		Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);

		std::string	getName() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		bool		isSigned() const;
		bool		beSigned(const Bureaucrat &bureaucrat);

	private:
		const std::string	_name;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;
		bool				_signed;

		class GradeTooHighException;
		class GradeTooLowException;
};

/* ************************************************************************** */

class Form::GradeTooHighException : public std::exception
{
	public:
		const char	*what() const throw();
};

class Form::GradeTooLowException : public std::exception
{
	public:
		const char	*what() const throw();
};

/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &os, const Form &form);

/* ************************************************************************** */

#endif
