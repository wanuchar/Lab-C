//
//  main.c
//  Lab4.2.27
//
//  Created by YAN on 3/30/20.
//  Copyright © 2020 YAN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int searchLetter(char sym);
int searchOperand(char sym);
float strToNum(char *s);

int main(int argc, const char * argv[]) {
    FILE *fExpr;
    FILE *fValue;
    fExpr = fopen("/Users/user/Documents/Прога/Lab4.2.27/Lab4.2.27/expr.txt", "r");
    fValue = fopen("/Users/user/Documents/Прога/Lab4.2.27/Lab4.2.27/value.txt", "r");
    if (fExpr == NULL) {
        printf("Не удалось открыть файл с выражениями\n");
        return 0;
    }
    
    if (fValue == NULL) {
        printf("Не удалось открыть файл со значениями\n");
        return 0;
    }
    
    char sym = '\0', lSym = '\0';
    char let[30];
    char *elet;
    float val = 0, result = 0;
    
    
    elet = fgets(let, sizeof(let), fExpr);
    printf("%s",elet);
    fseek(fExpr, 0, SEEK_SET);
    
    while (!feof(fExpr)) {
        lSym = sym;
        sym = fgetc(fExpr);
        
        if (searchLetter(sym)) {
            while (!feof(fValue)) {
                elet = fgets(let, sizeof(let), fValue);
                if (let[0] == sym && let[1] == '=') {
                    val = strToNum(&let[2]);
                    if (result == 0) {
                        result = val;
                    }
                }
            }
            fseek(fValue, 0, SEEK_SET);
        } else if (searchOperand(sym)) {
            continue;
        } else if (sym == '=')  {
            printf("%.2f%s", result, "\n");
        } else if (sym == '\xff') {
            continue;
        } else printf("неопознанный символ\n");
        
        if (searchOperand(lSym)) {
            if (lSym == '+') {
                result+=val;
            } else if (lSym == '-') {
                result-=val;
            } else if (lSym == '*') {
                result*=val;
            } else if (lSym == '/') {
                if (val == 0) {
                    printf("нельязя делить на 0");
                    exit(0);
                } else result/=val;
            }
        }
    }
    
    fclose(fValue);
    fclose(fExpr);
    return 0;
}

int searchLetter(char sym) {
    if (sym >= 65 && sym <= 90 ) {
        return 1;
    }
    else return 0;
}

int searchOperand(char sym) {
    if (sym == 42 || sym == 43 || sym == 45 || sym == 47) {
        return 1;
    }
    else return 0;
}

float strToNum(char *s) {
    float intp = 0;
    float flop = 0;
   
    int i = 0;
    int sign = 0;
    if (s[i] == '-')
    {
      sign = 1;
      i++;
    }
    while (s[i] >= 0x30 && s[i] <= 0x39)
    {
      intp += (s[i] & 0x0F);
      intp *= 10;
      i++;
    }
    intp /= 10;
    int j = 0;
    float temp;
    if (s[i] == '.' || s[i] == ',') {
        i++;
        while (s[i] >= 0x30 && s[i] <= 0x39)
        {
            j++;
            temp = s[i] & 0x0F;
            for (int f = 0; f < j; f++) {
                temp*=0.1;
            }
            flop += temp;
            i++;
        }
    }
    
    intp += flop;
    
    if (sign == 1)
      intp = -intp;
    
    return intp;
}
