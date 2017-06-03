#include "usersnumber.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int isnumbercorrect (int i) {
     int arr[10] = {0};
     if(i/1000 > 9 || i/1000 < 1) {
         return 0;
     }
     if (i < 0) {
         return 0;
     }
     while (i) {
         arr[i%10]++;
         i /= 10;
     }
     for(i=0; i<10;i++) {
         if (arr[i] > 1) {
             return 0;
         }
     }
     return 1;
}

void comp_number(int *num)
{
    int i = 0, j, n;
    srand(time(NULL));
    while (i < 4)
    {
        n = rand() % 9 + 1;
        for (j = i; j >= 0; j--)
        {
            if (num[j] == n)
            {
                break;
            }
            else if (j == 0)
            {
                num[i] = n;
                i++;
            }
        }
    }
}

void input(int *user)
{
    int i, j;
    scanf("%d", &i);
    while (isnumbercorrect(i) == 0)
    {
        printf("Число некорректно. Попробуй еще раз.\n");
        scanf("%d", &i);
    }
    for (j = 3; j >= 0; j--)
    {
        user[j] = i % 10;
        i /= 10;
    }
}
void cowsnbulls_counter(int *computer, int *user, int n)
{
    int array[10] = {0};
    int i, bulls = 0, cows = 0;
    for (i = 0; i < n; i++)
    {
        if (computer[i] == user[i])
        {
            bulls++;
        }
        else
        {
            array[computer[i]] = 1;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (array[user[i]] == 1)
        {
            cows++;
        }
    }
    printf("Коровы: %d, быки: %d.\n", cows, bulls);
}
