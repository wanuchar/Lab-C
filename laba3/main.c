//
//  main.c
//  Lab3.2.27
//
//  Created by YAN on 3/18/20.
//  Copyright © 2020 YAN. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void combSort(int *decNumArray, int n);

int main(int argc, const char * argv[]) {
    int n, m, res;
    
    printf("Введите количество строк массива: ");
    res = scanf("%d", &n);
    fflush(stdin);
    if (!res) {
        printf("Необходимо ввести целое число\n");
        return 0;
    }
   
    printf("Введите количество столбцов массива: ");
    res = scanf("%d", &m);
    fflush(stdin);
    if (!res) {
          printf("Необходимо ввести целое число\n");
          return 0;
    }
    
    int** a = (int**)malloc(n*sizeof(int*));
    if (!a) {
        printf("Allocation failure");
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(m*sizeof(int));
        if (!a[i]) {
            printf("Allocation failure");
            exit(0);
        }
    }
    
    srand((unsigned int)(time(NULL)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % 2;
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
    
    int decNum = 0;
    int* decNumArray = (int*)malloc(n*sizeof(int));
    if (!decNumArray) {
           printf("Allocation failure");
           exit(0);
       }
    for (int i = 0; i < n; i++) {
        for (int k = m - 1, j = 0; k>=0; k--, j++) {
            decNum+=a[i][j]*pow(2, k);
        }
        decNumArray[i] = decNum;
        decNum = 0;
    }
    
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    
    combSort(decNumArray, n);
    
    for (int i=0; i<n; i++) {
        if (decNumArray[i]==decNumArray[i+1]) {
            for (int j=i; j<n; j++) {
                decNumArray[j]=decNumArray[j+1];
            }
        n--;
        i--;
        }
    }
    
    int** binArray = (int**)malloc(n*sizeof(int*));
    if (!binArray) {
           printf("Allocation failure");
           exit(0);
       }
    for (int i = 0; i < n; i++) {
        binArray[i] = (int*)malloc(m*sizeof(int));
        if (!binArray[i]) {
            printf("Allocation failure");
            exit(0);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            binArray[i][j] = decNumArray[i]%2;
            decNumArray[i]/=2;
        }
    }
    
    free(decNumArray);
  
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d", binArray[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < n; i++) {
        free(binArray[i]);
    }
    free(binArray);
    

    return 0;
}

void combSort(int *decNumArray, int n) {
    int temp = 0;
    double fakt = 1.2473309;
    double step = n - 1;
    
    while (step >= 1) {
        for (int i = 0; i + step < n; i++) {
            if (decNumArray[i] > decNumArray[i + (int)step]) {
                temp = decNumArray[i];
                decNumArray[i] = decNumArray[i + (int)step];
                decNumArray[i + (int)step] = temp;
            }
        }
        step /= fakt;
    }
    
    int swapped = 1;
    
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (decNumArray[j] > decNumArray[j + 1]) {
                temp = decNumArray[j];
                decNumArray[j] = decNumArray[j + 1];
                decNumArray[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
    
}
