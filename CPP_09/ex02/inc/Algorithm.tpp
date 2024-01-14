/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:18:04 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 18:45:55 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_TPP
	#define ALGORITHM_TPP

/* ************************************************************************** */

int	jacobsthal(int n1, int n2)
{
	return (n1 + 2 * n2);
}

/* VECTOR ******************************************************************* */

template<typename T>
std::vector<T>	insertPairs(std::vector<Pair<T> > &container, T *lastOddElement)
{
	std::vector<T>								mainChain;
	typename std::vector<T>::iterator			mainChainLast;
	typename std::vector<Pair<T> >::iterator	containerIt;
	int											j_lower;
	int											j_upper;
	int											tmp;
	
	mainChain.push_back(container[0].get_b());
	mainChain.push_back(container[0].get_a());

	// INSERT ALL A'S, ONE AFTER ANOTHER
	for (containerIt = container.begin() + 1; containerIt != container.end(); containerIt += 1)
	{
		mainChain.push_back(containerIt->get_a());
	}

	// INSERT LAST ELEMENT IF ODD NUMBER OF ELEMS
	if (lastOddElement)
		mainChain.insert(binarySearch(mainChain.begin(), mainChain.end(), *lastOddElement), *lastOddElement);

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
			if (j_upper == static_cast<int>(container.size()))
				mainChainLast = mainChain.end();
			else
				mainChainLast = mainChain.begin() + j_upper + j_lower - 1;
			mainChain.insert(binarySearch(mainChain.begin(), mainChainLast, container[i].get_b()), container[i].get_b());
		}
	}
	return mainChain;
}

template <unsigned int N>
template <typename T>
void	Algorithm<N>::fordJohnson(std::vector<T> &argContainer)
{
	unsigned int			argContainerSize;
	std::vector<Pair<T> >	newContainerOfPairs;
	T						*lastOddElement;

	argContainerSize = argContainer.size();
	if (argContainerSize < 2)
		return ;

	// CREATE NEW CONTAINER OF PAIRS, CONTAINING CONTENT OF ARGCONTAINER. IF argContainer.size() IS ODD : LAST NUMBER DON'T GO INSIDE NEW CONTAINER
	for (size_t i = 0; i + 1 < argContainerSize; i += 2)
	{
		newContainerOfPairs.push_back(Pair<T>(argContainer[i], argContainer[i + 1]));
		newContainerOfPairs[i / 2].sortDescending();
	}
	lastOddElement = nullptr;
	if (argContainerSize % 2 != 0)
		lastOddElement = &(*(argContainer.end() - 1));

	// CALL ITSELF, GIVING ITSELF A CONTAINER OF PAIRS, THEN A CONTAINER OF PAIRS OF PAIRS, THEN A CONTAINER OF PAIRS OF PAIRS OF PAIRS...
	Algorithm<N - 1>::template fordJohnson<Pair<T> >(newContainerOfPairs);
	argContainer = insertPairs(newContainerOfPairs, lastOddElement);
}

/* DEQUE ******************************************************************** */

template<typename T>
std::deque<T>	insertPairs(std::deque<Pair<T> > &container, T *lastOddElement)
{
	std::deque<T>								mainChain;
	typename std::deque<T>::iterator			mainChainLast;
	typename std::deque<Pair<T> >::iterator	containerIt;
	int											j_lower;
	int											j_upper;
	int											tmp;
	
	mainChain.push_back(container[0].get_b());
	mainChain.push_back(container[0].get_a());

	// INSERT ALL A'S, ONE AFTER ANOTHER
	for (containerIt = container.begin() + 1; containerIt != container.end(); containerIt += 1)
	{
		mainChain.push_back(containerIt->get_a());
	}

	// INSERT LAST ELEMENT IF ODD NUMBER OF ELEMS
	if (lastOddElement)
		mainChain.insert(binarySearch(mainChain.begin(), mainChain.end(), *lastOddElement), *lastOddElement);

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
			if (j_upper == static_cast<int>(container.size()))
				mainChainLast = mainChain.end();
			else
				mainChainLast = mainChain.begin() + j_upper + j_lower - 1;
			mainChain.insert(binarySearch(mainChain.begin(), mainChainLast, container[i].get_b()), container[i].get_b());
		}
	}
	return mainChain;
}


template <unsigned int N>
template <typename T>
void	Algorithm<N>::fordJohnson(std::deque<T> &argContainer)
{
	unsigned int			argContainerSize;
	std::deque<Pair<T> >	newContainerOfPairs;
	T						*lastOddElement;

	argContainerSize = argContainer.size();
	if (argContainerSize < 2)
		return ;

	// CREATE NEW CONTAINER OF PAIRS, CONTAINING CONTENT OF ARGCONTAINER. IF argContainer.size() IS ODD : LAST NUMBER DON'T GO INSIDE NEW CONTAINER
	for (size_t i = 0; i + 1 < argContainerSize; i += 2)
	{
		newContainerOfPairs.push_back(Pair<T>(argContainer[i], argContainer[i + 1]));
		newContainerOfPairs[i / 2].sortDescending();
	}
	lastOddElement = nullptr;
	if (argContainerSize % 2 != 0)
		lastOddElement = &(*(argContainer.end() - 1));

	// CALL ITSELF, GIVING ITSELF A CONTAINER OF PAIRS, THEN A CONTAINER OF PAIRS OF PAIRS, THEN A CONTAINER OF PAIRS OF PAIRS OF PAIRS...
	Algorithm<N - 1>::template fordJohnson<Pair<T> >(newContainerOfPairs);
	argContainer = insertPairs(newContainerOfPairs, lastOddElement);
}

/* ************************************************************************** */

template <>
struct Algorithm<1>
{

public:
	template <typename T>
	static void	fordJohnson(std::vector<T> &argContainer)
	{
		(void)	argContainer;
	}
	
	template <typename T>
	static void	fordJohnson(std::deque<T> &argContainer)
	{
		(void)	argContainer;
	}
};

/* ************************************************************************** */

#endif
