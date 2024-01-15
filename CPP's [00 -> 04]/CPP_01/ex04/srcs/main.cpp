/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouan_ck <titouan_ck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:17:50 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/26 01:13:16 by titouan_ck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <climits>
#include <fstream>
#include <cstddef>   


void	ft_replace(std::ifstream &infile, std::ofstream &outfile, std::string s1, std::string s2)
{
	std::string	lines;
	size_t		n;

	if (getline(infile, lines, '\0'))
	{
		n = 0;
		while (1)
		{
			n = lines.find(s1, n);
			if (n == std::string::npos)
				break ;
			lines = lines.substr(0, n) + s2 + lines.substr(n + s1.length());
			n += s2.length();
		}
		outfile << lines;
	}
}

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;

	if (argc != 4 || ((std::string) argv[2]).length() < 1)
		return (std::cerr << "./sedIsForLosers <filename> \"s1\" \"s2\"" << std::endl, 1);
	infile.open(argv[1]);
	if (!infile.is_open())
		return (std::cerr << "Could not open infile." << std::endl, 1);
	outfile.open(((std::string) argv[1] + (std::string)".replace").c_str());
	if (!outfile.is_open())
		return (infile.close(), std::cerr << "Could not open outfile." << std::endl, 1);
	ft_replace(infile, outfile, argv[2], argv[3]);
	infile.close();
	outfile.close();
	return (0);
}
