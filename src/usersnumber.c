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

