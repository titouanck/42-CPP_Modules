/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:28:24 by tchevrie          #+#    #+#             */
/*   Updated: 2023/07/17 17:19:21 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
	#define PMERGEME_HPP

	#include <iostream>
	#include <string>	
	#include <vector>
	#include <deque>	
	#include <algorithm>
	#include <sys/time.h>

	#define RED "\033[0;31m"
	#define BLUE "\033[0;34m"
	#define NC "\033[0m"

	void	swap(int *a, int *b);
	void	printContainer(std::vector<int> vct);
	void	printContainerRed(std::vector<int> vct);
	void	printContainerDefault(std::vector<int> vct);
	void	printContainer(std::deque<int> vct);
	void	printContainerRed(std::deque<int> vct);
	void	printContainerDefault(std::deque<int> vct);

	bool	PmergeMe(int argc, char **args);

	class PmergeMeException : public std::exception
	{
		private:
			const char	*_e;
		public:
			PmergeMeException(const char *e);
			const char* what() const throw();
	};

#endif
