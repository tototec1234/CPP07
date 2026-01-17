/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:06:41 by toruinoue         #+#    #+#             */
/*   Updated: 2026/01/17 19:53:50 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template< class T >
class Array
{
	private:
		T*              _array;     // 動的配列のポインタ
		unsigned int    _size;      // 配列のサイズ

	public:
		// デフォルトコンストラクタ：空配列を作成
		Array();
		// サイズ指定コンストラクタ：指定サイズの配列を作成
		Array(unsigned int size);
		// コピーコンストラクタ：既存の配列をコピーして新しい配列を作成
		Array(const Array &src);
		// デストラクタ
		~Array();
		// 代入演算子：既存配列に別の配列の内容を代入
		Array& operator=(const Array &src);
		// 添字演算子（非const版）：配列要素への読み書きアクセス
		T& operator[](unsigned int index);
		// 添字演算子（const版）：配列要素への読み取り専用アクセス
		const T& operator[](unsigned int index) const;
		// 配列内の要素数を返すメンバー関数
		unsigned int size() const;
		// 不正なインデックスアクセス時の例外
		class InvalidIndexException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

# include "Array.tpp"

#endif
