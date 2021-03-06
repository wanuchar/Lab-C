#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;

struct Stack
{
    int data;
    Stack *next;
} *begin;

Stack* push(Stack* p, int in)
{
    Stack *t = malloc(sizeof(Stack));
    t->data = in;
    t->next = p;
    return t;
}

Stack* pop(Stack* p, int *out)
{
    Stack *t = p;
    *out = p->data;
    p = p->next;
    free (t);
    return p;
}

void show(Stack* p)
{
    Stack *t = p;
    while (t)
    {
        printf("%d%s", t->data, "\n");
        t = t->next;
    }
}

Stack* inversion(Stack *p)
{
    Stack *t = p, *temp = NULL;
    int a;
    while (t)
    {
        a = t->data;
        temp = push(temp, a);
        t = t->next;
    }
    return temp;
}

int main(int argc, const char * argv[])
{
   
    int a, num, res, prov;
    Stack *invers = malloc(sizeof(Stack));
    while(1)
    {
        printf("Choose function: \n1)Add\n2)remove\n3)show\n4)invers\nElse: exit\n");
        res = scanf("%d", &a);
        if (!res)
        {
            printf("You must enter an integer. Try again. \n");
            return 0;
        }
        switch (a)
        {
            case 1:
                printf("Enter the number: ");
                prov = scanf("%d", &num);
                if (!prov)
                {
                    printf("You must enter an integer. Try again. \n");
                    return 0;
                }
                begin = push(begin, num);
                break;
            case 2:
                if (!begin)
                {
                    printf("Stack is empty. Try again.\n");
                    continue;
                }
                begin = pop(begin, &num);
                printf("%s%d%s","You remove: ", num, "\n");
                break;
            case 3:
                if (!begin)
                {
                    printf("Stack is empty. Try again.\n");
                    continue;
                }
                printf("Your stack: \n");
                show(begin);
                break;
            case 4:
                if (!begin)
                {
                    printf("Stack is empty. Try again.\n");
                    continue;
                }
                invers = inversion(begin);
                printf("Your invers stack: \n");
                show(invers);
                break;
            default:
                printf("Program closed.\n");
                return 0;
                break;
        }
    }
    return 0;
}
