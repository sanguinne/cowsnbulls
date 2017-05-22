#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("COWS'N'BULLS\n");
    printf("Правила игры:\n");
    printf("Компьютер загадывает четырехзначное число, цифры в котором не повторяются. Твоя задача - отгадать число. Удачи!\n");
    int number[4];
    comp_number (&number);
    printf("\nКомпьютер загадал число.\n");
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
                printf("%d", num[i]);
                i++;
            }
        }
    }
}
