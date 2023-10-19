#include <iostream>
#include <thread>
#include <future>

int add(int a, int b) {
    return a + b;
}

int main() {
    std::future<int> f = std::async(add, 5, 15);
    int result = f.get();
    std::cout << "Результат: " << result << std::endl;
    return 0;
}
