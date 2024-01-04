/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:07:28 by tchevrie          #+#    #+#             */
/*   Updated: 2024/01/04 19:27:33 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ************************************************************************** */

bool	RPN(std::string str)
{
	std::stack<int>		numbers;
	int					tmp;
	size_t				i;
	int					result;
	bool				definedResult;

	result = 0;
	definedResult = false;
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
			if (numbers.size() < 1)
				return (std::cout << "Error\n", false);
			else
			{
				if (definedResult == false)
				{
					if (numbers.size() < 2)
						return (std::cout << "Error\n", false);
					tmp = numbers.top();
					numbers.pop();
					result = numbers.top();
					numbers.pop();
					numbers.push(tmp);
					definedResult = true;
				}
				switch (str[i])
				{
					case '*':
						result *= numbers.top();
						break ;
					case '/':
						result /= numbers.top();
						break ;
					case '+':
						result += numbers.top();
						break ;
					case '-':
						result -= numbers.top();
						break ;
					default:
						return (std::cout << "Error\n", false);
						break ;
				}
				numbers.pop();
			}
		}
		if (str[i + 1] && !isspace(str[i + 1]))
			return (std::cout << "Error\n", false);
		while (isspace(str[++i]))
			;
	}
	if (!numbers.empty())
		return (std::cout << "Error\n", false);
	else
		return (std::cout << result << std::endl, true);
}

/* ************************************************************************** */
