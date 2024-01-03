/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:23:57 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/29 18:54:15 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMENTS_HPP
	#define COMMENTS_HPP

	#include <string>
	#include <iostream>

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
