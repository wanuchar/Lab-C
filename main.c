//
//  main.c
//  Lab1
//
//  Created by YAN on 2/17/20.
//  Copyright © 2020 YAN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lennum (int a) {
    int temp = a, count = 0;
       while (temp > 0) {
           temp/=10;
           count++;
       }
    return count;
}

int main(int argc, const char * argv[]) {
   //int num1, num2;
    char* numer1 = (char*)malloc(32);
    char* numer2 = (char*)malloc(32);
    printf("Enter two numbers to multiply: ");
    scanf("%s", numer1);
    scanf("%s", numer2);
    
    unsigned long len1, len2;
    len1 = strlen(numer1);
    len2 = strlen(numer2);
    
    int num = 0, num2 = atoi(numer2), tempnum = 0, flag = 0;
    
    long i = len1 - 1;
    while (i >= 0) {
        num = (numer1[i] - '0')*num2;
        if (flag == 1) {
            printf(" ");
            flag = 0;
        }
            if (lennum(num) < lennum(tempnum)) {
                printf(" ");
                flag = 1;
        }
        for (long j = i; j > 0; j--) {
            printf(" ");
            
        }
        printf("%d\n", num);
        i--;
        tempnum = num;
    }
    
    num = atoi(numer1)*num2;
    
    for (long j = lennum(num); j > 0; j--) {
        printf("-");
    }
    
    printf("\n%d\n", num);
    
    return 0;
}
