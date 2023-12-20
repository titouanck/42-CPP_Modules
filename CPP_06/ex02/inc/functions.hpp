/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:43:00 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/20 11:48:13 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
	#define FUNCTIONS_HPP

	#include <iostream>
	#include <string>
	#include <cstdlib>
	#include <sys/time.h>
	#include "A.hpp"
	#include "B.hpp"
	#include "C.hpp"

/* ************************************************************************** */

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

/* ************************************************************************** */

#endif
