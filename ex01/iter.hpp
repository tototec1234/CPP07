/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:53:45 by toruinoue         #+#    #+#             */
/*   Updated: 2026/01/16 17:38:45 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

// 非const配列用
// func が void func(int& x) なら、arry[i]（int&型）はそのまま参照として渡される
// func が void func(int x) なら、arry[i]（int&型）は値としてコピーされて渡される
template<typename T,  typename F>
void iter(T *arry, size_t len_array, F func){
	if (arry == NULL)
		return;
	for (size_t i =0; i < len_array; i++)
		func(arry[i]);
}

// const配列用のオーバーロード
// func が void func(const int& x) なら、arry[i]（const int&型）はそのまま参照として渡される
// func が void func(const int x) なら、arry[i]（const int&型）は値としてコピーされて渡される
template<typename T, typename F>
void iter(const T *arry, size_t len_array, F func){
	if (arry == NULL)
		return;
	for (size_t i =0; i < len_array; i++)
		func(arry[i]);
}

#endif

/*

Implement the following function templates:

- The first parameter is the address of an array.
- The second one is the length of the array, passed as a const value.
- The third one is a function that will be called on every element of the array.

Submit a main.cpp file that contains your tests. Provide enough code to generate a test executable.

Your iter function template must work with any type of array. The third parameter can be an instantiated function template.

The function passed as the third parameter may take its argument by const reference or non-const reference, depending on the context.

Think carefully about how to support both const and non-const elements in your iter function.

*/
