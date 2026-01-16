#include <iostream>

// sumple_cpp07 スタイル
template <typename T>
const T max_v1(const T& lhs, const T& rhs){
    return lhs < rhs ? rhs : lhs;
}

// c++7 スタイル  
template <typename T>
const T& max_v2(const T& x, const T& y){
    return (x > y ? x : y);
}

int main() {
    int a = 5;
    int b = 5;
    
    std::cout << "Test: max(5, 5)" << std::endl;
    std::cout << "max_v1 (sumple style): " << max_v1(a, b) << std::endl;
    std::cout << "max_v2 (c++7 style): " << max_v2(a, b) << std::endl;
    
    // アドレスを確認（どちらを返しているか）
    const int& ref1 = max_v1(a, b);
    const int& ref2 = max_v2(a, b);
    
    std::cout << "Address of a: " << &a << std::endl;
    std::cout << "Address of b: " << &b << std::endl;
    std::cout << "Address returned by max_v1: " << &ref1 << std::endl;
    std::cout << "Address returned by max_v2: " << &ref2 << std::endl;
    
    return 0;
}
