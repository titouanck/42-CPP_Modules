/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarySearch.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titouanck <chevrier.titouan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:13:00 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 11:49:37 by titouanck        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYSEARCH_TPP
	#define BINARYSEARCH_TPP

/* ************************************************************************** */

template <typename T>
typename std::vector<T>::iterator	binarySearch(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last, const T &toFind)
{
	typename std::vector<T>::iterator	it;

	// std::cout << "binarySearch(): ";
	// for (it = first; it != last; it++)
	// {
	// 	std::cout << *it;
	// 	std::cout << ", ";
	// }
	// std::cout << std::endl;
	(void)	toFind;
	size_t	distance;

	distance = std::distance(first, last - 1);
	if (distance < 2)
	{
		if (*first >= toFind)
			return first;
		else
			return first + 1;
	}
	typename std::vector<T>::iterator	mid;

	mid = first + distance / 2;
	// std::cout << "MID: " << *mid << std::endl;
	if (toFind == *mid)
		return mid;
	else if (toFind < *mid)
		return binarySearch(first, mid, toFind);
	else
		return binarySearch(mid + 1, last, toFind);
}

/* ************************************************************************** */

#endif
