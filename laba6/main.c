#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct Node Node;
int const n = 10;

struct Node
{
    Node* right;
    Node* left;
    Node* mid;
    int key;
    int height;
} *root;

int height(Node *p)
{
    return p?p->height:0;
}

void fixheight(Node* p)
{
    int hl = height(p->left);
    int hr = height(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

void push(int a, Node **item)
{
    if (*item == NULL) {
        *item = (Node *)calloc(1, sizeof(Node));
        (*item)->key = a;
        (*item)->left = NULL;
        (*item)->mid = NULL;
        (*item)->right = NULL;
        (*item)->height = 0;
    }
    else if (a < (*item)->key)
    {
        fixheight((*item));
        push(a, &(*item)->left);
    }
    else if (a > (*item)->key)
    {
        fixheight((*item));
        push(a, &(*item)->right);
    }
    else
    {
        fixheight((*item));
        push(a, &(*item)->mid);
    }
}

void show(Node *item)
{
    if (item->left)
    show(item->left);
    printf("%d ", item->key);
    if (item->mid)
    show(item->mid);
    if (item->right)
    show(item->right);
}



int main(int argc, const char * argv[]) {
    int sym, i;
    srand((unsigned int)time(NULL));
    for (i = 0; i < n; i++) {
        sym = rand()%31;
        push(sym, &root);
        fixheight(root);
    }
    show(root);
    printf("%s%d%s", "\nTree height: ", root->height, "\n");
    return 0;
}
