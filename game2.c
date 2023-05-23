#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_MATCHES = 100;
const int MIN_MATCHES = 1;
const int MAX_TAKE = 10;

int main() {
  int matches = MAX_MATCHES;
  int currentPlayer = 1;
  int num;

  printf("Добро пожаловать в игру '100 Спичек'!\n");

  while (matches > 0) {
    printf("\nНа столе осталось %d спичек.\n", matches);
    printf("Игрок %d, сколько спичек вы хотите взять (от %d до %d)? ",
           currentPlayer, MIN_MATCHES, MAX_TAKE);

    char input[10];
    fgets(input, sizeof(input), stdin);

    // Проверяем, является ли введенное значение числом
    bool isNumber = true;
    size_t inputLength = strlen(input);
    for (size_t i = 0; i < inputLength; i++) {
      if (!isdigit(input[i]) && input[i] != '\n') {
        isNumber = false;
        break;
      }
    }

    if (!isNumber) {
      printf("Ошибка: введите целое число.\n");
      continue;
    }

    num = atoi(input);

    if (num < MIN_MATCHES || num > MAX_TAKE || num > matches) {
      printf("Ошибка: введите число от %d до %d и не больше, чем осталось "
             "спичек.\n",
             MIN_MATCHES, MAX_TAKE);
      continue;
    }

    matches -= num;
    currentPlayer = (currentPlayer % 2) + 1;
  }
  currentPlayer = (currentPlayer % 2) + 1;

  printf("\nИгрок %d победил! Он взял последнюю спичку.\n", currentPlayer);

  return 1;
}
