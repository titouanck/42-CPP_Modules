/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:58:12 by titouan_ck        #+#    #+#             */
/*   Updated: 2023/06/04 14:09:20 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
	#define BUREAUCRAT_HPP

	#include <string>
	#include <iostream>
	#include <exception>

	class Bureaucrat
	{
		private:
			Bureaucrat(void) {}
			class GradeTooHighException;
			class GradeTooLowException;
			
			const std::string	_name;
			int					_grade;

		public:
			Bureaucrat(std::string name, int grade);
			Bureaucrat(const Bureaucrat &obj);
			~Bureaucrat(void);
			Bureaucrat	&operator=(const Bureaucrat &obj);

			std::string	getName(void) const;
			int			getGrade(void) const;
			void		promote(void);
			void		demote(void);
	};

	class Bureaucrat::GradeTooHighException : public std::exception
	{
		private:
			const char	*_e;
		public:
			GradeTooHighException(const char *e);
			const char* what() const throw();
	};

	class Bureaucrat::GradeTooLowException : public std::exception
	{
		private:
			const char	*_e;
		public:
			GradeTooLowException(const char *e);
			const char* what() const throw();
	};

	std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
