# C++ - Module 07

## C++テンプレート

概要:
このドキュメントには、C++モジュールのModule 07の演習問題が含まれています。

バージョン: 10.0

---

# 第I章

## はじめに

**原文:**
```
C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or "C with Classes" (source: Wikipedia).

The goal of these modules is to introduce you to Object-Oriented Programming. This will be the starting point of your C++ journey. Many languages are recommended to learn OOP. We decided to choose C++ since it's derived from your old friend C. Because this is a complex language, and in order to keep things simple, your code will comply with the C++98 standard.

We are aware modern C++ is way different in a lot of aspects. So if you want to become a proficient C++ developer, it's up to you to go further after the 42 Common Core!
```

**和訳:**
C++は、Bjarne StroustrupによってCプログラミング言語の拡張として作成された汎用プログラミング言語で、「C with Classes」（クラス付きC）と呼ばれます（出典: Wikipedia）。

これらのモジュールの目標は、オブジェクト指向プログラミングを紹介することです。これはあなたのC++の旅の出発点となります。OOPを学ぶために多くの言語が推奨されています。私たちは、あなたの古い友達であるCから派生しているため、C++を選択することにしました。これは複雑な言語であるため、シンプルに保つために、あなたのコードはC++98標準に準拠します。

現代のC++は多くの側面で大きく異なることを認識しています。したがって、熟練したC++開発者になりたい場合は、42 Common Coreの後にさらに進むのはあなた次第です！

---

**注: 第II章（一般的なルール）と第III章（AI指示）は、Module 05と同様の内容のため割愛しています。**

---

# 第IV章

## 演習 00: いくつかの関数から始める

**原文:**
```
|  Exercise: 00  |   |
| --- | --- |
|  Start with a few functions  |   |
|  Directory: ex00/  |   |
|  Files to Submit: Makefile, main.cpp, whatever.{h, hpp}  |   |
|  Forbidden: None  |   |

Implement the following function templates:

- swap: Swaps the values of two given parameters. Does not return anything.
- min: Compares the two values passed as parameters and returns the smallest one. If they are equal, it returns the second one.
- max: Compares the two values passed as parameters and returns the greatest one. If they are equal, it returns the second one.

These functions can be called with any type of argument. The only requirement is that the two arguments must have the same type and must support all the comparison operators.

Templates must be defined in the header files.

Running the following code:

```c
int main(void) {
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
return 0;
}
```

Should output:

```txt
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```
```

**和訳:**
|  演習: 00  |   |
| --- | --- |
|  いくつかの関数から始める  |   |
|  ディレクトリ: ex00/  |   |
|  提出ファイル: Makefile, main.cpp, whatever.{h, hpp}  |   |
|  禁止事項: なし  |   |

次の関数テンプレートを実装してください：

- swap: 2つの指定されたパラメータの値を交換します。何も返しません。
- min: パラメータとして渡された2つの値を比較し、最小値を返します。等しい場合、2番目の値を返します。
- max: パラメータとして渡された2つの値を比較し、最大値を返します。等しい場合、2番目の値を返します。

これらの関数は、任意の型の引数で呼び出すことができます。唯一の要件は、2つの引数が同じ型であり、すべての比較演算子をサポートしている必要があることです。

テンプレートはヘッダーファイルで定義する必要があります。

次のコードを実行すると：

```c
int main(void) {
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
return 0;
}
```

次の出力が得られるはずです：

```txt
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```

---

# 第V章

## 演習 01: Iter

**原文:**
```
|   | Exercise: 01  |
| --- | --- |
|   | Iter  |
|  Directory: ex01/  |   |
|  Files to Submit: Makefile, main.cpp, iter.{h, hpp}  |   |
|  Forbidden: None  |   |

Implement a function template iter that takes 3 parameters and returns nothing.

- The first parameter is the address of an array.
- The second one is the length of the array, passed as a const value.
- The third one is a function that will be called on every element of the array.

Submit a main.cpp file that contains your tests. Provide enough code to generate a test executable.

Your iter function template must work with any type of array. The third parameter can be an instantiated function template.

The function passed as the third parameter may take its argument by const reference or non-const reference, depending on the context.

Think carefully about how to support both const and non-const elements in your iter function.
```

**和訳:**
|   | 演習: 01  |
| --- | --- |
|   | Iter  |
|  ディレクトリ: ex01/  |   |
|  提出ファイル: Makefile, main.cpp, iter.{h, hpp}  |   |
|  禁止事項: なし  |   |

3つのパラメータを受け取り、何も返さない関数テンプレートiterを実装してください。

- 最初のパラメータは配列のアドレスです。
- 2番目のパラメータは配列の長さで、const値として渡されます。
- 3番目のパラメータは、配列の各要素に対して呼び出される関数です。

テストを含むmain.cppファイルを提出してください。テスト実行可能ファイルを生成するのに十分なコードを提供してください。

iter関数テンプレートは、任意の型の配列で動作する必要があります。3番目のパラメータは、インスタンス化された関数テンプレートにすることができます。

3番目のパラメータとして渡される関数は、コンテキストに応じて、引数をconst参照または非const参照で受け取ることができます。

iter関数でconst要素と非const要素の両方をサポートする方法を慎重に検討してください。

---

# 第VI章

## 演習 02: Array

**原文:**
```
|  Exercise: 02  |   |
| --- | --- |
|  Array  |   |
|  Directory: ex02/  |   |
|  Files to Submit: Makefile, main.cpp, Array.{h, hpp} and optional file: Array.tpp  |   |
|  Forbidden: None  |   |

Develop a class template Array that contains elements of type T and that implements the following behavior and functions:

- Construction with no parameter: Creates an empty array.
- Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.

Tip: Try to compile int * a = new int(); then display *a.

- Construction by copy and assignment operator. In both cases, modifying either the original array or its copy after copying musn't affect the other array.
- You MUST use the operator new[] to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access non-allocated memory.
- Elements can be accessed through the subscript operator: [ ].
- When accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown.
- A member function size() that returns the number of elements in the array. This member function takes no parameters and must not modify the current instance.

As usual, ensure everything works as expected and turn in a main.cpp file that contains your tests.
```

**和訳:**
|  演習: 02  |   |
| --- | --- |
|  Array  |   |
|  ディレクトリ: ex02/  |   |
|  提出ファイル: Makefile, main.cpp, Array.{h, hpp} およびオプションファイル: Array.tpp  |   |
|  禁止事項: なし  |   |

型Tの要素を含み、次の動作と関数を実装するクラステンプレートArrayを開発してください：

- パラメータなしの構築: 空の配列を作成します。
- unsigned int nをパラメータとする構築: デフォルトで初期化されたn個の要素の配列を作成します。

ヒント: `int * a = new int();` をコンパイルしてから、`*a`を表示してみてください。

- コピーによる構築と代入演算子。どちらの場合も、コピー後に元の配列またはそのコピーのいずれかを変更しても、もう一方の配列に影響を与えてはいけません。
- メモリを割り当てるには、演算子new[]を使用する必要があります。予防的割り当て（事前にメモリを割り当てること）は禁止されています。プログラムは、割り当てられていないメモリにアクセスしてはいけません。
- 要素は添字演算子[ ]を通じてアクセスできます。
- [ ]演算子で要素にアクセスする際、インデックスが範囲外の場合、std::exceptionがスローされます。
- 配列内の要素数を返すメンバー関数size()。このメンバー関数はパラメータを受け取らず、現在のインスタンスを変更してはいけません。

いつものように、すべてが期待どおりに機能することを確認し、テストを含むmain.cppファイルを提出してください。

---

**注: 第VII章（提出とピア評価）は、Module 05と同様の内容のため割愛しています。**

