/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:00:00 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/17 15:27:23 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "AnsiColor.hpp"
#include "Array.hpp"

// ===== テスト関数 =====

void printMenu(void);
void testDefaultConstructor(void);
void testParameterizedConstructor(void);
void testCopyConstructor(void);
void testAssignmentOperator(void);
void testSubscriptOperator(void);
void testExceptionHandling(void);
void testSizeFunction(void);
void testDifferentTypes(void);
void testIntegratedTests236(void);
void testValueInitialization(void);

int main(void) {
	std::string choice;

	std::cout << CYAN_COLOR << "\n=== CPP07 Exercise 02: Array ===" << RESET_COLOR << std::endl;
	std::cout << GREEN_COLOR << "Array<T>クラステンプレートのテストメニュー" << RESET_COLOR << std::endl;

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
				testDefaultConstructor();
				break;
			case '2':
				testParameterizedConstructor();
				break;
			case '3':
				testCopyConstructor();
				break;
			case '4':
				testAssignmentOperator();
				break;
			case '5':
				testSubscriptOperator();
				break;
			case '6':
				testExceptionHandling();
				break;
			case '7':
				testSizeFunction();
				break;
			case '8':
				testDifferentTypes();
				break;
			case '9':
				testIntegratedTests236();
				break;
			case 'a':
			case 'A':
				testValueInitialization();
				break;
			case '0':
				std::cout << CYAN_COLOR << "\nプログラムを終了します。" << RESET_COLOR << std::endl;
				return 0;
			default:
				std::cout << RED_COLOR << "無効な選択です。0-9、a、0を入力してください。" << RESET_COLOR << std::endl;
				break;
		}
		std::cout << std::endl;
	}
}

void printMenu(void) {
	std::cout << "\n" << BOLD_BLUE_COLOR << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET_COLOR << std::endl;
	std::cout << BOLD_GREEN_COLOR << " テストメニュー" << RESET_COLOR << std::endl;
	std::cout << BOLD_BLUE_COLOR << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET_COLOR << std::endl;
	std::cout << "  " << CYAN_COLOR << "1" << RESET_COLOR << ". デフォルトコンストラクタのテスト" << std::endl;
	std::cout << "     Construction with no parameter: Creates an empty array." << std::endl;
	std::cout << "  " << CYAN_COLOR << "2" << RESET_COLOR << ". パラメータ付きコンストラクタのテスト" << std::endl;
	std::cout << "     Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default." << std::endl;
	std::cout << "  " << CYAN_COLOR << "3" << RESET_COLOR << ". コピーコンストラクタのテスト" << std::endl;
	std::cout << "     Construction by copy and assignment operator. In both cases, modifying either the original array or its copy after copying musn't affect the other array." << std::endl;
	std::cout << "  " << CYAN_COLOR << "4" << RESET_COLOR << ". 代入演算子のテスト" << std::endl;
	std::cout << "     Construction by copy and assignment operator. In both cases, modifying either the original array or its copy after copying musn't affect the other array." << std::endl;
	std::cout << "  " << CYAN_COLOR << "5" << RESET_COLOR << ". 添字演算子[]のテスト" << std::endl;
	std::cout << "     Elements can be accessed through the subscript operator: [ ]." << std::endl;
	std::cout << "  " << CYAN_COLOR << "6" << RESET_COLOR << ". 例外処理のテスト" << std::endl;
	std::cout << "     When accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown." << std::endl;
	std::cout << "  " << CYAN_COLOR << "7" << RESET_COLOR << ". size()関数のテスト" << std::endl;
	std::cout << "     A member function size() that returns the number of elements in the array. This member function takes no parameters and must not modify the current instance." << std::endl;
	std::cout << "  " << CYAN_COLOR << "8" << RESET_COLOR << ". 異なる型でのテスト" << std::endl;
	std::cout << "  " << CYAN_COLOR << "9" << RESET_COLOR << ". テスト2（パラメータ付きコンストラクタ）・テスト3（コピーコンストラクタ）・テスト6（例外処理）の結合テスト" << std::endl;
	std::cout << "  " << CYAN_COLOR << "a" << RESET_COLOR << ". 値初期化のテスト (new int() vs new int)" << std::endl;
	std::cout << "  " << RED_COLOR << "0" << RESET_COLOR << ". 終了" << std::endl;
	std::cout << BOLD_BLUE_COLOR << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET_COLOR << std::endl;
}

void testDefaultConstructor(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 1: Construction with no parameter: Creates an empty array." << RESET_COLOR << std::endl;
	std::cout << GREEN_COLOR << "=== デフォルトコンストラクタのテスト ===" << RESET_COLOR << std::endl;
	
	Array<int> empty_array;
	
	if (empty_array.size() == 0) {
		std::cout << GREEN_COLOR << "✓ 空配列のサイズは0です" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 空配列のサイズが0ではありません" << RESET_COLOR << std::endl;
	}
	
	std::cout << CYAN_COLOR << "空配列のサイズ: " << empty_array.size() << RESET_COLOR << std::endl;
}

void testParameterizedConstructor(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 2: Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default." << RESET_COLOR << std::endl;
	std::cout << GREEN_COLOR << "=== パラメータ付きコンストラクタのテスト ===" << RESET_COLOR << std::endl;
	
	const unsigned int test_size = 10;
	Array<int> numbers(test_size);
	
	if (numbers.size() == test_size) {
		std::cout << GREEN_COLOR << "✓ 配列のサイズがコンストラクタのパラメータと一致しています" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 配列のサイズがコンストラクタのパラメータと一致しません" << RESET_COLOR << std::endl;
	}
	
	// デフォルト初期化の確認
	bool all_zero = true;
	for (unsigned int i = 0; i < numbers.size(); i++) {
		std::cerr << "numbers[" << i << "] = " << numbers[i] << std::endl;
		
		if (numbers[i] != 0) {
			all_zero = false;
			break;
		}
	}
	
	if (all_zero) {
		std::cout << GREEN_COLOR << "✓ すべての要素がデフォルト値(0)で初期化されています" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 要素が適切に初期化されていません" << RESET_COLOR << std::endl;
	}
	
	// 文字列配列でのテスト
	Array<std::string> strings(5);
	bool all_empty = true;
	for (unsigned int i = 0; i < strings.size(); i++) {
		std::cerr << "strings[" << i << "] = \"" << strings[i] << "\"" << std::endl;
		
		if (!strings[i].empty()) {
			all_empty = false;
			break;
		}
	}
	
	if (all_empty) {
		std::cout << GREEN_COLOR << "✓ 文字列配列の要素が空文字列で初期化されています" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 文字列配列の要素が適切に初期化されていません" << RESET_COLOR << std::endl;
	}
}

void testCopyConstructor(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 3: Construction by copy and assignment operator. In both cases, modifying either the original array or its copy after copying musn't affect the other array." << RESET_COLOR << std::endl;
	std::cout << GREEN_COLOR << "=== コピーコンストラクタのテスト ===" << RESET_COLOR << std::endl;
	
	// 元配列の準備
	Array<int> original(5);
	for (unsigned int i = 0; i < original.size(); i++) {
		original[i] = i * 10;
	}
	
	std::cout << CYAN_COLOR << "元配列の内容: ";
	for (unsigned int i = 0; i < original.size(); i++) {
		std::cout << original[i] << " ";
	}
	std::cout << RESET_COLOR << std::endl;
	
	// コピーコンストラクタのテスト
	Array<int> copy(original);
	
	// サイズチェック
	if (copy.size() == original.size()) {
		std::cout << GREEN_COLOR << "✓ コピーのサイズが元の配列と同じです" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ コピーのサイズが元の配列と異なります" << RESET_COLOR << std::endl;
	}
	
	// 内容チェック
	bool content_match = true;
	for (unsigned int i = 0; i < original.size(); i++) {
		std::cerr << "copy[" << i << "] = " << copy[i] << ", original[" << i << "] = " << original[i] << std::endl;
		
		if (copy[i] != original[i]) {
			content_match = false;
			break;
		}
	}
	
	if (content_match) {
		std::cout << GREEN_COLOR << "✓ コピーの内容が元の配列と同じです" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ コピーの内容が元の配列と異なります" << RESET_COLOR << std::endl;
	}
	
	// 深いコピーのテスト
	original[0] = 999;
	if (copy[0] != 999) {
		std::cout << GREEN_COLOR << "✓ 深いコピーが確認されました - 元の配列を変更してもコピーに影響しません" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 浅いコピーが検出されました - 元の配列を変更するとコピーに影響します" << RESET_COLOR << std::endl;
	}
	
	std::cout << CYAN_COLOR << "元配列[0]を999に変更後:" << RESET_COLOR << std::endl;
	std::cout << "  元配列[0]: " << original[0] << std::endl;
	std::cout << "  コピー[0]: " << copy[0] << std::endl;
}

void testAssignmentOperator(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 4: Construction by copy and assignment operator. In both cases, modifying either the original array or its copy after copying musn't affect the other array." << RESET_COLOR << std::endl;
	std::cout << GREEN_COLOR << "=== 代入演算子のテスト ===" << RESET_COLOR << std::endl;
	
	// 元配列の準備
	Array<int> original(5);
	for (unsigned int i = 0; i < original.size(); i++) {
		original[i] = i * 20;
	}
	
	// 異なるサイズの配列に代入
	Array<int> assigned(3);
	assigned = original;
	
	// サイズチェック
	if (assigned.size() == original.size()) {
		std::cout << GREEN_COLOR << "✓ 代入により配列のサイズが正しく更新されました" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 代入により配列のサイズが更新されませんでした" << RESET_COLOR << std::endl;
	}
	
	// 内容チェック
	bool content_match = true;
	for (unsigned int i = 0; i < original.size(); i++) {
		std::cerr << "assigned[" << i << "] = " << assigned[i] << ", original[" << i << "] = " << original[i] << std::endl;
		
		if (assigned[i] != original[i]) {
			content_match = false;
			break;
		}
	}
	
	if (content_match) {
		std::cout << GREEN_COLOR << "✓ 代入により内容が正しくコピーされました" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 代入により内容が正しくコピーされませんでした" << RESET_COLOR << std::endl;
	}
	
	// 深いコピーのテスト
	original[1] = 777;
	if (assigned[1] != 777) {
		std::cout << GREEN_COLOR << "✓ 深いコピーが確認されました - 元の配列を変更しても代入先に影響しません" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 浅いコピーが検出されました - 元の配列を変更すると代入先に影響します" << RESET_COLOR << std::endl;
	}
	
	// 自己代入のテスト
	Array<int> self_test(3);
	self_test[0] = 100;
	self_test[1] = 200;
	self_test[2] = 300;
	// 警告を抑制するためにポインタ経由で自己代入をテスト
	Array<int>* self_ptr = &self_test;
	*self_ptr = self_test;
	
	if (self_test.size() == 3 && self_test[0] == 100) {
		std::cout << GREEN_COLOR << "✓ 自己代入が正常に処理されました" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 自己代入が正常に処理されませんでした" << RESET_COLOR << std::endl;
	}
}

void testSubscriptOperator(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 5: Elements can be accessed through the subscript operator: [ ]." << RESET_COLOR << std::endl;
	std::cout << GREEN_COLOR << "=== 添字演算子[]のテスト ===" << RESET_COLOR << std::endl;
	
	Array<int> numbers(5);
	
	// 書き込みテスト
	for (unsigned int i = 0; i < numbers.size(); i++) {
		std::cerr << "書き込み前: numbers[" << i << "] = " << numbers[i] << std::endl;
		numbers[i] = i * 100;
		std::cerr << "書き込み後: numbers[" << i << "] = " << numbers[i] << std::endl;
	}
	std::cout << GREEN_COLOR << "✓ []演算子による書き込みが成功しました" << RESET_COLOR << std::endl;
	
	// 読み取りテスト
	bool read_correct = true;
	for (unsigned int i = 0; i < numbers.size(); i++) {
		std::cerr << "numbers[" << i << "] = " << numbers[i] << std::endl;
		
		if (numbers[i] != static_cast<int>(i * 100)) {
			read_correct = false;
			break;
		}
	}
	
	if (read_correct) {
		std::cout << GREEN_COLOR << "✓ []演算子による読み取りが成功しました" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ []演算子による読み取りが失敗しました" << RESET_COLOR << std::endl;
	}
	
	// const版のテスト
	const Array<int> const_numbers = numbers;
	if (const_numbers[0] == 0) {
		std::cout << GREEN_COLOR << "✓ const []演算子が正常に動作しています" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ const []演算子が正常に動作していません" << RESET_COLOR << std::endl;
	}
	
	std::cout << CYAN_COLOR << "配列の内容: ";
	for (unsigned int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << RESET_COLOR << std::endl;
}

void testExceptionHandling(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 6: When accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown." << RESET_COLOR << std::endl;
	std::cout << GREEN_COLOR << "=== 例外処理のテスト ===" << RESET_COLOR << std::endl;
	
	Array<int> numbers(5);
	std::cerr << "Array<int> numbers(5); を作成しました" << std::endl;
	
	// 正の範囲外アクセス
	try {
		std::cerr << "テスト実行: numbers[10] = 42;" << std::endl;
		numbers[10] = 42;
		std::cout << RED_COLOR << "✗ 正の範囲外アクセスで例外がスローされませんでした" << RESET_COLOR << std::endl;
	} catch (const std::exception& e) {
		std::cout << GREEN_COLOR << "✓ 正の範囲外アクセスで例外がキャッチされました" << RESET_COLOR << std::endl;
		std::cout << YELLOW_COLOR << "  例外メッセージ: " << e.what() << RESET_COLOR << std::endl;
	}
	
	// 負のインデックス（unsigned intにキャストされて大きな値になる）
	try {
		std::cerr << "テスト実行: numbers[-1] = 42;" << std::endl;
		numbers[-1] = 42;
		std::cout << RED_COLOR << "✗ 負のインデックスで例外がスローされませんでした" << RESET_COLOR << std::endl;
	} catch (const std::exception& e) {
		std::cout << GREEN_COLOR << "✓ 負のインデックスで例外がキャッチされました" << RESET_COLOR << std::endl;
		std::cout << YELLOW_COLOR << "  例外メッセージ: " << e.what() << RESET_COLOR << std::endl;
	}
	
	// 空配列での範囲外アクセス
	Array<int> empty;
	std::cerr << "Array<int> empty; を作成しました" << std::endl;
	
	try {
		std::cerr << "テスト実行: empty[0] = 42;" << std::endl;
		empty[0] = 42;
		std::cout << RED_COLOR << "✗ 空配列アクセスで例外がスローされませんでした" << RESET_COLOR << std::endl;
	} catch (const std::exception& e) {
		std::cout << GREEN_COLOR << "✓ 空配列アクセスで例外がキャッチされました" << RESET_COLOR << std::endl;
		std::cout << YELLOW_COLOR << "  例外メッセージ: " << e.what() << RESET_COLOR << std::endl;
	}
}

void testSizeFunction(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 7: A member function size() that returns the number of elements in the array. This member function takes no parameters and must not modify the current instance." << RESET_COLOR << std::endl;
	std::cout << GREEN_COLOR << "=== size()関数のテスト ===" << RESET_COLOR << std::endl;
	
	Array<int> empty;
	std::cerr << "Array<int> empty; を作成しました" << std::endl;
	
	Array<int> small(3);
	std::cerr << "Array<int> small(3); を作成しました" << std::endl;
	
	Array<int> large(10);
	std::cerr << "Array<int> large(10); を作成しました" << std::endl;
	
	if (empty.size() == 0) {
		std::cerr << "テスト実行: empty.size() == 0, 結果: " << empty.size() << std::endl;
		std::cout << GREEN_COLOR << "✓ 空配列のsize()は0を返します" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 空配列のsize()が0を返しません" << RESET_COLOR << std::endl;
	}
	
	if (small.size() == 3) {
		std::cerr << "テスト実行: small.size() == 3, 結果: " << small.size() << std::endl;
		std::cout << GREEN_COLOR << "✓ 小さな配列のsize()が正しい値を返します" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 小さな配列のsize()が正しい値を返しません" << RESET_COLOR << std::endl;
	}
	
	if (large.size() == 10) {
		std::cerr << "テスト実行: large.size() == 10, 結果: " << large.size() << std::endl;
		std::cout << GREEN_COLOR << "✓ 大きな配列のsize()が正しい値を返します" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 大きな配列のsize()が正しい値を返しません" << RESET_COLOR << std::endl;
	}
	
	std::cout << CYAN_COLOR << "空配列のサイズ: " << empty.size() << RESET_COLOR << std::endl;
	std::cerr << "empty.size() = " << empty.size() << std::endl;
	std::cout << CYAN_COLOR << "小さな配列のサイズ: " << small.size() << RESET_COLOR << std::endl;
	std::cerr << "small.size() = " << small.size() << std::endl;
	std::cout << CYAN_COLOR << "大きな配列のサイズ: " << large.size() << RESET_COLOR << std::endl;
	std::cerr << "large.size() = " << large.size() << std::endl;
}

void testDifferentTypes(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 8: 異なる型でのテスト ===" << RESET_COLOR << std::endl;
	
	// double型のテスト
	Array<double> doubles(3);
	doubles[0] = 3.14;
	doubles[1] = 2.71;
	doubles[2] = 1.41;
	
	if (doubles[0] == 3.14 && doubles[1] == 2.71 && doubles[2] == 1.41) {
		std::cout << GREEN_COLOR << "✓ double型のArrayが正常に動作しています" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ double型のArrayが正常に動作していません" << RESET_COLOR << std::endl;
	}
	
	std::cout << CYAN_COLOR << "double配列: " << doubles[0] << ", " << doubles[1] << ", " << doubles[2] << RESET_COLOR << std::endl;
	
	// string型のテスト
	Array<std::string> strings(2);
	strings[0] = "Hello";
	strings[1] = "World";
	
	if (strings[0] == "Hello" && strings[1] == "World") {
		std::cout << GREEN_COLOR << "✓ string型のArrayが正常に動作しています" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ string型のArrayが正常に動作していません" << RESET_COLOR << std::endl;
	}
	
	std::cout << CYAN_COLOR << "string配列: " << strings[0] << ", " << strings[1] << RESET_COLOR << std::endl;
}

void testIntegratedTests236(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 9: テスト2（パラメータ付きコンストラクタ）・テスト3（コピーコンストラクタ）・テスト6（例外処理）の結合テスト ===" << RESET_COLOR << std::endl;
	
	const unsigned int MAX_VAL = 10;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];  // 各要素は未定義値（環境依存）
	//  new int[MAX_VAL] vs new int[MAX_VAL]() の違いを確認
	// 以下のコードで、デフォルト初期化と値初期化の違いをテストできます

	// デフォルト初期化の場合（現在の実装）:
	std::cout << "new int[MAX_VAL] (デフォルト初期化) の各要素:" << std::endl;
	for (unsigned int i = 0; i < MAX_VAL; i++) {
		std::cout << "  mirror[" << i << "] = " << mirror[i] << std::endl;
		// 注意: 未定義値のため、ランダムな値が表示される可能性がある
	}
/*	
	// 値初期化の場合（テスト用）:
	int* mirror_value = new int[MAX_VAL]();  // 各要素は0で初期化される
	std::cout << "new int[MAX_VAL]() (値初期化) の各要素:" << std::endl;
	for (unsigned int i = 0; i < MAX_VAL; i++) {
		std::cout << "  mirror_value[" << i << "] = " << mirror_value[i] << std::endl;
		// すべて0になることが確認できる
	}
	delete[] mirror_value;
*/
	
	srand(time(NULL));
	// 上記のコメントアウトされたテストでは、
	// new int[MAX_VAL] と new int[MAX_VAL]() の違いを確認できます。
	// 現在の実装では、mirror は new int[MAX_VAL] で作成されているため、
	// 各要素は未定義値ですが、直後に値を代入しているため問題ありません。
	for (unsigned int i = 0; i < MAX_VAL; i++) {
		const int value = rand() % 1000;
		numbers[i] = value;
		mirror[i] = value;
	}
	
	std::cout << CYAN_COLOR << "初期化完了: " << MAX_VAL << "個の要素をランダムな値で初期化" << RESET_COLOR << std::endl;
	std::cout << YELLOW_COLOR << "注:  mirror は new int[MAX_VAL] (デフォルト初期化) で作成されています。" << RESET_COLOR << std::endl;
	std::cout << YELLOW_COLOR << "    各要素は未定義値ですが、ループで直後に値を代入しているため問題ありません。" << RESET_COLOR << std::endl;
	std::cout << YELLOW_COLOR << "    もし値初期化を使用する場合は、new int[MAX_VAL]() と記述します（コメントアウトを参照）。" << RESET_COLOR << std::endl;
	
	// SCOPE テスト
	{
		std::cerr << "テスト実行: Array<int> tmp = numbers;" << std::endl;
		Array<int> tmp = numbers;
		std::cerr << "テスト実行: Array<int> test(tmp);" << std::endl;
		Array<int> test(tmp);
		std::cout << CYAN_COLOR << "スコープ内でコピーを作成しました" << RESET_COLOR << std::endl;
		// スコープを抜ける時にデストラクタが呼ばれる
	}
	
	// 元の配列が影響を受けていないかチェック
	bool values_preserved = true;
	for (unsigned int i = 0; i < MAX_VAL; i++) {
		std::cerr << "mirror[" << i << "] = " << mirror[i] << ", numbers[" << i << "] = " << numbers[i] << std::endl;
		
		if (mirror[i] != numbers[i]) {
			values_preserved = false;
			break;
		}
	}
	
	if (values_preserved) {
		std::cout << GREEN_COLOR << "✓ スコープ破棄後も値が保持されています" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ スコープ破棄後に値が保持されていません" << RESET_COLOR << std::endl;
	}
	
	// 例外テスト
	std::cout << CYAN_COLOR << "\n例外テスト:" << RESET_COLOR << std::endl;
	
	try {
		std::cerr << "テスト実行: numbers[-2] = 0;" << std::endl;
		numbers[-2] = 0;
		std::cout << RED_COLOR << "✗ 負のインデックスで例外がスローされませんでした" << RESET_COLOR << std::endl;
	} catch (const std::exception& e) {
		std::cout << GREEN_COLOR << "✓ numbers[-2]で例外がキャッチされました" << RESET_COLOR << std::endl;
		std::cout << YELLOW_COLOR << "  例外メッセージ: " << e.what() << RESET_COLOR << std::endl;
	}
	
	try {
		std::cerr << "テスト実行: numbers[MAX_VAL] = 0;" << std::endl;
		numbers[MAX_VAL] = 0;
		std::cout << RED_COLOR << "✗ 範囲外インデックスで例外がスローされませんでした" << RESET_COLOR << std::endl;
	} catch (const std::exception& e) {
		std::cout << GREEN_COLOR << "✓ numbers[MAX_VAL]で例外がキャッチされました" << RESET_COLOR << std::endl;
		std::cout << YELLOW_COLOR << "  例外メッセージ: " << e.what() << RESET_COLOR << std::endl;
	}
	
	// 値の変更テスト
	std::cout << CYAN_COLOR << "\n値の変更テスト:" << RESET_COLOR << std::endl;
	for (unsigned int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand() % 1000;
		std::cerr << "numbers[" << i << "] = " << numbers[i] << std::endl;
	}
	std::cout << GREEN_COLOR << "✓ すべての要素を新しいランダム値で更新しました" << RESET_COLOR << std::endl;
	
	std::cerr << "テスト実行: delete[] mirror;" << std::endl;
	delete[] mirror;
	std::cout << GREEN_COLOR << "✓ 手動メモリクリーンアップが成功しました" << RESET_COLOR << std::endl;
}

void testValueInitialization(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト a: 値初期化のテスト (new int() vs new int) ===" << RESET_COLOR << std::endl;
	std::cout << YELLOW_COLOR << "ヒント: int * a = new int(); をコンパイルしてから、*a を表示してみてください。" << RESET_COLOR << std::endl;
	std::cout << YELLOW_COLOR << "Tip: Try to compile int * a = new int(); then display *a." << RESET_COLOR << std::endl;
	std::cout << std::endl;
	
	// new int() - 値初期化（value initialization）
	std::cout << CYAN_COLOR << "--- new int() (値初期化) ---" << RESET_COLOR << std::endl;
	int* a = new int();
	std::cout << "int* a = new int();" << std::endl;
	std::cout << "*a の値: " << *a << RESET_COLOR << std::endl;
	
	if (*a == 0) {
		std::cout << GREEN_COLOR << "✓ new int() は値初期化を行い、*a は 0 になります" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ new int() の結果が期待値(0)と異なります" << RESET_COLOR << std::endl;
	}
	
	delete a;
	
	// 複数回テストして一貫性を確認
	std::cout << CYAN_COLOR << "\n複数回の値初期化をテストします:" << RESET_COLOR << std::endl;
	bool all_zero = true;
	for (int i = 0; i < 5; i++) {
		int* test_val = new int();
		std::cout << "  試行 " << (i + 1) << ": *test_val = " << *test_val << std::endl;
		if (*test_val != 0) {
			all_zero = false;
		}
		delete test_val;
	}
	
	if (all_zero) {
		std::cout << GREEN_COLOR << "✓ すべての値初期化で 0 が返されました" << RESET_COLOR << std::endl;
	} else {
		std::cout << YELLOW_COLOR << "⚠ 一部の値初期化で 0 以外の値が返されました（環境依存の可能性）" << RESET_COLOR << std::endl;
	}
	
	// Array<T>での値初期化との関連性を説明
	std::cout << CYAN_COLOR << "\n--- Array<T> との関連性 ---" << RESET_COLOR << std::endl;
	std::cout << "Array<int> arr(10); を作成すると、new int[10] が使用されます。" << std::endl;
	std::cout << "各要素は値初期化され、int型の場合は 0 で初期化されます。" << std::endl;
	std::cout << std::endl;
	
	Array<int> test_array(5);
	bool array_all_zero = true;
	std::cout << "Array<int> test_array(5); の各要素:" << std::endl;
	for (unsigned int i = 0; i < test_array.size(); i++) {
		std::cout << "  test_array[" << i << "] = " << test_array[i];
		if (test_array[i] != 0) {
			array_all_zero = false;
			std::cout << " ← 期待値(0)と異なる";
		}
		std::cout << std::endl;
	}
	
	if (array_all_zero) {
		std::cout << GREEN_COLOR << "✓ Array<int> の各要素は値初期化により 0 で初期化されています" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ Array<int> の要素が適切に値初期化されていません" << RESET_COLOR << std::endl;
	}
	
	// 注意: new int（デフォルト初期化）は未定義動作を引き起こす可能性があるため、
	// テストには含めませんが、説明として記載
	std::cout << CYAN_COLOR << "\n--- 補足情報 ---" << RESET_COLOR << std::endl;
	std::cout << "new int() (値初期化) vs new int (デフォルト初期化):" << std::endl;
	std::cout << "  - new int(): 値初期化 → *a は 0 に初期化される" << std::endl;
	std::cout << "  - new int:  デフォルト初期化 → *a は未定義値（使用前に初期化が必要）" << std::endl;
	std::cout << "Array<T> の実装では、new T[n] を使用することで値初期化が行われます。" << std::endl;
	std::cout << "  実際の実装（Array.tpp）では:" << std::endl;
	std::cout << "    1. new T[n] で配列を確保" << std::endl;
	std::cout << "    2. その後、ループで各要素を T() で明示的に値初期化" << std::endl;
}

