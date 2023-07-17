/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:28:48 by tchevrie          #+#    #+#             */
/*   Updated: 2023/07/17 16:37:13 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMeException::PmergeMeException(const char *e) : _e(e)
{}

const char	*PmergeMeException::what() const throw()
{
	return (_e);
}

template <typename Tcontainer>
Tcontainer	recursivity(Tcontainer vct)
{
	typename Tcontainer::iterator	first;
	typename Tcontainer::iterator	last;
	size_t						i;
	size_t						j;

	while (vct.size() < 4)
		return (vct);
	first = vct.begin();
	last = vct.begin() + vct.size() / 2;
	if ((vct.size() / 2) % 2 != 0)
		last += 1;
	Tcontainer	leftVct(first, last);

	first = last;
	last = vct.end();
	Tcontainer	rightVct(first, last);

	leftVct = recursivity(leftVct);
	rightVct = recursivity(rightVct);

	std::cout << "A: ";
	printContainer(leftVct);
	std::cout << "B: ";
	printContainer(rightVct);

	i = 1;
	j = 1;
	while (j < rightVct.size())
	{
		while (*(rightVct.begin() + j) > *(leftVct.begin() + i) && i < leftVct.size())
			i += 2;
		leftVct.insert(leftVct.begin() + i - 1, rightVct.begin() + j - 1, rightVct.begin() + j + 1);
		i += 2;
		j += 2;
	}
	if (rightVct.size() % 2 != 0)
		leftVct.push_back(*(rightVct.end() - 1));
	std::cout << "FUSION: ";
	printContainer(leftVct);
	return (leftVct);
}

template <typename Tcontainer>
void	sort(Tcontainer &vct)
{
	if (vct.size() < 2)
		return ;
	std::cout << "\nORIGINAL: ";
	std::cout << BLUE;
	printContainerDefault(vct);
	std::cout << NC;
	for (typename Tcontainer::iterator it = vct.begin(); it != vct.end(); it += 2)
	{
		if (it + 1 == vct.end())
			break ;
		if (*it > *(it + 1))
			swap(&(*it), &(*(it + 1)));
	}
	std::cout << "\nPAIRES TRIÉES: ";
	printContainer(vct);
	std::cout << '\n';
	vct = recursivity(vct);
	
	std::cout << "\nAPRES RECURSIVITE: ";
	printContainer(vct);

	Tcontainer	oddVct(vct);
	Tcontainer	evenVct(vct);
	
	for (int i = vct.size() - 1; i >= 0; i--)
	{
		if (i % 2 == 0)
			oddVct.erase(oddVct.begin() + i);
		else
			evenVct.erase(evenVct.begin() + i);
	}

	std::cout << "\nODD: ";
	printContainerRed(oddVct);
	std::cout << "EVEN: ";
	printContainerDefault(evenVct);

	while (evenVct.size() > 0)
	{
		typename Tcontainer::iterator it;
		for (it = oddVct.begin(); it != oddVct.end(); it++)
		{
			if (*evenVct.begin() < *it)
				break ;
		}
		oddVct.insert(it, evenVct.begin(), evenVct.begin() + 1);
		evenVct.erase(evenVct.begin());
	}
	vct = oddVct;
}

int	PmergeMeAtoi(std::string arg)
{
	long	nbr;

	nbr = 0;
	if (arg.length() < 1)
		throw PmergeMeException("Empty argument.");
	for (size_t i = 0; arg[i]; i++)
	{
		if (!isdigit(arg[i]))
			throw PmergeMeException("Not a positive number.");
		nbr *= 10;
		nbr += arg[i] - '0';
		if (nbr > 2147483647)
			throw PmergeMeException("Too big of a number.");
	}
	return (nbr);
}

bool	PmergeMe(char **args)
{
	std::vector<int>	vct;
	std::deque<int>		dqe;
	int							nbr;

	for (int i = 0; args[i]; i++)
	{
		try
		{
			nbr = PmergeMeAtoi(args[i]);
			if (std::find(vct.begin(), vct.end(), nbr) != vct.end())
				return (std::cerr << "Error with `" << args[i] << "`.\n" << "Number present multiple times." << '\n', false);
			vct.push_back(nbr);
			dqe.push_back(nbr);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error with `" << args[i] << "`.\n" << e.what() << '\n';
			return (false);
		}
	}
	sort(vct);
	std::cout << "\nSORTED: ";
	std::cout << BLUE;
	printContainerDefault(vct);
	std::cout << NC;
	
	std::cout << "\n----------\n";

	sort(dqe);
	std::cout << "\nSORTED: ";
	std::cout << BLUE;
	printContainerDefault(dqe);
	std::cout << NC;

	return (true);
}
