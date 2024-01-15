/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:50:53 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/24 17:47:01 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

bool	getInput(std::string field, std::string &str, int format)
{
	bool	firstPrompt = true;

	while (str.length() < 1)
	{
		if (firstPrompt)
			std::cout << field << ": ";
		else
			std::cout << RED << field << ": " NC;
		firstPrompt = false;
		if (!std::getline(std::cin, str))
		{
			std::cout << RED "✗" NC << std::endl;
			std::cerr << RED "Operation failed." NC << std::endl;
			exit(1);
		}
		str = stripStr(str);
		if (format == 2)
		{
			str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
			for (size_t i = 0; i < str.length(); i++)
			{
				if ((str.at(i) == '-' && str.at(i + 1) == '-') \
				|| (str.at(i) != '-' && !isdigit(str.at(i)) \
				&& (i != 0 || str.at(i) != '+')) \
				|| *str.begin() == '-' || *(str.end() - 1) == '-' \
				|| (*str.begin() == '0' && str.length() < 2) \
				|| (*str.begin() == '+' && str.length() < 3))
					str = "";
			}
		}
	}
	return (true);
}

std::string	stripStr(std::string str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (i > 0)
		str = str.substr(i, str.length() - i);
	j = str.length();
	if (j-- == 0)
		return (str);
	while (j >= 0 && (str[j] == ' ' || (str[j] >= '\t' && str[j] <= '\r')))
		j--;
	str = str.substr(0, j + 1);
	return (str);
}

std::string	toupperStr(std::string str)
{
	size_t	length;
	size_t	i;

	length = str.length();
	i = 0;
	while (i < length)
	{
		if ('a' <= str.at(i) && str.at(i) <= 'z')
			str.at(i) += ('A' - 'a');
		i++;
	}
	return (str);
}
