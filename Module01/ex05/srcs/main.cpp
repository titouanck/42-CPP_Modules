/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:17:50 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 13:05:26 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	complainer;

	complainer.complain("DEBUG");
	std::cout << std::endl;
	complainer.complain("INFO");
	std::cout << std::endl;
	complainer.complain("WARNING");
	std::cout << std::endl;
	complainer.complain("ERROR");
	std::cout << std::endl;
	complainer.complain("");
	std::cout << std::endl;
	complainer.complain("42");
}
