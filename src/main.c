#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "usersnumber.h"

int main() {
    printf("COWS'N'BULLS\n");
    printf("Правила игры:\n");
    printf("Компьютер загадывает четырехзначное число, цифры в котором не повторяются. Твоя задача - отгадать это число. После каждого ввода числа приложение выведет число быков и коров. Быки - количество верно угаданных цифр, стоящих на верных позициях. Коровы - верно угаданные цифры, стоящие на неверных позициях. Удачи!\n");
    int number[4], player[4];
    int counter = 0;
    comp_number (number);
    printf("Компьютер загадал число. Твой ход.\n");
    input(player);
    while (memcmp (number, player, 4 * sizeof(int)) != 0) {
        printf("Числа разные!\n");
        cowsnbulls_counter (number, player, 4);
        input(player);
        counter++;
    }
    printf("Ты угадал число после %d попыток! Поздравляем!\n", counter);
    return 0;
}
