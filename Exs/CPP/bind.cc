
#include <iostream>
#include <functional>

// 定义一个普通函数
int multiply(int a, int b) {
    return a * b;
}

int main() {
    // 使用 std::bind 绑定 multiply 函数的第一个参数为 10
    auto bound_func = std::bind(multiply, 10, std::placeholders::_1);
    
    // 现在 bound_func 是一个只接受一个参数的函数
    std::cout << "10 * 5 = " << bound_func(5) << std::endl;
    
    return 0;
}
