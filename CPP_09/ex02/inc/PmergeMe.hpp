/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:08:35 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/09 15:05:54 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
	#define PMERGEME_HPP
	#include <string>
	#include <iostream>
	#include <cstdlib>
	#include <vector>
	#include <deque>

/* ************************************************************************** */

std::vector<unsigned int>	mergeSort(std::vector<unsigned int> container);
std::vector<unsigned int>	insertionSort(std::vector<unsigned int> container);
std::vector<unsigned int>	mergeInsertionSort(std::vector<unsigned int> container);

/* ************************************************************************** */

	#include "PmergeMe.tpp"

#endif
