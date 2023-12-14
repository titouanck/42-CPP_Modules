/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:17:42 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/07 20:47:24 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
	#define SERIALIZER_HPP

	#include <iostream>
	#include <string>

	typedef struct s_Data
	{
		unsigned long int	serialNumber;
		struct s_Data		*next;
	}						Data;

	class Serializer
	{
		private:
			Serializer(const Serializer &obj);
			static Data			_lstData;
			

		public:
			class NullPointer;

			Serializer(Data *ptr);
			~Serializer(void);
			Serializer	&operator=(const Serializer &obj);

			static unsigned long int	serialize(Data *ptr);
			static Data					*deserialize(unsigned long int serialNumber);
	};

	class Serializer::NullPointer : public std::exception
	{
		private:
			const char	*_exception;

		public:
			NullPointer(const char *exception);
			const char	*what(void) const throw();
	};

#endif
