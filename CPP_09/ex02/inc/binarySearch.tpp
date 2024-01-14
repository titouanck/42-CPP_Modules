/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarySearch.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:13:00 by titouanck         #+#    #+#             */
/*   Updated: 2024/01/14 19:47:12 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYSEARCH_TPP
	#define BINARYSEARCH_TPP

/* ************************************************************************** */

template <typename T>
typename std::vector<T>::iterator	binarySearch(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last, const T &toFind)
{
	size_t								distance;
	typename std::vector<T>::iterator	mid;

	distance = std::distance(first, last - 1);
	if (distance < 2)
	{
		if (*first >= toFind)
			return first;
		else if (distance == 1 && *(first + 1) >= toFind)
			return first + 1;
		else
			return first + 2;
	}

	mid = first + distance / 2;
	if (toFind == *mid)
		return mid;
	else if (toFind < *mid)
		return binarySearch(first, mid, toFind);
	else
		return binarySearch(mid + 1, last, toFind);
}

template <typename T>
typename std::deque<T>::iterator	binarySearch(typename std::deque<T>::iterator first, typename std::deque<T>::iterator last, const T &toFind)
{
	size_t								distance;
	typename std::deque<T>::iterator	mid;

	distance = std::distance(first, last - 1);
	if (distance < 2)
	{
		if (*first >= toFind)
			return first;
		else if (distance == 1 && *(first + 1) >= toFind)
			return first + 1;
		else
			return first + 2;
	}

	mid = first + distance / 2;
	if (toFind == *mid)
		return mid;
	else if (toFind < *mid)
		return binarySearch(first, mid, toFind);
	else
		return binarySearch(mid + 1, last, toFind);
}

/* ************************************************************************** */

#endif
