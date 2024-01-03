/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:56:39 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/29 18:54:00 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comments.hpp"

#define TOOLS_RED "\033[0;31m"
#define TOOLS_BLUE "\033[0;34m"
#define TOOLS_NC "\033[0m"

/* ************************************************************************** */

std::string	formatComment(std::string str, unsigned int n)
{
	std::string		prefix;
	std::string		suffix;
	unsigned int	count;

	prefix = "/* ";
	suffix = "*/";

	count = n;
	if (str.length() + prefix.length() + suffix.length() + 1 > n)
		return prefix + str + ' ' + suffix;
	str = prefix + str + ' ';
	while (str.length()+ suffix.length() < n)
	{
		str += '*';
	}
	str += suffix;
	return str;
}

std::string	formatComment(std::string str)
{
	return "/* " + str + " */";
}

/* ************************************************************************** */

void	comment(std::string str)
{
	std::cout << TOOLS_BLUE << formatComment(str) << TOOLS_NC << std::endl;
}

void	_comment(std::string str)
{
	std::cout << std::endl;
	std::cout << TOOLS_BLUE << formatComment(str) << TOOLS_NC << std::endl;
}

void	comment_(std::string str)
{
	std::cout << TOOLS_BLUE << formatComment(str) << TOOLS_NC << std::endl;
	std::cout << std::endl;
}

void	_comment_(std::string str)
{
	std::cout << std::endl;
	std::cout << TOOLS_BLUE << formatComment(str) << TOOLS_NC << std::endl;
	std::cout << std::endl;
}

/* ************************************************************************** */

void	comment(std::string str, unsigned int n)
{
	std::cout << TOOLS_BLUE << formatComment(str, n) << TOOLS_NC << std::endl;
}

void	_comment(std::string str, unsigned int n)
{
	std::cout << std::endl;
	std::cout << TOOLS_BLUE << formatComment(str, n) << TOOLS_NC << std::endl;
}

void	comment_(std::string str, unsigned int n)
{
	std::cout << TOOLS_BLUE << formatComment(str, n) << TOOLS_NC << std::endl;
	std::cout << std::endl;
}

void	_comment_(std::string str, unsigned int n)
{
	std::cout << std::endl;
	std::cout << TOOLS_BLUE << formatComment(str, n) << TOOLS_NC << std::endl;
	std::cout << std::endl;
}
