/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:42:18 by titouanck         #+#    #+#             */
/*   Updated: 2023/12/20 12:43:37 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

/* ************************************************************************** */

int	main(void)
{
	Base	*ptr;

	/* generates a random object A, B or C */
	ptr = generate();

	/* identify class via a pointer */
	identify(ptr);

	/* identify class via a reference */
	identify(*ptr);
}

/* ************************************************************************** */
