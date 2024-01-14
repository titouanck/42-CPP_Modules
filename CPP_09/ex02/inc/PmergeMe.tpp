/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:18:04 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 15:38:15 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
	#define PMERGEME_TPP

/* ************************************************************************** */

int	jacobsthal(int n1, int n2)
{
	return (n1 + 2 * n2);
}

template<typename T>
std::vector<T>	insert_pairs(std::vector<Pair<T> > &container, T *lastOddElement)
{
	std::vector<T>								mainChain;
	typename std::vector<T>::iterator			mainChainLast;
	typename std::vector<Pair<T> >::iterator	containerIt;
	int											j_lower;
	int											j_upper;
	int											tmp;
	
	std::cout << "container[0]: " << container[0] << std::endl << std::endl;
	
	mainChain.push_back(container[0].get_b());
	mainChain.push_back(container[0].get_a());

	// std::cout << "mainChain BEGIN: ";
	// for (typename std::vector<T>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
	// 	std::cout << *it << ",_, ";
	// std::cout << std::endl << std::endl;

	// INSERT ALL A'S, ONE AFTER ANOTHER
	for (containerIt = container.begin() + 1; containerIt != container.end(); containerIt += 1)
	{
		mainChain.push_back(containerIt->get_a());
	}

	std::cout << "mainChain AFTER_ALL_A'S: ";
	for (typename std::vector<T>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
		std::cout << *it << ",_, ";
	std::cout << std::endl << std::endl;
	
	if (lastOddElement)
		mainChain.insert(binarySearch(mainChain.begin(), mainChain.end(), *lastOddElement), *lastOddElement);

	std::cout << "mainChain INSERT_LAST_OLD_ELEMENT: ";
	for (typename std::vector<T>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
		std::cout << *it << ",_, ";
	std::cout << std::endl << std::endl;

	// INSERT ALL B'S, WITH BINARY SEARCH
	j_lower	= 1;
	j_upper	= 1;
	tmp		= 1;
	while (j_upper < static_cast<int>(container.size()))
	{
		tmp = j_lower;
		j_lower = j_upper;
		j_upper = std::min(jacobsthal(j_lower, tmp), static_cast<int>(container.size()));
		for (int i = j_upper - 1; i >= j_lower; i--)
		{
			std::cout << "B TO PUT: " << container[i].get_b() << std::endl;
			std::cout << "j_lower= " << j_lower << std::endl;
			std::cout << "j_upper= " << j_upper << std::endl;
			std::cout << "container.size()= " << static_cast<int>(container.size()) << std::endl;
			if (j_upper == static_cast<int>(container.size()))
				mainChainLast = mainChain.end();
			else
				mainChainLast = mainChain.begin() + j_upper + j_lower - 1;
			std::cout << "mainChainLast: " << *(mainChainLast - 1) << std::endl;
			mainChain.insert(binarySearch(mainChain.begin(), mainChainLast, container[i].get_b()), container[i].get_b());
		}
	}

	std::cout << "mainChain AFTER ALL B'S: ";
	for (typename std::vector<T>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
		std::cout << *it << ",_, ";
	std::cout << std::endl << std::endl;

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
		
		std::cout << "newContainerOfPairs: ";
		for (typename std::vector<Pair<T> >::iterator it = newContainerOfPairs.begin(); it != newContainerOfPairs.end(); it++)
			std::cout << *it << ",_, ";
		std::cout << std::endl << std::endl;

		recursivity<N - 1>::template fordJohnsonAlgorithm<Pair<T> >(newContainerOfPairs);
		
		// std::cout << "newContainerOfPairs: ";
		// for (typename std::vector<Pair<T> >::iterator it = newContainerOfPairs.begin(); it != newContainerOfPairs.end(); it++)
		// 	std::cout << *it << ",_, ";
		// std::cout << std::endl << std::endl;
		
		argContainer = insert_pairs(newContainerOfPairs, lastOddElement);
		
		// std::cout << "argContainer: ";
		// for (typename std::vector<T>::iterator it = argContainer.begin(); it != argContainer.end(); it++)
		// 	std::cout << *it << ",_, ";
		// std::cout << std::endl << std::endl;
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
