#include <iostream>
#include <vector>

using namespace std;

// Функция для вычисления скалярного произведения векторов
double dotProduct(const vector<int> &a, const vector<int> &b, const int &size) {
    int result = 0;

    // Директива pragma omp parallel for распараллеливает цикл
    #pragma omp parallel for reduction(+:result)
    for (int i = 0; i < size; ++i) {
        result += a[i] * b[i];
    }

    return result;
}

int main() {
    // Инициализация векторов
    vector<int> vector1 = {1, 2, 3, 4, 5};
    vector<int> vector2 = {6, 7, 8, 9, 10};

    // Проверка на одинаковую длину векторов
    if (vector1.size() != vector2.size())
    {
        cerr << "Ошибка: Векторы должны быть одинаковой длины." << endl;
        return 1;
    } 

    int size = vector1.size();
    
    int result = dotProduct(vector1, vector2, size);

    cout << "Скалярное произведение: " << result << endl;

    return 0;
}
