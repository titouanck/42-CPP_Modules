/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:18:04 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 13:09:22 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
	#define PMERGEME_TPP

/* ************************************************************************** */

jacobsthal(unsigned int n1, unsigned int n2)
{
	return (n1 + 2 * n2);
}

template<typename T>
std::vector<T>	insert_pairs(std::vector<Pair<T> > &container, T *lastOddElement)
{
	std::vector<T>								mainChain;
	typename std::vector<T>::iterator			mainChainEnd;
	typename std::vector<Pair<T> >::iterator	containerIt;
	unsigned int	j_lower = 1;
	unsigned int	j_upper = 1;
	
	mainChain.push_back(container[0].get_b());
	mainChain.push_back(container[0].get_a());

	// INSERT ALL A'S, ONE AFTER ANOTHER
	for (containerIt = container.begin() + 1; containerIt != container.end(); containerIt += 1)
	{
		mainChain.push_back(containerIt->get_a());
	}
	if (lastOddElement)
		mainChain.insert(binarySearch(mainChain.begin(), mainChain.end(), *lastOddElement), *lastOddElement);
	// INSERT ALL B'S, WITH BINARY SEARCH
	for (size_t i = 1; i < container.size(); i += 1)
	{
		mainChainEnd = mainChain.end();
		if ()
		mainChain.insert(binarySearch(mainChain.begin(), mainChain.end(), container[i].get_b()), container[i].get_b());
	}
	
	return mainChain;
}

template <unsigned int N>
class recursivity
{
	public:
	template <typename T>
	static void	fordJohnsonAlgorithm(std::vector<T> &argContainer)
	{
		unsigned int			argContainerSize;
		std::vector<Pair<T> >	newContainerOfPairs;
		T						*lastOddElement;

		argContainerSize = argContainer.size();
		if (argContainerSize < 2)
			return ;

		for (size_t i = 0; i + 1 < argContainerSize; i += 2)
		{
			newContainerOfPairs.push_back(Pair<T>(argContainer[i], argContainer[i + 1]));
			newContainerOfPairs[i / 2].sortDescending();
		}
		lastOddElement = NULL;
		if (argContainerSize % 2 != 0)
			lastOddElement = &(*(argContainer.end() - 1));
		recursivity<N - 1>::template fordJohnsonAlgorithm<Pair<T> >(newContainerOfPairs);
		argContainer = insert_pairs(newContainerOfPairs, lastOddElement);
	}
};

template <>
class recursivity<1>
{

public:
	template <typename T>
	static void	fordJohnsonAlgorithm(std::vector<T> &argContainer)
	{
		(void)	argContainer;
	}
};

/* ************************************************************************** */

#endif
