/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:00:00 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/16 19:26:42 by toruinoue        ###   ########.fr       */
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
void testOriginalScenario(void);

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
				testOriginalScenario();
				break;
			case '0':
				std::cout << CYAN_COLOR << "\nプログラムを終了します。" << RESET_COLOR << std::endl;
				return 0;
			default:
				std::cout << RED_COLOR << "無効な選択です。0-9の数字を入力してください。" << RESET_COLOR << std::endl;
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
	std::cout << "  " << CYAN_COLOR << "2" << RESET_COLOR << ". パラメータ付きコンストラクタのテスト" << std::endl;
	std::cout << "  " << CYAN_COLOR << "3" << RESET_COLOR << ". コピーコンストラクタのテスト" << std::endl;
	std::cout << "  " << CYAN_COLOR << "4" << RESET_COLOR << ". 代入演算子のテスト" << std::endl;
	std::cout << "  " << CYAN_COLOR << "5" << RESET_COLOR << ". 添字演算子[]のテスト" << std::endl;
	std::cout << "  " << CYAN_COLOR << "6" << RESET_COLOR << ". 例外処理のテスト" << std::endl;
	std::cout << "  " << CYAN_COLOR << "7" << RESET_COLOR << ". size()関数のテスト" << std::endl;
	std::cout << "  " << CYAN_COLOR << "8" << RESET_COLOR << ". 異なる型でのテスト" << std::endl;
	std::cout << "  " << CYAN_COLOR << "9" << RESET_COLOR << ". オリジナルシナリオのテスト" << std::endl;
	std::cout << "  " << RED_COLOR << "0" << RESET_COLOR << ". 終了" << std::endl;
	std::cout << BOLD_BLUE_COLOR << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET_COLOR << std::endl;
}

void testDefaultConstructor(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 1: デフォルトコンストラクタのテスト ===" << RESET_COLOR << std::endl;
	
	Array<int> empty_array;
	
	if (empty_array.size() == 0) {
		std::cout << GREEN_COLOR << "✓ 空配列のサイズは0です" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 空配列のサイズが0ではありません" << RESET_COLOR << std::endl;
	}
	
	std::cout << CYAN_COLOR << "空配列のサイズ: " << empty_array.size() << RESET_COLOR << std::endl;
}

void testParameterizedConstructor(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 2: パラメータ付きコンストラクタのテスト ===" << RESET_COLOR << std::endl;
	
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
	std::cout << "\n" << GREEN_COLOR << "=== テスト 3: コピーコンストラクタのテスト ===" << RESET_COLOR << std::endl;
	
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
	std::cout << "\n" << GREEN_COLOR << "=== テスト 4: 代入演算子のテスト ===" << RESET_COLOR << std::endl;
	
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
	std::cout << "\n" << GREEN_COLOR << "=== テスト 5: 添字演算子[]のテスト ===" << RESET_COLOR << std::endl;
	
	Array<int> numbers(5);
	
	// 書き込みテスト
	for (unsigned int i = 0; i < numbers.size(); i++) {
		numbers[i] = i * 100;
	}
	std::cout << GREEN_COLOR << "✓ []演算子による書き込みが成功しました" << RESET_COLOR << std::endl;
	
	// 読み取りテスト
	bool read_correct = true;
	for (unsigned int i = 0; i < numbers.size(); i++) {
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
	std::cout << "\n" << GREEN_COLOR << "=== テスト 6: 例外処理のテスト ===" << RESET_COLOR << std::endl;
	
	Array<int> numbers(5);
	
	// 正の範囲外アクセス
	try {
		numbers[10] = 42;
		std::cout << RED_COLOR << "✗ 正の範囲外アクセスで例外がスローされませんでした" << RESET_COLOR << std::endl;
	} catch (const std::exception& e) {
		std::cout << GREEN_COLOR << "✓ 正の範囲外アクセスで例外がキャッチされました" << RESET_COLOR << std::endl;
		std::cout << YELLOW_COLOR << "  例外メッセージ: " << e.what() << RESET_COLOR << std::endl;
	}
	
	// 負のインデックス（unsigned intにキャストされて大きな値になる）
	try {
		numbers[-1] = 42;
		std::cout << RED_COLOR << "✗ 負のインデックスで例外がスローされませんでした" << RESET_COLOR << std::endl;
	} catch (const std::exception& e) {
		std::cout << GREEN_COLOR << "✓ 負のインデックスで例外がキャッチされました" << RESET_COLOR << std::endl;
		std::cout << YELLOW_COLOR << "  例外メッセージ: " << e.what() << RESET_COLOR << std::endl;
	}
	
	// 空配列での範囲外アクセス
	Array<int> empty;
	try {
		empty[0] = 42;
		std::cout << RED_COLOR << "✗ 空配列アクセスで例外がスローされませんでした" << RESET_COLOR << std::endl;
	} catch (const std::exception& e) {
		std::cout << GREEN_COLOR << "✓ 空配列アクセスで例外がキャッチされました" << RESET_COLOR << std::endl;
		std::cout << YELLOW_COLOR << "  例外メッセージ: " << e.what() << RESET_COLOR << std::endl;
	}
}

void testSizeFunction(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 7: size()関数のテスト ===" << RESET_COLOR << std::endl;
	
	Array<int> empty;
	Array<int> small(3);
	Array<int> large(10);
	
	if (empty.size() == 0) {
		std::cout << GREEN_COLOR << "✓ 空配列のsize()は0を返します" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 空配列のsize()が0を返しません" << RESET_COLOR << std::endl;
	}
	
	if (small.size() == 3) {
		std::cout << GREEN_COLOR << "✓ 小さな配列のsize()が正しい値を返します" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 小さな配列のsize()が正しい値を返しません" << RESET_COLOR << std::endl;
	}
	
	if (large.size() == 10) {
		std::cout << GREEN_COLOR << "✓ 大きな配列のsize()が正しい値を返します" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ 大きな配列のsize()が正しい値を返しません" << RESET_COLOR << std::endl;
	}
	
	std::cout << CYAN_COLOR << "空配列のサイズ: " << empty.size() << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "小さな配列のサイズ: " << small.size() << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "大きな配列のサイズ: " << large.size() << RESET_COLOR << std::endl;
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
	
	// string型のテスト
	Array<std::string> strings(2);
	strings[0] = "Hello";
	strings[1] = "World";
	
	if (strings[0] == "Hello" && strings[1] == "World") {
		std::cout << GREEN_COLOR << "✓ string型のArrayが正常に動作しています" << RESET_COLOR << std::endl;
	} else {
		std::cout << RED_COLOR << "✗ string型のArrayが正常に動作していません" << RESET_COLOR << std::endl;
	}
	
	std::cout << CYAN_COLOR << "double配列: " << doubles[0] << ", " << doubles[1] << ", " << doubles[2] << RESET_COLOR << std::endl;
	std::cout << CYAN_COLOR << "string配列: " << strings[0] << ", " << strings[1] << RESET_COLOR << std::endl;
}

void testOriginalScenario(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 9: オリジナルシナリオのテスト ===" << RESET_COLOR << std::endl;
	
	const unsigned int MAX_VAL = 10;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	
	srand(time(NULL));
	for (unsigned int i = 0; i < MAX_VAL; i++) {
		const int value = rand() % 1000;
		numbers[i] = value;
		mirror[i] = value;
	}
	
	std::cout << CYAN_COLOR << "初期化完了: " << MAX_VAL << "個の要素をランダムな値で初期化" << RESET_COLOR << std::endl;
	
	// SCOPE テスト
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		std::cout << CYAN_COLOR << "スコープ内でコピーを作成しました" << RESET_COLOR << std::endl;
		// スコープを抜ける時にデストラクタが呼ばれる
	}
	
	// 元の配列が影響を受けていないかチェック
	bool values_preserved = true;
	for (unsigned int i = 0; i < MAX_VAL; i++) {
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
		numbers[-2] = 0;
		std::cout << RED_COLOR << "✗ 負のインデックスで例外がスローされませんでした" << RESET_COLOR << std::endl;
	} catch (const std::exception& e) {
		std::cout << GREEN_COLOR << "✓ numbers[-2]で例外がキャッチされました" << RESET_COLOR << std::endl;
		std::cout << YELLOW_COLOR << "  例外メッセージ: " << e.what() << RESET_COLOR << std::endl;
	}
	
	try {
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
	}
	std::cout << GREEN_COLOR << "✓ すべての要素を新しいランダム値で更新しました" << RESET_COLOR << std::endl;
	
	delete[] mirror;
	std::cout << GREEN_COLOR << "✓ 手動メモリクリーンアップが成功しました" << RESET_COLOR << std::endl;
}
