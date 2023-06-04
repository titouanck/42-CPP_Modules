/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:14:28 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/04 23:16:44 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
	#define INTERN_HPP

	#include "Form.hpp"

	class Intern
	{
		public:
			Intern(void);
			Intern(const Intern &obj);
			~Intern(void);
			Intern	&operator=(const Intern &obj);
			
			Form	*makeForm(std::string type, std::string target);
	};

#endif