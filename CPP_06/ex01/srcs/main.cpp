/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:16:46 by tchevrie          #+#    #+#             */
/*   Updated: 2023/12/20 12:45:36 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

/* ************************************************************************** */

int	main()
{
	Data	data;

	data.Gentle	= "Podasai";
	data.Mates	= "Snayzy";

	/* ***************************************************** */
	
	Data	*r;
	
	r = Serializer::deserialize(Serializer::serialize(&data));

	/* ***************************************************** */
	
	if (&data == r)
		std::cout << "mission accomplished ! " \
		<< "data's content: " << r->Gentle << " & " << r->Mates \
		<< std::endl;
	else
		std::cout << "mission failed :(" << std::endl;
}

/* ************************************************************************** */
