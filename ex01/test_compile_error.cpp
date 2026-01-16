/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_compile_error.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:35:00 by toruinoue         #+#    #+#             */
/*   Updated: 2026/01/16 18:35:00 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* このファイルは、iter.hppで func == NULL のチェックがある場合、
 * コンパイルエラーになることを確認するためのテストファイルです。
 * コンパイルするには: c++ -Wall -Wextra -Werror -std=c++98 test_compile_error.cpp iter.hpp
 */

#include "iter.hpp"
#include <iostream>

/* ==演算子が定義されていない関数オブジェクト（ファンクタ） */
struct PrintFunctor {
	void operator()(int x) const {
		std::cout << x << " ";
	}
	/* ==演算子が定義されていないため、func == NULL のチェックでコンパイルエラーになる */
};

int main(void) {
	int arr[] = {1, 2, 3};
	const size_t size = sizeof(arr) / sizeof(int);
	
	PrintFunctor printer;
	/* この行でコンパイルエラーになるはず:
	 * error: no match for 'operator==' (operand types are 'PrintFunctor' and 'long int')
	 */
	::iter(arr, size, printer);
	
	return 0;
}
