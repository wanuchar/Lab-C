//
//  main.c
//  Lab2.1.18
//
//  Created by YAN on 2/25/20.
//  Copyright © 2020 YAN. All rights reserved.
//

#include <stdio.h>

struct Data {
    int minInWeb;
    int minOutWeb;
    int minLLP;
    int sms;
};

struct tarrif {
    char arr[30];
    int minInWeb;
    int minOutWeb;
    int minLLP;
    int sms;
};

struct Data IData (void);
void ChTarr(struct Data* ObjData, struct tarrif* ObjTar);


int main(int argc, const char * argv[]) {
    int ch;
    struct tarrif tar[5] = {"Без Лимита", 500, 500,500, 40,
        "Комфорт S", 1000, 60, 60, 30,
        "Комфорт M", 1500, 120, 120, 45,
        "Привет.Звонки", 2000, 300,300, 10,
        "Комфорт L", 3000, 3000,3000, 120
    };
    
    struct Data inform[1];
    while (1) {
         printf("\nВыберите функцию: \n1)Ввод данных \n2)Рассчет оптимального тарифа \n3)Информационные услуги \n4)Обратная связь \n5)Завершить программу\n\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                inform[0] = IData();
                break;
            case 2:
                ChTarr(inform, tar);
                break;
            case 3:
                printf("\nВнутри сети Другие сети Городские линии SMS\n");
                for (int i = 0; i < 5; i++) {
                    printf("\n%s%s%d%s%d%s%d%s%d%s", tar[i].arr, " ", tar[i].minInWeb," ", tar[i].minOutWeb," ", tar[i].minLLP," ", tar[i].sms, "\n");
                }
                break;
            case 4:
                printf("\n150 - единый номер контакт-центра (звонок бесплатный из всех сетей операторов Беларуси)\n");
                printf("\n7100 - (с мобильного A1 - 0,03 руб.)\n");
                printf("\nв роуминге по телефону +375 29 6 000 150 (оплата согласно роуминговым тарифам)\n");
                printf("\nЭлектронный адрес для обслуживания физических лиц: 150@A1.by\n");
                break;
            case 5:
                return 0;
                break;
                
            default:
                printf("\nВыберите одну из предложенных функций\n");
                break;
        }
    }
    return 0;
}

struct Data IData() {
    struct Data obj[1];
   
    printf("\nКоличество минут разговоров внутри сети: ");
    scanf("%d", &obj[0].minInWeb);
    printf("Количество минут разговоров другим операторам: ");
    scanf("%d", &obj[0].minOutWeb);
    printf("Количество минут разговоров на городскую линию: ");
    scanf("%d", &obj[0].minLLP);
    printf("Количество SMS: ");
    scanf("%d", &obj[0].sms);
    
    return obj[0];
}

void ChTarr(struct Data* ObjData, struct tarrif* ObjTar)
{
    int count = 0;
    int flag[5] = {0};
    
        if (ObjData[0].minInWeb >=0 && ObjData[0].minInWeb <= ObjTar[0].minInWeb) {
            flag[0]++;
        } else if (ObjData[0].minInWeb >=3000) {
            flag[4]++;
        } else {
            for (int i = 0; i < 5; i++) {
                if (ObjData[0].minInWeb >= ObjTar[i].minInWeb) {
                    count++;
                }
            }
            flag[count]++;
            count = 0;
        }
        
        if (ObjData[0].minOutWeb >=0 && ObjData[0].minOutWeb <= ObjTar[0].minOutWeb) {
            flag[0]++;
        } else if (ObjData[0].minOutWeb >=3000) {
            flag[4]++;
        } else {
            for (int i = 0; i < 5; i++) {
                if (ObjData[0].minOutWeb >= ObjTar[i].minOutWeb) {
                    count++;
                }
            }
            flag[count]++;
            count = 0;
        }
       
        if (ObjData[0].minLLP >=0 && ObjData[0].minLLP <= ObjTar[0].minLLP) {
            flag[0]++;
        } else if (ObjData[0].minLLP >=3000) {
            flag[4]++;
        } else {
            for (int i = 0; i < 5; i++) {
                if (ObjData[0].minLLP >= ObjTar[i].minLLP) {
                    count++;
                }
            }
            flag[count]++;
            count = 0;
        }
        
        if (ObjData[0].sms >=0 && ObjData[0].sms <= ObjTar[0].sms) {
            flag[0]++;
        } else if (ObjData[0].sms >=3000) {
            flag[4]++;
        } else {
            for (int i = 0; i < 5; i++) {
                if (ObjData[0].sms >= ObjTar[i].sms) {
                    count++;
                }
            }
            flag[count]++;
            count = 0;
        }
    int max = flag[0], index = 0;
    
    for (int i = 0; i < 5; i++) {
        if (flag[i] > max) {
            max = flag[i];
            index = i;
        }
    }
    
    printf("\nНаиболее подходящий тариф для ваших запросов это: \n");
    printf("%s%s%d%s%d%s%d%s%d%s", ObjTar[index].arr, " ", ObjTar[index].minInWeb," ", ObjTar[index].minOutWeb," ", ObjTar[index].minLLP," ", ObjTar[index].sms, "\n");
   
}
