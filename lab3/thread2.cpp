#include <iostream>
#include <thread>

using namespace std;

// Функция, которая будет выполняться в каждом потоке
void threadFunction(int intValue, float floatValue, double *doubleValue)
{
    // Вывод идентификатора потока
    cout << "Thread ID: " << this_thread::get_id() << endl;

    // Вывод переданных параметров
    cout << "int: " << intValue << endl;
    cout << "float: " << floatValue << endl;

    if (doubleValue != nullptr)
    {
        cout << "double: " << *doubleValue << endl;
    }
}

int main()
{
    int intValue = 42;
    float floatValue = 3.14;
    double doubleValue = 2.71828;

    // Создаем 3 потока и передаем им параметры
    thread thread1(threadFunction, intValue, floatValue, &doubleValue);
    thread thread2(threadFunction, intValue * 2, floatValue * 2, &doubleValue);
    thread thread3(threadFunction, intValue * 3, floatValue * 3, nullptr);

    // Ждем завершения всех потоков
    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
