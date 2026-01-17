/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/17 20:45:56 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// デフォルトコンストラクタ：空配列を作成
template< typename T >
Array<T>::Array() : _array(NULL), _size(0)
{
	// 空配列の場合はnew[]を呼ばない（new T[0]は未定義動作の可能性がある）
//	std::cout << "Constructor called.\n_size:" << this->_size << "\n" << std::endl;
}

// サイズ指定コンストラクタ：指定サイズの配列を作成
template< typename T >
Array<T>::Array(unsigned int size) : _array(NULL), _size(size)
{
	if (this->_size > 0)
	{
		this->_array = new T[this->_size]();
		// this->_array = new T[this->_size];
		// T()で安全で予測可能な初期化
		// Tがintなら0、charなら'\0'、stringなら空文字列...というように初期化される
		// for (unsigned int i = 0; i < this->_size; i++)
		// 	this->_array[i] = T();
	}
//	std::cout << "Constructor (Array(unsigned int size)) called.\n_size:" << this->_size << "\n" << std::endl;
}

/*
// ⚠️ 注意: C++11以降では有効だが、C++98では不可
Array<T>::Array(unsigned int size) : _array(NULL), _size(size)
{
    if (this->_size > 0)
    {
        this->_array = new T[this->_size]();  // カッコで値初期化
        // ループ不要（全要素が自動的に値初期化される）
    }
}
*/

// コピーコンストラクタ：既存の配列をコピーして新しい配列を作成
template< typename T >
Array<T>::Array(const Array &src) : _array(NULL), _size(src._size)
{
	if (this->_size > 0)
	{
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = src._array[i];
	}
//	std::cout << "Copy constructor called.\n_size:" << this->_size << "\n" << std::endl;
}

// デストラクタ
template< typename T >
Array<T>::~Array()
{
	if (this->_array != NULL)
		delete[] this->_array;
//	std::cout << "Destructor called." << std::endl;
}

// 代入演算子：既存配列に別の配列の内容を代入
template< typename T >
Array<T>& Array<T>::operator=(const Array &src)
{
//	std::cout << "Operator = called." << std::endl;
	if (this == &src)
		return (*this);
	
	if (this->_array != NULL)
		delete[] this->_array;
	
	this->_size = src._size;
	
	if (this->_size > 0)
	{
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = src._array[i];
	}
	else
		this->_array = NULL;
	
	return (*this);
}

// 添字演算子（非const版）：配列要素への読み書きアクセス
template< typename T >
T& Array<T>::operator[](unsigned int index)
{
//	std::cout << "Operator [] called." << std::endl;
	if (index >= this->_size)
		throw InvalidIndexException();
	return this->_array[index];
}

// 添字演算子（const版）：配列要素への読み取り専用アクセス
template< typename T >
const T& Array<T>::operator[](unsigned int index) const
{
//	std::cout << "Operator [] called." << std::endl;
	if (index >= this->_size)
		throw InvalidIndexException();
	return this->_array[index];
}

// 配列内の要素数を返すメンバー関数
template< typename T >
unsigned int Array<T>::size() const
{
	return (this->_size);
}

// 不正なインデックスアクセス時の例外
template< typename T >
const char* Array<T>::InvalidIndexException::what() const throw()
{
	return ("Error: Invalid index");
}
