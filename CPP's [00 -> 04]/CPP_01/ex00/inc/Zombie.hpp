/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 07:19:19 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 07:44:29 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
	# define ZOMBIE_HPP

	#include <iostream>
	#include <string>

class Zombie
{
	private:
		std::string	name;
		
	public:
		void	announce( void );

		Zombie( std::string name );
		~Zombie();
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif