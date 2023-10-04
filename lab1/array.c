#include <stdio.h>
#include <stdlib.h>

// Функция для создания динамического массива указанного пользователем размера
int *createArray(int size)
{
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL)
    {
        printf("Ошибка выделения памяти для массива.\n");
        exit(1);
    }
    return array;
}

// Функция для заполнения массива индексами
void fillArrayWithIndices(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = i;
    }
}

// Функция для вывода содержимого массива в заданном диапазоне
void printArrayInRange(int *array, int start, int end)
{
    if (start < 0 || start > end)
    {
        printf("Некорректный диапазон.\n");
        return;
    }

    for (int i = start; i <= end; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Функция для сохранения массива в двоичный файл
void saveArrayToBinaryFile(int *array, int size, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        printf("Ошибка открытия файла для записи.\n");
        exit(1);
    }
    fwrite(array, sizeof(int), size, file);
    fclose(file);
}

// Функция для считывания содержимого массива из двоичного файла и вывода в консоль
void readArrayFromBinaryFile(int **array, int *size, const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Ошибка открытия файла для чтения.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    *size = ftell(file) / sizeof(int);
    fseek(file, 0, SEEK_SET);

    *array = (int *)malloc((*size) * sizeof(int));
    if (*array == NULL)
    {
        printf("Ошибка выделения памяти для массива.\n");
        exit(1);
    }

    fread(*array, sizeof(int), *size, file);
    fclose(file);
}

int main()
{
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    int *array = createArray(size);
    fillArrayWithIndices(array, size);

    int start, end;
    printf("Введите начальный индекс диапазона: ");
    scanf("%d", &start);
    printf("Введите конечный индекс диапазона: ");
    scanf("%d", &end);

    printf("Содержимое массива в заданном диапазоне: ");
    printArrayInRange(array, start, end);

    saveArrayToBinaryFile(array, size, "array.bin");
    printf("Массив сохранен в файле 'array.bin'.\n");

    int *loadedArray;
    int loadedSize;

    readArrayFromBinaryFile(&loadedArray, &loadedSize, "array.bin");
    printf("Содержимое загруженного массива: ");
    printArrayInRange(loadedArray, 0, loadedSize - 1);

    free(array);
    free(loadedArray);

    return 0;
}
