/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:18:04 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 12:44:32 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
	#define PMERGEME_TPP

/* ************************************************************************** */

template<typename T>
std::vector<T>	insert_pairs(std::vector<Pair<T> > &container, T *lastOddElement)
{
	std::vector<T>								mainChain;
	typename std::vector<Pair<T> >::iterator	it;
	
	mainChain.push_back(container[0].get_b());
	mainChain.push_back(container[0].get_a());
	if (container.size() == 1 && lastOddElement != NULL)
		mainChain.insert(binarySearch(mainChain.begin(), mainChain.end(), *lastOddElement), *lastOddElement);
	if (container.size() < 2)
		return mainChain;
	for (it = container.begin() + 1; it != container.end(); it += 1)
	{
		mainChain.push_back(it->get_a());
	}
	if (lastOddElement)
		mainChain.insert(binarySearch(mainChain.begin(), mainChain.end(), *lastOddElement), *lastOddElement);
	for (size_t i = 1; i < container.size(); i += 1)
		mainChain.insert(binarySearch(mainChain.begin(), mainChain.end(), container[i].get_b()), container[i].get_b());
	
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
