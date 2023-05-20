#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

const int MAX_MATCHES = 100;
const int MIN_MATCHES = 1;
const int MAX_TAKE = 10;

int main()
{
    int matches = MAX_MATCHES;

    printf("Добро пожаловать в игру 'Спички'!\n");

    while (matches > 0)
    {
        printf("\nНа столе осталось %d спичек.\n", matches);
        printf("Сколько спичек вы хотите взять (от %d до %d)? ", MIN_MATCHES, MAX_TAKE);

        char input[10];
        fgets(input, sizeof(input), stdin);

        // Проверяем, является ли введенное значение числом
        bool isNumber = true;
        size_t inputLength = strlen(input);
        for (size_t i = 0; i < inputLength; i++)
        {
            if (!isdigit(input[i]) && input[i] != '\n')
            {
                isNumber = false;
                break;
            }
        }

        if (!isNumber)
        {
            printf("Ошибка: введите целое число.\n");
            continue;
        }

        int num = atoi(input);

        if (num < MIN_MATCHES || num > MAX_TAKE || num > matches)
        {
            printf("Ошибка: введите число от %d до %d и не больше, чем осталось спичек.\n", MIN_MATCHES, MAX_TAKE);
            continue;
        }

        matches -= num;

        // Ход компьютера
        int computerTake = (matches - 1) % (MAX_TAKE + 1);
        if (computerTake < MIN_MATCHES)
            computerTake = MIN_MATCHES;

        printf("Компьютер взял %d спичек.\n", computerTake);
        matches -= computerTake;
    }

    printf("\nВы проиграли! На столе не осталось спичек.\n");

    return 0;
}
