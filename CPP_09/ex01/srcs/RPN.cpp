/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:07:28 by tchevrie          #+#    #+#             */
/*   Updated: 2024/01/15 11:06:59 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ************************************************************************** */

bool	RPN(std::string str)
{
	std::stack<int>		numbers;
	size_t				i;
	int					topNumber;

	if (!str[0] || !isdigit(str[0]))
		return (std::cout << "Error\n", false);
	i = 0;
	while (isspace(str[i]))
		i++;
	while (str[i])
	{
		if (isdigit(str[i]))
			numbers.push(str[i] - '0');
		else 
		{
			if (numbers.size() < 2)
				return (std::cout << "Error\n", false);
			else
			{
				topNumber = numbers.top();
				numbers.pop();
				switch (str[i])
				{
					case '*':
						topNumber = numbers.top() * topNumber;
						break ;
					case '/':
						if (topNumber == 0)
							return (std::cout << "Error\n", false);
						topNumber = numbers.top() / topNumber;
						break ;
					case '+':
						topNumber = numbers.top() + topNumber;
						break ;
					case '-':
						topNumber = numbers.top() - topNumber;
						break ;
					default:
						return (std::cout << "Error\n", false);
						break ;
				}
				numbers.pop();
				numbers.push(topNumber);
			}
		}
		if (str[i + 1] && !isspace(str[i + 1]))
			return (std::cout << "Error\n", false);
		while (isspace(str[++i]))
			;
	}
	if (numbers.empty())
		return (std::cout << "Error\n", false);
	else
		return (std::cout << numbers.top() << std::endl, true);
}

/* ************************************************************************** */
