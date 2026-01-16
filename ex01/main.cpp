/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:00:00 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/16 18:41:21 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include "AnsiColor.hpp"
#include "iter.hpp"

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

// ===== テスト用の関数 =====

// 非const参照を受け取る関数（値を変更）
void increment_int(int &value){	value++;}

// const参照を受け取る関数（読み取り専用）
void print_int(const int &value){	std::cout << value << " ";}

// 値渡しで受け取る関数
void print_int_by_value(int value){	std::cout << value << " ";}

// string型用の関数
void print_string(const std::string &str){	std::cout << str << " ";}

void uppercase_string(std::string &str){
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

// float型用の関数
void print_float(const float &value){	std::cout << value << " ";}

void multiply_float(float &value){	value *= 2.0f;}

// 関数テンプレート（インスタンス化された関数テンプレートのテスト用）
template<typename T>
void print_template(const T &value)
{
	std::cout << value << " ";
}

// ===== テスト関数 =====

void printMenu(void);
void testNonConstIntArray(void);
void testConstIntArray(void);
void testStringArray(void);
void testFloatArray(void);
void testFunctionTemplate(void);
void testValueVsReference(void);
void testCompileErrorCase(void);

int main(void) {
	std::string choice;

	std::cout << CYAN_COLOR << "\n=== CPP07 Exercise 01: Iter ===" << RESET_COLOR << std::endl;
	std::cout << GREEN_COLOR << "iter関数テンプレートのテストメニュー" << RESET_COLOR << std::endl;

	while (true) {
		printMenu();
		std::cout << YELLOW_COLOR << "選択してください: " << RESET_COLOR;
		std::getline(std::cin, choice);

		if (choice.empty()) {
			std::cout << RED_COLOR << "無効な選択です。もう一度入力してください。" << RESET_COLOR << std::endl;
			continue;
		}

		switch (choice[0]) {
			case '1':
				testNonConstIntArray();
				break;
			case '2':
				testConstIntArray();
				break;
			case '3':
				testStringArray();
				break;
			case '4':
				testFloatArray();
				break;
			case '5':
				testFunctionTemplate();
				break;
			case '6':
				testValueVsReference();
				break;
			case '7':
				testCompileErrorCase();
				break;
			case '0':
				std::cout << CYAN_COLOR << "\nプログラムを終了します。" << RESET_COLOR << std::endl;
				return 0;
			default:
				std::cout << RED_COLOR << "無効な選択です。0-7の数字を入力してください。" << RESET_COLOR << std::endl;
				break;
		}
		std::cout << std::endl;
	}
}

void printMenu(void) {
	std::cout << "\n" << BOLD_BLUE_COLOR << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET_COLOR << std::endl;
	std::cout << BOLD_GREEN_COLOR << " テストメニュー" << RESET_COLOR << std::endl;
	std::cout << BOLD_BLUE_COLOR << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET_COLOR << std::endl;
	std::cout << "  " << CYAN_COLOR << "1" << RESET_COLOR << ". 非const配列のテスト (int型、変更操作)" << std::endl;
	std::cout << "  " << CYAN_COLOR << "2" << RESET_COLOR << ". const配列のテスト (int型、読み取り専用)" << std::endl;
	std::cout << "  " << CYAN_COLOR << "3" << RESET_COLOR << ". string型配列のテスト" << std::endl;
	std::cout << "  " << CYAN_COLOR << "4" << RESET_COLOR << ". float型配列のテスト" << std::endl;
	std::cout << "  " << CYAN_COLOR << "5" << RESET_COLOR << ". 関数テンプレートのテスト" << std::endl;
	std::cout << "  " << CYAN_COLOR << "6" << RESET_COLOR << ". 値渡しと参照渡しのテスト" << std::endl;
	std::cout << "  " << CYAN_COLOR << "7" << RESET_COLOR << ". コンパイルエラーになるテストケース" << std::endl;
	std::cout << "  " << RED_COLOR << "0" << RESET_COLOR << ". 終了" << std::endl;
	std::cout << BOLD_BLUE_COLOR << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET_COLOR << std::endl;
}

void testNonConstIntArray(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 1: 非const配列のテスト (int型、変更操作) ===" << RESET_COLOR << std::endl;
	
	int int_array[] = {1, 2, 3, 4, 5};
	const size_t int_size = sizeof(int_array) / sizeof(int);
	
	std::cout << "初期値: ";
	::iter(int_array, int_size, print_int);
	std::cout << std::endl;
	
	std::cout << CYAN_COLOR << "increment_int関数を適用（各要素を+1）..." << RESET_COLOR << std::endl;
	::iter(int_array, int_size, increment_int);
	
	std::cout << "変更後: ";
	::iter(int_array, int_size, print_int);
	std::cout << std::endl;
	
	std::cout << GREEN_COLOR << "✓ 非const配列での変更操作が正常に動作しました" << RESET_COLOR << std::endl;
}

void testConstIntArray(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 2: const配列のテスト (int型、読み取り専用) ===" << RESET_COLOR << std::endl;
	
	const int const_array[] = {10, 20, 30, 40, 50};
	const size_t const_size = sizeof(const_array) / sizeof(int);
	
	std::cout << "const配列の内容: ";
	::iter(const_array, const_size, print_int);
	std::cout << std::endl;
	
	std::cout << CYAN_COLOR << "const配列は読み取り専用です（変更操作はコンパイルエラーになります）" << RESET_COLOR << std::endl;
	std::cout << GREEN_COLOR << "✓ const配列用のオーバーロードが正常に動作しました" << RESET_COLOR << std::endl;
	
	// std::cout << "const配列にincrement_int関数を適用（各要素を+1）... ";
	// ::iter(const_array, const_size, increment_int);
	// std::cout << std::endl;
	
	std::cout << CYAN_COLOR << "const配列は読み取り専用です（変更操作はコンパイルエラーになります）" << RESET_COLOR << std::endl;
}

void testStringArray(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 3: string型配列のテスト ===" << RESET_COLOR << std::endl;
	
	std::string str_array[] = {"hello", "world", "cpp", "template"};
	const size_t str_size = sizeof(str_array) / sizeof(std::string);
	
	std::cout << "初期値: ";
	::iter(str_array, str_size, print_string);
	std::cout << std::endl;
	
	std::cout << CYAN_COLOR << "uppercase_string関数を適用（大文字に変換）..." << RESET_COLOR << std::endl;
	::iter(str_array, str_size, uppercase_string);
	
	std::cout << "変更後: ";
	::iter(str_array, str_size, print_string);
	std::cout << std::endl;
	
	std::cout << GREEN_COLOR << "✓ string型配列での操作が正常に動作しました" << RESET_COLOR << std::endl;
}

void testFloatArray(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 4: float型配列のテスト ===" << RESET_COLOR << std::endl;
	
	float float_array[] = {1.5f, 2.5f, 3.5f, 4.5f};
	const size_t float_size = sizeof(float_array) / sizeof(float);
	
	std::cout << "初期値: ";
	::iter(float_array, float_size, print_float);
	std::cout << std::endl;
	
	std::cout << CYAN_COLOR << "multiply_float関数を適用（各要素を2倍）..." << RESET_COLOR << std::endl;
	::iter(float_array, float_size, multiply_float);
	
	std::cout << "変更後: ";
	::iter(float_array, float_size, print_float);
	std::cout << std::endl;
	
	std::cout << GREEN_COLOR << "✓ float型配列での操作が正常に動作しました" << RESET_COLOR << std::endl;
}

void testFunctionTemplate(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 5: 関数テンプレートのテスト ===" << RESET_COLOR << std::endl;
	
	std::cout << BOLD_YELLOW_COLOR << "--- int型配列で関数テンプレートを使用 ---" << RESET_COLOR << std::endl;
	int int_array[] = {100, 200, 300};
	const size_t int_size = sizeof(int_array) / sizeof(int);
	std::cout << "int配列: ";
	::iter(int_array, int_size, print_template<int>);
	std::cout << std::endl;
	
	std::cout << BOLD_YELLOW_COLOR << "--- string型配列で関数テンプレートを使用 ---" << RESET_COLOR << std::endl;
	std::string str_array[] = {"template", "function", "test"};
	const size_t str_size = sizeof(str_array) / sizeof(std::string);
	std::cout << "string配列: ";
	::iter(str_array, str_size, print_template<std::string>);
	std::cout << std::endl;
	
	std::cout << BOLD_YELLOW_COLOR << "--- float型配列で関数テンプレートを使用 ---" << RESET_COLOR << std::endl;
	float float_array[] = {1.1f, 2.2f, 3.3f};
	const size_t float_size = sizeof(float_array) / sizeof(float);
	std::cout << "float配列: ";
	::iter(float_array, float_size, print_template<float>);
	std::cout << std::endl;
	
	std::cout << GREEN_COLOR << "✓ 関数テンプレート（インスタンス化された関数テンプレート）が正常に動作しました" << RESET_COLOR << std::endl;
}

void testValueVsReference(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 6: 値渡しと参照渡しのテスト ===" << RESET_COLOR << std::endl;
	
	int int_array[] = {1, 2, 3};
	const size_t int_size = sizeof(int_array) / sizeof(int);
	
	std::cout << BOLD_YELLOW_COLOR << "--- const参照で受け取る関数を使用 ---" << RESET_COLOR << std::endl;
	std::cout << "配列の内容: ";
	::iter(int_array, int_size, print_int);
	std::cout << std::endl;
	std::cout << CYAN_COLOR << "  → print_int(const int&) が呼ばれます" << RESET_COLOR << std::endl;
	
	std::cout << BOLD_YELLOW_COLOR << "--- 値渡しで受け取る関数を使用 ---" << RESET_COLOR << std::endl;
	std::cout << "配列の内容: ";
	::iter(int_array, int_size, print_int_by_value);
	std::cout << std::endl;
	std::cout << CYAN_COLOR << "  → print_int_by_value(int) が呼ばれます（値としてコピーされます）" << RESET_COLOR << std::endl;
	
	std::cout << BOLD_YELLOW_COLOR << "--- 非const参照で受け取る関数を使用（変更操作） ---" << RESET_COLOR << std::endl;
	std::cout << "変更前: ";
	::iter(int_array, int_size, print_int);
	std::cout << std::endl;
	::iter(int_array, int_size, increment_int);
	std::cout << "変更後: ";
	::iter(int_array, int_size, print_int);
	std::cout << std::endl;
	std::cout << CYAN_COLOR << "  → increment_int(int&) が呼ばれます（参照で変更されます）" << RESET_COLOR << std::endl;
	
	std::cout << GREEN_COLOR << "✓ 値渡しと参照渡しの両方が正常に動作しました" << RESET_COLOR << std::endl;
}

// ==演算子が定義されていない関数オブジェクト（ファンクタ）
struct PrintFunctor {
	void operator()(int x) const {
		std::cout << x << " ";
	}
	// ==演算子が定義されていないため、func == NULL のチェックでコンパイルエラーになる
};

void testCompileErrorCase(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 7: コンパイルエラーになるテストケース ===" << RESET_COLOR << std::endl;
	
	std::cout << BOLD_YELLOW_COLOR << "\n【テスト方法】" << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "iter.hpp の以下のコメントアウトを外してテストしてください:" << RESET_COLOR << std::endl;
	std::cout << YELLOW_COLOR << "  // if (func == NULL)" << RESET_COLOR << std::endl;
	std::cout << YELLOW_COLOR << "  //     return;" << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "↓" << RESET_COLOR << std::endl;
	std::cout << GREEN_COLOR << "  if (func == NULL)" << RESET_COLOR << std::endl;
	std::cout << GREEN_COLOR << "      return;" << RESET_COLOR << std::endl;
	
	std::cout << BOLD_YELLOW_COLOR << "\n【テスト内容】" << RESET_COLOR << std::endl;
	std::cout << "==演算子が定義されていない関数オブジェクト（ファンクタ）をiter関数に渡します。" << std::endl;
	std::cout << "iter.hppで func == NULL のチェックが有効な場合、コンパイルエラーになります。" << std::endl;
	
	std::cout << BOLD_YELLOW_COLOR << "\n【テストコード】" << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "struct PrintFunctor {" << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "    void operator()(int x) const {" << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "        std::cout << x << \" \";" << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "    }" << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "    // ==演算子が定義されていない" << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "};" << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "" << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "int arr[] = {1, 2, 3};" << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "PrintFunctor printer;" << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "::iter(arr, 3, printer);  // コンパイルエラー" << RESET_COLOR << std::endl;
	
	std::cout << BOLD_YELLOW_COLOR << "\n【期待されるエラー】" << RESET_COLOR << std::endl;
	std::cout << RED_COLOR << "error: comparison between NULL and non-pointer ('PrintFunctor' and NULL)" << RESET_COLOR << std::endl;
	std::cout << RED_COLOR << "error: invalid operands to binary expression ('PrintFunctor' and 'long')" << RESET_COLOR << std::endl;
	
	std::cout << BOLD_YELLOW_COLOR << "\n【現在の状態】" << RESET_COLOR << std::endl;
	std::cout << "iter.hppで func == NULL のチェックがコメントアウトされているため、" << std::endl;
	std::cout << "このテストケースは正常にコンパイル・実行できます:" << std::endl;
	
	int arr[] = {1, 2, 3};
	const size_t size = sizeof(arr) / sizeof(int);
	
	PrintFunctor printer;
	std::cout << "実行結果: ";
	::iter(arr, size, printer);
	std::cout << std::endl;
	
	std::cout << GREEN_COLOR << "✓ 現在は正常に動作しています（func == NULL のチェックがコメントアウトされているため）" << RESET_COLOR << std::endl;
	std::cout << YELLOW_COLOR << "⚠ func == NULL のチェックを有効にすると、コンパイルエラーになります" << RESET_COLOR << std::endl;
}
