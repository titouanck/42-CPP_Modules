/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:53:13 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/04 22:35:48 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
	#define SHRUBBERYCREATIONFORM_HPP

	#include "Form.hpp"

	class ShrubberyCreationForm : public Form
	{
		public:
			ShrubberyCreationForm(std::string target);
			ShrubberyCreationForm(const ShrubberyCreationForm &obj);
			~ShrubberyCreationForm(void);
			ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &obj);

			void	execute(const Bureaucrat &executor) const;
	};

#endif
