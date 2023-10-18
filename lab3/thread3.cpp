#include <iostream>
#include <vector>
#include <thread>

// Функция для вычисления скалярного произведения для определенного участка векторов
int scalarProduct(const std::vector<int> &v1, const std::vector<int> &v2, int start, int end)
{
    int result = 0;
    for (int i = start; i < end; ++i)
    {
        result += v1[i] * v2[i];
    }
    return result;
}

int main()
{
    std::vector<int> vector1 = {1, 2, 3, 4, 5};
    std::vector<int> vector2 = {6, 7, 8, 9, 10};

    int numThreads = 5;

    std::vector<std::thread> threads;
    std::vector<int> results(numThreads, 0);

    // Запуск потоков для вычисления скалярного произведения
    for (int i = 0; i < numThreads; ++i)
    {
        threads.emplace_back(std::thread([&vector1, &vector2, &results, i, numThreads]()
                                         {
            int start = i * (vector1.size() / numThreads);
            int end = (i + 1) * (vector1.size() / numThreads);
            results[i] = scalarProduct(vector1, vector2, start, end); }));
    }

    // Ожидание завершения всех потоков
    for (auto &thread : threads)
    {
        thread.join();
    }

    // Суммирование результатов
    int finalResult = 0;
    for (auto &res : results)
    {
        finalResult += res;
    }

    std::cout << "Скалярное произведение векторов: " << finalResult << std::endl;

    return 0;
}
