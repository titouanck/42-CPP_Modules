/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:53:13 by tchevrie          #+#    #+#             */
/*   Updated: 2023/12/12 21:09:16 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
	#define BUREAUCRAT_HPP

	#include <string>
	#include <iostream>

/* ************************************************************************** */

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat &operator=(const Bureaucrat& src);
		~Bureaucrat();

		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);

		std::string	getName() const;
		int			getGrade() const;
		void		promote();
		void		demote();

	private:
		const std::string	_name;
		int					_grade;
		
		class GradeTooHighException;
		class GradeTooLowException;
};

/* ************************************************************************** */

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		const char	*what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		const char	*what() const throw();
};

/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

/* ************************************************************************** */

std::string		getName(const Bureaucrat &bureaucrat);
int				getGrade(const Bureaucrat &bureaucrat);

#endif
