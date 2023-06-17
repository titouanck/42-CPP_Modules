/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:07:28 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/17 15:58:22 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	RPN(std::string str)
{
	std::deque<int>		numbers;
	size_t				i;
	int					result;

	if (!str[0] || !isdigit(str[0]))
		return (std::cerr << "Error\n", false);
	i = 0;
	while (isspace(str[++i]))
		;
	result = str[0] - '0';
	while (str[i])
	{
		if (isdigit(str[i]))
			numbers.push_back(str[i] - '0');
		else 
		{
			if (numbers.empty())
				return (std::cerr << "Error\n", false);
			switch (str[i])
			{
				case '*':
					result *= numbers.back();
					break ;
				case '/':
					result /= numbers.back();
					break ;
				case '+':
					result += numbers.back();
					break ;
				case '-':
					result -= numbers.back();
					break ;
				default:
					return (std::cerr << "Error\n", false);
					break ;
			}
			numbers.pop_back();
		}
		if (str[i + 1] && !isspace(str[i + 1]))
			return (std::cerr << "Error\n", false);
		while (isspace(str[++i]))
			;
	}
	if (!numbers.empty())
		return (std::cerr << "Error\n", false);
	else
		return (std::cout << result << std::endl, true);
}
