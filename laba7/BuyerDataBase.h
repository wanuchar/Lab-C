#ifndef BuyerDataBase_h
#define BuyerDataBase_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BuyerBase BuyerBase;
typedef struct Contacts Contacts;

struct Contacts
{
    unsigned int number;
    char email[30];
};

struct BuyerBase {
    char name[60];
    Contacts contact;
    char desiredBrand[15];
    int year;
    bool state;
    int maxPrice;
    BuyerBase *next, *prev;
};

BuyerBase* addBuyer(char *n, Contacts c, char *dB, int y, int st, int mP,BuyerBase *head);
void delAllBuyer(BuyerBase *head);
void showBuyer(BuyerBase *head);

#endif /* BuyerDataBase_h */
