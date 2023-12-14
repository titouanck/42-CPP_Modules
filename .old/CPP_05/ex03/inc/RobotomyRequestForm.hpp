/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:54:03 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/04 23:43:24 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
	#define ROBOTOMYREQUESTFORM_HPP

	#include "Form.hpp"

	class RobotomyRequestForm : public Form
	{
		public:
			RobotomyRequestForm(std::string target);
			RobotomyRequestForm(const RobotomyRequestForm &obj);
			~RobotomyRequestForm(void);
			RobotomyRequestForm	&operator=(const RobotomyRequestForm &obj);

			void	execute(const Bureaucrat &executor) const;

			static Form	*createInstance(std::string target);
	};

#endif
