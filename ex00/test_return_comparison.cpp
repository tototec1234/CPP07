#include <iostream>
#include <string>

// 値返しの例
std::string return_by_value(const std::string& a, const std::string& b) {
    std::cout << "return_by_value: コピーを作成しています" << std::endl;
    return a < b ? a : b;  // 文字列のコピーが発生
}

// 参照返しの例
const std::string& return_by_reference(const std::string& a, const std::string& b) {
    std::cout << "return_by_reference: 参照を返しています（コピーなし）" << std::endl;
    return a < b ? a : b;  // 参照のみ（コピーなし）
}

int main() {
    std::string str1 = "Hello";
    std::string str2 = "World";
    
    std::cout << "=== 値返しの場合 ===" << std::endl;
    std::string result1 = return_by_value(str1, str2);
    std::cout << "result1 のアドレス: " << (void*)&result1 << std::endl;
    std::cout << "str1 のアドレス: " << (void*)&str1 << std::endl;
    std::cout << "str2 のアドレス: " << (void*)&str2 << std::endl;
    std::cout << "→ 異なるアドレス（コピーされている）" << std::endl;
    
    std::cout << "\n=== 参照返しの場合 ===" << std::endl;
    const std::string& result2 = return_by_reference(str1, str2);
    std::cout << "result2 のアドレス: " << (void*)&result2 << std::endl;
    std::cout << "str1 のアドレス: " << (void*)&str1 << std::endl;
    std::cout << "str2 のアドレス: " << (void*)&str2 << std::endl;
    std::cout << "→ 同じアドレス（参照のみ）" << std::endl;
    
    return 0;
}
