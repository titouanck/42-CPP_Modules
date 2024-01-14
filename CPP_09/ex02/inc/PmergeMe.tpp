/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:18:04 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 11:50:50 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
	#define PMERGEME_TPP

/* ************************************************************************** */

template<typename T>
std::vector<T>	insert_pairs(std::vector<Pair<T> > &container, T *lastOddElement)
{
	std::cout << "Just entered insert_pairs() with: ";
	for (typename std::vector<Pair<T> >::iterator it2 = container.begin(); it2 != container.end(); it2++)
	{
		std::cout << *it2 << ", ";
	}
	std::cout << std::endl << std::endl;
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
	std::cout << "Just added A's with: ";
	for (typename std::vector<T>::iterator it2 = mainChain.begin(); it2 != mainChain.end(); it2++)
	{
		std::cout << *it2 << ", ";
	}
	std::cout << std::endl << std::endl;
	// for (size_t i = 1; i < container.size(); i += 1)
	// 	mainChain.insert(binarySearch(mainChain.begin(), mainChain.end(), container[i].get_b()), container[i].get_b());
	
	std::cout << std::endl << "INSERPRINT: ";
	for (typename std::vector<T>::iterator it2 = mainChain.begin(); it2 != mainChain.end(); it2++)
	{
		std::cout << *it2 << ", ";
	}
	std::cout << std::endl;
	
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
			std::cout << "Creating a pair for [" << argContainer[i] << ", " << argContainer[i + 1] << "]" << std::endl;
			newContainerOfPairs.push_back(Pair<T>(argContainer[i], argContainer[i + 1]));
			newContainerOfPairs[i / 2].sortDescending();
			std::cout << newContainerOfPairs[i / 2] << std::endl;
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
