/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:00:06 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/07 18:12:16 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
	#define SCALARCONVERTER_HPP

	#include <iostream>
	#include <string>
	#include <climits>
	#include <cstdlib>
	#include <cfloat>
	#include <iomanip>

	enum inputType { noType, charType, intType, floatType, doubleType };
	enum displayability { Non_displayable, Impossible, Displayable };

	typedef struct s_convert
	{
		char			charNbr;
		int				intNbr;
		double			doubleNbr;
		float			floatNbr;
		displayability	charDis;
		displayability	intDis;
		displayability	doubleDis;
		displayability	floatDis;
	}					t_convert;

	class ScalarConverter
	{
		private:
			static bool	isChar(std::string str, int len, char &nbr);
			static bool	isInt(std::string str, int len, int &nbr);
			static bool	isDouble(const char *input, int len, double &nbr);
			static bool	isFloat(const char *input, int len, float &nbr, double &dnbr);
			static void	setDisplayability(inputType type, t_convert &tnbr);
			static void	castNbr(inputType type, t_convert &tnbr);
			static void	print(t_convert &tnbr);
		
		public:
			ScalarConverter(const char *str);
			ScalarConverter(const ScalarConverter &obj);
			~ScalarConverter(void);
			ScalarConverter	&operator=(const ScalarConverter &obj);

			static void	convert(const char *input);

			const char	*_input;
			void		convertIt(void);
	};

#endif
