/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:30:03 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 12:33:10 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
	#define HARL_HPP

	#include <string>
	#include <climits>
	#include <iostream>

class Harl
{
	private:
		void	debug(void);	
		void	info(void);	
		void	warning(void);	
		void	error(void);

	public:
		void	complain(std::string level);	
};

#endif