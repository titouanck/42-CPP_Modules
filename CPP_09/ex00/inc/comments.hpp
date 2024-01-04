/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:23:57 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/04 13:49:59 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMENTS_HPP
	#define COMMENTS_HPP

	#include <string>
	#include <iostream>

	#define TCK_RED "\033[0;31m"
	#define TCK_BLUE "\033[0;34m"
	#define TCK_NC "\033[0m"

/* ************************************************************************** */

std::string	formatComment(std::string str, unsigned int n);
std::string	formatComment(std::string str);

void		comment(std::string str);
void		_comment(std::string str);
void		comment_(std::string str);
void		_comment_(std::string str);

void		comment(std::string str, unsigned int n);
void		_comment(std::string str, unsigned int n);
void		comment_(std::string str, unsigned int n);
void		_comment_(std::string str, unsigned int n);

/* ************************************************************************** */

#endif
