/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:16:46 by tchevrie          #+#    #+#             */
/*   Updated: 2023/12/19 11:51:43 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************************************************************** */

int	main()
{
	Data				*ptr;

	std::cout << "--- --- --- ---" << std::endl;

	unsigned long int	serialNumber;
	Data				objData;

	objData.serialNumber = 42;
	serialNumber = Serializer::serialize(&objData);
	ptr = Serializer::deserialize(serialNumber);

	std::cout << "serial number:   " << serialNumber << std::endl;
	std::cout << "objData address: " << &objData << std::endl;
	std::cout << "retuned address: " << ptr << std::endl;

	std::cout << "--- --- --- ---" << std::endl;

	std::cout << "we try to deserialize again" << std::endl;
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

	std::cout << "--- --- --- ---" << std::endl;

	std::cout << "we try to deserialize again" << std::endl;
	ptr = Serializer::deserialize(anotherObjData.serialNumber);
	
	std::cout << "serial number:          " << anotherObjData.serialNumber  << std::endl;
	std::cout << "anotherObjData address: " << &anotherObjData << std::endl;
	std::cout << "retuned address:        " << ptr << std::endl;

	std::cout << "--- --- --- ---" << std::endl;

	std::cout << "Deserialize a non-existing serial number: " << Serializer::deserialize(-42) << std::endl;

	std::cout << "--- --- --- ---" << std::endl;

	std::cout << "Serialize with a NULL address" << std::endl;
	try {
		serialNumber = Serializer::serialize(NULL);
	}
	catch (std::exception &e) {
		std::cout << "CATCH EXCEPTION: " << e.what() << std::endl;
	}

}
