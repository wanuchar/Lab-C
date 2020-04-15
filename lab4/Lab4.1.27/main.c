//
//  main.c
//  Lab4.1.27
//
//  Created by YAN on 3/30/20.
//  Copyright © 2020 YAN. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char surname[5][20] = { {"Иванов"}, {"Петров"}, {"Смирнов"}, {"Степанов"}, {"Алексеев"} };
    char holidays[4][30] = {{"с Днем рождения"}, {"с Рождеством"}, {"с Новым годом"}, {"с Пасхой"}};
    char congr[9][40] = {{"счастья"}, {"здоровья"}, {"любви"}, {"всех благ"}, {"удачи"}, {"долголетия"}, {"исполнения желаний"}, {"хороших друзей"}, {"много денег"}};
    srand((unsigned int)(time(NULL)));
    int sur, hol;
    sur = rand()%5;
    hol = rand()%4;
    printf("%s%s%s%s", surname[sur], ", поздравляю ", holidays[hol], ", желаю ");
    int con;
    int temp[2][1];
    for (int i = 0; i < 3; i++) {
        con = rand()%9;
        if (i == 0) {
            temp[i][0] = con;
        } else if (i == 1) {
            while (con == temp[0][0]) {
                con = rand()%9;
            }
            temp[i][0] = con;
        } else if (i == 2) {
            while (con == temp[0][0] || con == temp[1][0]) {
                con = rand()%9;
            }
        }
        printf("%s", congr[con]);
        if (i == 2) {
            printf(".");
        }else printf(", ");
    }
    printf("\n");
    return 0;
}
