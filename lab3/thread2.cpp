#include <iostream>
#include <thread>

// Функция, которую будут выполнять потоки
void threadFunction(int intValue, float floatValue, double *doubleValue)
{
    std::cout << "Поток ID: " << std::this_thread::get_id() << std::endl;
    std::cout << "int значение: " << intValue << std::endl;
    std::cout << "float значение: " << floatValue << std::endl;
    std::cout << "double значение: " << *doubleValue << std::endl;
}

int main()
{
    int intValue = 42;
    float floatValue = 3.14;
    double doubleValue = 2.71828;

    // Создание и запуск 3 потоков
    std::thread thread1(threadFunction, intValue, floatValue, &doubleValue);
    std::thread thread2(threadFunction, intValue + 1, floatValue + 1, &doubleValue);
    std::thread thread3(threadFunction, intValue + 2, floatValue + 2, &doubleValue);

    // Ожидание завершения потоков
    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
