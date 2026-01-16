/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/16 15:29:13 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHTEVER_HPP
# define WHTEVER_HPP

template <typename T>
void swap(T &first, T &second){
	T tmp = first;
	first = second;
	second = tmp;
}

template <typename T>
const T& min(const T &first, const T &second){
	return first < second ? first : second;
}

template <typename T>
const T& max(const T &first, const T &second){
	return second < first ? first : second;
}

#endif

