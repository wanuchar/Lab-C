#ifndef CarDataBase_h
#define CarDataBase_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct CarBase CarBase;

struct CarBase
{
    char brand[15];
    int year;
    int engineVolume;
    bool state;
    int price;
    CarBase *next, *prev;
};

CarBase* addByStep(char *b, int y, int enV, int st, int p, CarBase *head);
CarBase* add(CarBase *newItem, CarBase *head);
CarBase* search(CarBase *head, int num);
CarBase* sortPrice(CarBase *head, CarBase *buff, int right);
CarBase* sortYear(CarBase *head, CarBase *buff, int right);
void delAll(CarBase *head);
void show(CarBase *head);
int count(CarBase *head);


#endif /* CarDataBase_h */
