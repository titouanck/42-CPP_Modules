/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:35:34 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/12 21:41:28 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
	#define AFORM_HPP

	#include <string>
	#include <iostream>
	#include <fstream>
	#include "Bureaucrat.hpp"

/* ************************************************************************** */

class AForm
{
	public:
		AForm();
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		~AForm();

		AForm(std::string name);
		AForm(int gradeRequiredToSign, int gradeRequiredToExecute);
		AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute, std::string target);

		std::string	getName() const;
		std::string	getTarget() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		bool		isSigned() const;
		bool		beSigned(const Bureaucrat &bureaucrat);
		
		bool		execute(const Bureaucrat &executor) const;
		virtual bool executeForm(const Bureaucrat &executor) const = 0;

	private:
		const std::string	_name;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;
		const std::string	_target;
		bool				_signed;

		class GradeTooHighException;
		class GradeTooLowException;
};

/* ************************************************************************** */

class AForm::GradeTooHighException : public std::exception
{
	public:
		const char	*what() const throw();
};

class AForm::GradeTooLowException : public std::exception
{
	public:
		const char	*what() const throw();
};

/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &os, const AForm &form);

/* ************************************************************************** */

#endif
