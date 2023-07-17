/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:52:44 by tchevrie          #+#    #+#             */
/*   Updated: 2023/07/17 17:17:48 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (std::cerr << "Error: invalid number of arguments.\n", 1);
	return (!PmergeMe(argc - 1, argv + 1));
}
