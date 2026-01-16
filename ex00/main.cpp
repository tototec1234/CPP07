/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:00:00 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/16 15:39:59 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "AnsiColor.hpp"
#include "Whatever.hpp"

/*
Implement the following function templates:

- swap: Swaps the values of two given parameters. Does not return anything.
- min: Compares the two values passed as parameters and returns the smallest one. If they are equal, it returns the second one.
- max: Compares the two values passed as parameters and returns the greatest one. If they are equal, it returns the second one.

These functions can be called with any type of argument. The only requirement is that the two arguments must have the same type and must support all the comparison operators.

Templates must be defined in the header files.

*/

void printMenu(void);
void testSubjectPDF(void);
void testFloat(void);
void testSameValueAddress(void);

int main(void) {
	std::string choice;

	std::cout << CYAN_COLOR << "\n=== CPP07 Exercise 00: Start with a few functions ===" << RESET_COLOR << std::endl;
	std::cout << GREEN_COLOR << "テンプレート関数 (swap, min, max) のテストメニュー" << RESET_COLOR << std::endl;

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
				testSubjectPDF();
				break;
			case '2':
				testFloat();
				break;
			case '3':
				testSameValueAddress();
				break;
			case '0':
				std::cout << CYAN_COLOR << "\nプログラムを終了します。" << RESET_COLOR << std::endl;
				return 0;
			default:
				std::cout << RED_COLOR << "無効な選択です。0-3の数字を入力してください。" << RESET_COLOR << std::endl;
				break;
		}
		std::cout << std::endl;
	}
}

void printMenu(void) {
	std::cout << "\n" << BOLD_BLUE_COLOR << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET_COLOR << std::endl;
	std::cout << BOLD_GREEN_COLOR << " テストメニュー" << RESET_COLOR << std::endl;
	std::cout << BOLD_BLUE_COLOR << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET_COLOR << std::endl;
	std::cout << "  " << CYAN_COLOR << "1" << RESET_COLOR << ". subjectPDFのテスト (int型 + string型)" << std::endl;
	std::cout << "  " << CYAN_COLOR << "2" << RESET_COLOR << ". Float型テスト (swap, min, max)" << std::endl;
	std::cout << "  " << CYAN_COLOR << "3" << RESET_COLOR << ". 同じ値の場合のアドレス参照テスト" << std::endl;
	std::cout << "  " << RED_COLOR << "0" << RESET_COLOR << ". 終了" << std::endl;
	std::cout << BOLD_BLUE_COLOR << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET_COLOR << std::endl;
}

void testSubjectPDF(void) {
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
}

void testFloat(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 3: float型のテスト ===" << RESET_COLOR << std::endl;
	
	float e = 2.5;
	float f = 3.5;
	
	std::cout << "初期値: e = " << CYAN_COLOR << e << RESET_COLOR << ", f = " << CYAN_COLOR << f << RESET_COLOR << std::endl;
	
	::swap(e, f);
	std::cout << "swap(e, f) 実行後:" << std::endl;
	std::cout << "  e = " << YELLOW_COLOR << e << RESET_COLOR << ", f = " << YELLOW_COLOR << f << RESET_COLOR << std::endl;
	
	std::cout << "min(e, f) = " << GREEN_COLOR << ::min(e, f) << RESET_COLOR << std::endl;
	std::cout << "max(e, f) = " << GREEN_COLOR << ::max(e, f) << RESET_COLOR << std::endl;
}

void testSameValueAddress(void) {
	std::cout << "\n" << GREEN_COLOR << "=== テスト 4: 同じ値の場合のアドレス参照テスト ===" << RESET_COLOR << std::endl;
	
	std::cout << BOLD_YELLOW_COLOR << "\n--- int型でのテスト ---" << RESET_COLOR << std::endl;
	int x = 5;
	int y = 5;  // xと同じ値
	
	std::cout << "x = " << x << ", &x = " << CYAN_COLOR << &x << RESET_COLOR << std::endl;
	std::cout << "y = " << y << ", &y = " << CYAN_COLOR << &y << RESET_COLOR << std::endl;
	
	// アドレス比較テスト：同じ値の場合、どちらのアドレスを参照するかを確認
	const int& min_ref = ::min(x, y);
	const int& max_ref = ::max(x, y);
	
	std::cout << "\nmin(x, y) の値 = " << GREEN_COLOR << ::min(x, y) << RESET_COLOR << std::endl;
	std::cout << "min(x, y) が参照するアドレス = " << CYAN_COLOR << &min_ref << RESET_COLOR << std::endl;
	std::cout << "  → xのアドレス (&x) = " << &x << std::endl;
	std::cout << "  → yのアドレス (&y) = " << &y << std::endl;
	
	if (&min_ref == &x) {
		std::cout << "  → " << RED_COLOR << "xのアドレスと一致 (第一引数)" << RESET_COLOR << std::endl;
	} else if (&min_ref == &y) {
		std::cout << "  → " << GREEN_COLOR << "yのアドレスと一致 (第二引数) ✓" << RESET_COLOR << std::endl;
	}
	std::cout << "  → 要件: 等しい場合は第二引数(y)を返すべき" << std::endl;
	
	std::cout << "\nmax(x, y) の値 = " << GREEN_COLOR << ::max(x, y) << RESET_COLOR << std::endl;
	std::cout << "max(x, y) が参照するアドレス = " << CYAN_COLOR << &max_ref << RESET_COLOR << std::endl;
	std::cout << "  → xのアドレス (&x) = " << &x << std::endl;
	std::cout << "  → yのアドレス (&y) = " << &y << std::endl;
	
	if (&max_ref == &x) {
		std::cout << "  → " << RED_COLOR << "xのアドレスと一致 (第一引数)" << RESET_COLOR << std::endl;
	} else if (&max_ref == &y) {
		std::cout << "  → " << GREEN_COLOR << "yのアドレスと一致 (第二引数) ✓" << RESET_COLOR << std::endl;
	}
	std::cout << "  → 要件: 等しい場合は第二引数(y)を返すべき" << std::endl;
	
	// 文字列でもテスト
	std::cout << BOLD_YELLOW_COLOR << "\n--- string型でのテスト ---" << RESET_COLOR << std::endl;
	std::string str1 = "test";
	std::string str2 = "test";  // str1と同じ値
	
	std::cout << "str1 = \"" << str1 << "\", &str1 = " << CYAN_COLOR << &str1 << RESET_COLOR << std::endl;
	std::cout << "str2 = \"" << str2 << "\", &str2 = " << CYAN_COLOR << &str2 << RESET_COLOR << std::endl;
	
	const std::string& min_str_ref = ::min(str1, str2);
	const std::string& max_str_ref = ::max(str1, str2);
	
	std::cout << "\nmin(str1, str2) の値 = \"" << GREEN_COLOR << ::min(str1, str2) << RESET_COLOR << "\"" << std::endl;
	std::cout << "min(str1, str2) が参照するアドレス = " << CYAN_COLOR << &min_str_ref << RESET_COLOR << std::endl;
	std::cout << "  → str1のアドレス (&str1) = " << &str1 << std::endl;
	std::cout << "  → str2のアドレス (&str2) = " << &str2 << std::endl;
	
	if (&min_str_ref == &str1) {
		std::cout << "  → " << RED_COLOR << "str1のアドレスと一致 (第一引数)" << RESET_COLOR << std::endl;
	} else if (&min_str_ref == &str2) {
		std::cout << "  → " << GREEN_COLOR << "str2のアドレスと一致 (第二引数) ✓" << RESET_COLOR << std::endl;
	}
	std::cout << "  → 要件: 等しい場合は第二引数(str2)を返すべき" << std::endl;
	
	std::cout << "\nmax(str1, str2) の値 = \"" << GREEN_COLOR << ::max(str1, str2) << RESET_COLOR << "\"" << std::endl;
	std::cout << "max(str1, str2) が参照するアドレス = " << CYAN_COLOR << &max_str_ref << RESET_COLOR << std::endl;
	std::cout << "  → str1のアドレス (&str1) = " << &str1 << std::endl;
	std::cout << "  → str2のアドレス (&str2) = " << &str2 << std::endl;
	
	if (&max_str_ref == &str1) {
		std::cout << "  → " << RED_COLOR << "str1のアドレスと一致 (第一引数)" << RESET_COLOR << std::endl;
	} else if (&max_str_ref == &str2) {
		std::cout << "  → " << GREEN_COLOR << "str2のアドレスと一致 (第二引数) ✓" << RESET_COLOR << std::endl;
	}
	std::cout << "  → 要件: 等しい場合は第二引数(str2)を返すべき" << std::endl;
}

/*
Should output:

```txt
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2

*/
