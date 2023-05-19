/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:40:19 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/19 15:28:41 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

class toupperStr
{
	public:
		std::string	input;

		std::string	clToupper(void);
};

std::string	toupperStr::clToupper(void)
	{
		std::string	output;
		size_t		i;

		std::cout << "input: " << input << std::endl;
		i = 0;
		while (input[i])
		{
			if (97 <= input[i] && input[i] <= 122)
				output[i] = input[i] - 'a' + 'A';
			else
				output[i] = input[i];
			std::cout << output[i] << std::endl;
			i++;
		}
		// output[i] = '\0';
		std::cout << "output: " << output << std::endl;
		return (output);
	}

int	main(int argc, char **argv)
{
	toupperStr	str;
	std::string	majuscule;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			str.input = argv[i];
			// std::cout << str.input.length() << std::endl;
			majuscule = str.clToupper();
			std::cout << majuscule << std::endl;
		}
	}
} 
