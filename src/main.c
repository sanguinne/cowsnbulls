#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "usersnumber.h"
void input(int* user);
void comp_number (int* num);
void cowsnbulls_counter (int* computer, int* user, int n);

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
void comp_number (int* num) {
    int i = 0, j, n;
    srand(time(NULL));
    while (i < 4) {
        n = rand() % 9 + 1;
        for (j = i; j >= 0; j--) {
            if (num[j] == n) {
                break;
            }
            else if(j==0) {
                num[i] = n;
                i++;
            }
        }
    }
}
void input(int* user) {
     int i, j;
     scanf("%d", &i);
     while (isnumbercorrect(i)==0) { 
         printf("Число некорректно. Попробуй еще раз.\n");
         scanf("%d", &i);
     }
     for (j = 3; j>=0; j--) {
         user[j] = i%10;
         i /= 10;
     }
}
void cowsnbulls_counter (int* computer, int* user, int n) {
     int array[10] = {0};
     int i, bulls = 0, cows = 0;
     for (i = 0; i < n; i++) {
         if (computer[i] == user[i]) {
             bulls++;
         }
         else {
             array[computer[i]] = 1;
         }
     }
     for (i = 0; i < n; i++) {
         if (array[user[i]] == 1) {
             cows++;
         }
     }
     printf("Коровы: %d, быки: %d.\n", cows, bulls);
}
