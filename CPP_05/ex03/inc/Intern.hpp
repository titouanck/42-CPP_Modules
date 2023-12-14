/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:54:34 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/13 20:08:46 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
	#define INTERN_HPP

	#include "ShrubberyCreationForm.hpp"
	#include "RobotomyRequestForm.hpp"
	#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);	
		Intern &operator=(const Intern &copy);
		~Intern();

		AForm	*makeForm(std::string name, std::string target);
};

#endif
