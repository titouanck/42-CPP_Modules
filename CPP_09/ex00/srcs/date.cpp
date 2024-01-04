/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:19 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/04 17:31:43 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "date.hpp"

#define ODD_MONTH	(month % 2 == 1)
#define EVEN_MONTH	(month % 2 == 0)
#define LEAP_YEAR	((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)

/* ************************************************************************** */

static unsigned int	getDay(unsigned int &date)
{
	unsigned int	day;

	day = date % 100;
	date -= day;
	return day;
}

static unsigned int	getMonth(unsigned int &date)
{
	unsigned int	month;

	month = date % 10000;
	date -= month;
	month /= 100;
	return month;
}

static unsigned int	getYear(unsigned int &date)
{
	unsigned int	year;

	year = date;
	year /= 10000;
	return year;
}

/* ************************************************************************** */

#include <iostream>

bool	existingDate(unsigned int date)
{
	unsigned int	day   = getDay(date);
	unsigned int	month = getMonth(date);
	unsigned int	year  = getYear(date);

	if (month == 0 || day == 0)
		return false;

	if ((ODD_MONTH	&&	month >= 1	&&	month <= 7	&&	day <= 31) \
	|| (EVEN_MONTH	&&	month >= 8	&&	month <= 12 &&	day <= 31))
		return true;

	if (month != 2	&&	month >= 1	&&	month <= 12 &&	day <= 30)
		return true;

	if (LEAP_YEAR	&&	month == 2	&&	day <= 29)
		return true;

	if (!LEAP_YEAR	&&	month == 2	&&	day <= 28)
		return true;

	return false;
}

/* ************************************************************************** */
