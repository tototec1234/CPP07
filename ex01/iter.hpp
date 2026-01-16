/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:53:45 by toruinoue         #+#    #+#             */
/*   Updated: 2026/01/16 18:52:52 by toruinoue        ###   ########.fr       */
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
	// if (func == NULL)	// コメントアウトを外してテストする　テストメニュー  7. コンパイルエラーになるテストケース
	// 	return;				// コメントアウトを外してテストする　テストメニュー  7. コンパイルエラーになるテストケース
	
	/* *************************************************************************** */
	/* T *arryは「ポインタ」であることが確定しているため、NULLチェックOK。				 	*/
	/* FのNULLチェックについて:													      */
	/* 関数名や関数テンプレートのインスタンスは関数ポインタに暗黙的に変換されるため、		 	*/
	/* この実装でも動作する（現在のテストケースでは問題なく動作）。						 	  */
	/* ただし、関数オブジェクト（ファンクタ）で==演算子が定義されていない場合、				   */
	/*  または==演算子がNULLとの比較をサポートしていない場合はコンパイルエラーになる可能性がある。*/
	/* より汎用的な実装にするには、NULLチェックを削除するか、								*/
	/* SFINAEやconcepts（C++20）を使用する必要がある。						 		    */				
	/* *************************************************************************** */
	for (size_t i =0; i < len_array; i++)
		func(arry[i]);
}

// const配列用のオーバーロード
// func が void func(const int& x) なら、arry[i]（const int&型）はそのまま参照として渡される
// func が void func(const int x) なら、arry[i]（const int&型）は値としてコピーされて渡される
// 課題書の「const値として渡される」という記述は、呼び出し側でconst size_tとして定義できることを示しているだけで、
// 関数のパラメータ自体をconstにする必要はありません。値渡しでは、引数の値がコピーされてパラメータに渡されるため、
// 元の変数のconst性は関数パラメータに引き継がれません。これはC++の値渡しの仕様です。
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
