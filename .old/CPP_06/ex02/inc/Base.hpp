/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:15:02 by tchevrie          #+#    #+#             */
/*   Updated: 2023/06/08 12:16:22 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
	#define BASE_HPP

	class Base
	{
		public:
			virtual ~Base(void);
	};

	class A : public Base
	{};

	class B : public Base
	{};

	class C : public Base
	{};

#endif
