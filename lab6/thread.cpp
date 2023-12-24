#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx; // мьютекс для синхронизации вывода

// Функция, которую выполняет каждый поток
void threadFunction(int threadNumber) {
    // Что-то вычисляем (в данном случае, просто номер потока умножаем на 2)
    int result = threadNumber * 2;

    // Захватываем мьютекс для синхронизации вывода
    lock_guard<mutex> lock(mtx);

    // Выводим результат
    cout << "Поток " << threadNumber << " - Результат: " << result << endl;
}

int main() {
    const int numThreads = 8; // Количество потоков

    // Создаем массив потоков
    thread threads[numThreads];

    // Запускаем потоки
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = thread(threadFunction, i + 1);
    }

    // Ждем завершения всех потоков
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    return 0;
}
