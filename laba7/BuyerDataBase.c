#include "BuyerDataBase.h"

BuyerBase *addBuyer(char *n, Contacts c, char *dB, int y, int st, int mP,BuyerBase *head)
{
    int i = 0;
    BuyerBase *newItem = calloc(1, sizeof(BuyerBase));
    if (!newItem)
    {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    for (i = 0; n[i] != '\0'; i++)
        newItem->name[i] = n[i];
    newItem->contact = c;
    for (i = 0; dB[i] != '\0'; i++)
        newItem->desiredBrand[i] = dB[i];
    newItem->year = y;
    if (st == 1)
        newItem->state = 1;
    else newItem->state = 0;
    newItem->maxPrice = mP;
    if (!head)
    {
            head = newItem;
    }
    else
    {
        BuyerBase *current = head;
        for (i = 1; current->next != NULL ; i++)
            current = current->next;
        if (current->next)
        {
            current->next->prev = newItem;
        }
            newItem->next = current->next;
            current->next = newItem;
            newItem->prev = current;
            current = newItem;
        }
    return head;
}

void showBuyer(BuyerBase *head)
{
    if (head)
    {
        printf("%s%s%s", "ФИО: ", head->name, "\n");
        printf("%s%d%s%s%s","Телефон: ", head->contact.number, "\nПочта: ", head->contact.email, "\n");
        printf("%s%s%s","Желаемая марка: ", head->desiredBrand, "\n");
        printf("%s%d%s","Год: ", head->year, "\n");
        if (head->state == 1)
        {
            printf("Cостояние автомобиля: новый\n");
        } else printf("Cостояние автомобиля: б/у\n");
        printf("%s%d%s", "Финансовые возможности: ", head->maxPrice, "\n");
        printf("\n");
        showBuyer(head->next);
    }
    else printf("\n");
}

void delAllBuyer(BuyerBase *head)
{
    if (head) {
        delAllBuyer(head->next);
        free(head);
    }
}
