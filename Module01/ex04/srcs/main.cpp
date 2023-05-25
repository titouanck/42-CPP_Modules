/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:17:50 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/25 12:17:50 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <climits>
#include <fstream>
#include <cstddef>   

bool	ends_with_newline(std::ifstream &infile)
{
	std::string	buffer;

	getline(infile, buffer, '\0');
	infile.clear();
	infile.seekg(0);
	if (buffer.length() < 1 || *(buffer.end() - 1) != '\n')
		return (false);
	else
		return (true);
}

void	ft_replace(std::ifstream &infile, std::ofstream &outfile, std::string s1, std::string s2)
{
	std::string	line;
	size_t		n;
	bool		newline;
	bool		firstLine = true;

	newline = ends_with_newline(infile);
	while (getline(infile, line))
	{
		if (firstLine == false)
			outfile << std::endl;
		firstLine = false;
		n = 0;
		while (1)
		{
			n = line.find(s1, n);
			if (n == std::string::npos)
				break ;
			line = line.substr(0, n) + s2 + line.substr(n + s1.length());
			n += s2.length();
		}
		outfile << line;
	}
	if (newline == true)
		outfile << std::endl;
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
