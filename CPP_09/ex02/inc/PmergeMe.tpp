/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:18:04 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 07:08:14 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
	#define PMERGEME_TPP

/* ************************************************************************** */

template <typename T>
void	fordJohnsonAlgorithm(std::vector<T> &argContainer)
{
	std::vector<Pair<T> >	newContainerOfPairs;
	size_t					argContainerSize;
	Pair<T>					pair;
	T						lastOddElement;

	argContainerSize = argContainer.size();
	if (argContainerSize < 2)
		return ;
	for (size_t i = 0; i + 1 < argContainerSize; i += 2)
	{
		pair._a = argContainer[i];
		pair._b = argContainer[i + 1];
		pair.sortDescending();
		newContainerOfPairs.push_back(pair);
	}
	if (argContainerSize % 2 != 0)
		lastOddElement = *(argContainer.end() - 1);
	fordJohnsonAlgorithm<Pair<T> >(newContainerOfPairs);
}

/* ************************************************************************** */

#endif
