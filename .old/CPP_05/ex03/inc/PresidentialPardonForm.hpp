/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:54:41 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/04 23:43:31 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
	#define PRESIDENTIALPARDONFORM_HPP

	#include "Form.hpp"

	class PresidentialPardonForm : public Form
	{
		public:
			PresidentialPardonForm(std::string target);
			PresidentialPardonForm(const PresidentialPardonForm &obj);
			~PresidentialPardonForm(void);
			PresidentialPardonForm	&operator=(const PresidentialPardonForm &obj);

			void	execute(const Bureaucrat &executor) const;
	
			static Form	*createInstance(std::string target);
	};

#endif
