#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int MAX_MATCHES = 100;
const int MIN_MATCHES = 1;
const int MAX_TAKE = 10;

void playerTurn(int* matches);
void computerTurn(int* matches);

int main()
{
    int matches = MAX_MATCHES;

    printf("Добро пожаловать в игру '100 спичек'!\n");

    while (matches > 0) {
        printf("\nНа столе осталось %d спичек.\n", matches);

        // Ход игрока
        playerTurn(&matches);

        if (matches <= 0) {
            printf("\nПоздравляем! Вы победили, взяв последнюю спичку.\n");
            break;
        }

        // Ход компьютера
        computerTurn(&matches);

        if (matches <= 0) {
            printf("\nК сожалению, вы проиграли. Компьютер взял последнюю "
                   "спичку.\n");
            break;
        }
    }

    return 0;
}

void playerTurn(int* matches)
{
    int num;

    while (true) {
        printf("Сколько спичек вы хотите взять (от %d до %d)? ",
               MIN_MATCHES,
               MAX_TAKE);

        char input[10];
        fgets(input, sizeof(input), stdin);

        // Проверяем, является ли введенное значение числом
        bool isNumber = true;
        for (int i = 0; input[i] != '\n'; i++) {
            if (!isdigit(input[i])) {
                isNumber = false;
                break;
            }
        }

        if (!isNumber) {
            printf("Ошибка: введите целое число.\n");
            continue;
        }

        num = atoi(input);

        if (num < MIN_MATCHES || num > MAX_TAKE || num > *matches) {
            printf("Ошибка: введите число от %d до %d и не больше, чем "
                   "осталось "
                   "спичек.\n",
                   MIN_MATCHES,
                   MAX_TAKE);
            continue;
        }

        *matches -= num;
        break;
    }
}

void computerTurn(int* matches)
{
    int num;

    // Генерируем случайное количество спичек для хода компьютера
    num = (rand() % MAX_TAKE) + MIN_MATCHES;

    if (num > *matches)
        num = *matches;

    *matches -= num;

    printf("\nХод компьютера: Компьютер взял %d спичек.\n", num);
}
