/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:28:24 by tchevrie          #+#    #+#             */
/*   Updated: 2023/07/17 16:38:50 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
	#define PMERGEME_HPP

	#include <iostream>
	#include <string>	
	#include <vector>
	#include <deque>	
	#include <algorithm>

	#define RED "\033[0;31m"
	#define GREEN "\033[0;32m"
	#define BLUE "\033[0;34m"
	#define ORANGE "\033[0;33m"
	#define PURPLE "\033[0;35m"
	#define CYAN "\033[0;36m"
	#define LIGHTGRAY "\033[0;37m"
	#define DARKGRAY "\033[1;30m"
	#define LIGHTRED "\033[1;31m"
	#define LIGHTGREEN "\033[1;32m"
	#define LIGHTBLUE "\033[1;34m"
	#define LIGHTPURPLE "\033[1;35m"
	#define LIGHTCYAN "\033[1;36m"
	#define YELLOW "\033[1;33m"
	#define WHITE "\033[1;37m"
	#define NC "\033[0m"

	void	swap(int *a, int *b);
	void	printContainer(std::vector<int> vct);
	void	printContainerRed(std::vector<int> vct);
	void	printContainerDefault(std::vector<int> vct);
	void	printContainer(std::deque<int> vct);
	void	printContainerRed(std::deque<int> vct);
	void	printContainerDefault(std::deque<int> vct);

	bool	PmergeMe(char **args);

	class PmergeMeException : public std::exception
	{
		private:
			const char	*_e;
		public:
			PmergeMeException(const char *e);
			const char* what() const throw();
	};

#endif
