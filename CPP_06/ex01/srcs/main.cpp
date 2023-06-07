/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:16:46 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/07 20:57:35 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


int	main()
{
	unsigned long int	serialNumber;
	Data				*ptr;

	std::cout << "--- --- --- ---" << std::endl;

	Data				objData;

	objData.serialNumber = 42;
	serialNumber = Serializer::serialize(&objData);
	ptr = Serializer::deserialize(serialNumber);

	std::cout << "serial number:   " << serialNumber << std::endl;
	std::cout << "objData address: " << &objData << std::endl;
	std::cout << "retuned address: " << ptr << std::endl;

	std::cout << "--- --- --- ---" << std::endl;

	Data				anotherObjData;
	Serializer			objSerializer(&anotherObjData);

	anotherObjData.serialNumber = 4815162342;
	ptr = Serializer::deserialize(anotherObjData.serialNumber);

	std::cout << "serial number:          " << anotherObjData.serialNumber  << std::endl;
	std::cout << "anotherObjData address: " << &anotherObjData << std::endl;
	std::cout << "retuned address:        " << ptr << std::endl;
}
