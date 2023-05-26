/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 07:19:19 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 09:07:55 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
	# define ZOMBIE_HPP

	#include <iostream>
	#include <string>
	#include <climits>

class Zombie
{
	private:
		std::string	name;
		
	public:
		void	announce( void ) const;
		void	defName( std::string input );

		Zombie( void );
		Zombie( std::string name );
		~Zombie();
};

Zombie	*zombieHorde( int N, std::string name );

#endif