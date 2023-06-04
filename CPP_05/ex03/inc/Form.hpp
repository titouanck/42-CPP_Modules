/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:24:28 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/04 16:42:43 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
	#define FORM_HPP

	#include <string>
	#include <iostream>
	#include <exception>

	class Bureaucrat;

	class Form
	{
		private:
			const std::string	_name;
			const int			_minGradeToSign;
			const int			_minGradeToExecute;
			bool				_signed;

		protected:
			class GradeTooHighException;
			class GradeTooLowException;
			class AlreadySigned;
			const std::string	_target;
			void				_readyToExecute(const Bureaucrat &bureaucratObj) const;

		public:
			Form(std::string name, int minGradeToSign, int minGradeToExecute, std::string target);
			Form(const Form &obj);
			virtual ~Form(void);
			Form	&operator=(const Form &obj);

			std::string	getTarget(void) const;
			std::string	getName(void) const;
			int			getMinGradeToSign(void) const;
			int			getMinGradeToExecute(void) const;
			bool		isSigned(void) const;
			void		beSigned(Bureaucrat &bureaucratObj);
	
			virtual void	execute(const Bureaucrat &executor) const = 0;
	};

	class Form::GradeTooHighException : public std::exception
	{
		private:
			const char	*_e;
		public:
			GradeTooHighException(const char *e);
			const char* what() const throw();
	};

	class Form::GradeTooLowException : public std::exception
	{
		private:
			const char	*_e;
		public:
			GradeTooLowException(const char *e);
			const char* what() const throw();
	};

	class Form::AlreadySigned : public std::exception
	{
		private:
			const char	*_e;
		public:
			AlreadySigned(const char *e);
			const char* what() const throw();
	};

std::ostream	&operator<<(std::ostream &os, const Form &obj);

#endif
