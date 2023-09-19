#include <stdio.h>
#include <stdlib.h>

// Функция для создания динамического массива заданного размера и заполнения его индексами
int* createAndFillArray(int size) {
    int* array = (int*)malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Ошибка выделения памяти для массива.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    return array;
}

// Функция для вывода содержимого массива в заданном диапазоне
void printArray(int* array, int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Функция для сохранения массива в двоичный файл
void saveArrayToFile(int* array, int size, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Ошибка открытия файла для записи.\n");
        exit(1);
    }

    fwrite(array, sizeof(int), size, file);
    fclose(file);
}

// Функция для считывания содержимого массива из двоичного файла и вывода в консоль
void readArrayFromFile(int** array, int* size, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка открытия файла для чтения.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    *size = ftell(file) / sizeof(int);
    fseek(file, 0, SEEK_SET);

    *array = (int*)malloc((*size) * sizeof(int));
    if (*array == NULL) {
        printf("Ошибка выделения памяти для массива.\n");
        exit(1);
    }

    fread(*array, sizeof(int), *size, file);
    fclose(file);
}

int main() {
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    int* array = createAndFillArray(size);

    printf("Содержимое массива: ");
    printArray(array, 0, size - 1);

    saveArrayToFile(array, size, "array.bin");
    printf("Массив сохранен в файле 'array.bin'.\n");

    int* loadedArray;
    int loadedSize;

    readArrayFromFile(&loadedArray, &loadedSize, "array.bin");
    printf("Содержимое загруженного массива: ");
    printArray(loadedArray, 0, loadedSize - 1);

    free(array);
    free(loadedArray);

    return 0;
}

