#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Открываем файл для чтения
    FILE *file = fopen("comp_system.txt", "r");

    // Проверяем, удалось ли открыть файл
    if (file == NULL)
    {
        printf("Не удалось открыть файл comp_system.txt\n");
        return 1;
    }

    // Читаем и выводим содержимое файла построчно
    char line[256]; // Буфер для хранения строки
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    // Закрываем файл
    fclose(file);

    return 0;
}
