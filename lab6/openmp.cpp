#include <iostream>
#include <omp.h>

int main() {
    const int num_threads = 8; // Установите желаемое количество потоков
    int results[num_threads];

    // Начало параллельной области с использованием OpenMP
    #pragma omp parallel num_threads(num_threads)
    {
        // Получаем номер текущего потока
        int thread_id = omp_get_thread_num();

        // Выполняем задачу для каждого потока
        results[thread_id] = thread_id * thread_id;

        // Синхронизация для вывода результатов в правильном порядке
        #pragma omp barrier

        // Последовательный вывод результатов
        #pragma omp single
        {
            for (int i = 0; i < num_threads; ++i) {
                std::cout << "Thread " << i + 1 << " result: " << results[i] << std::endl;
            }
        }
    } // Конец параллельной области

    return 0;
}
