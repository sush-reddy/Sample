#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* Top = NULL;

void Push(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = Top;
    Top = newNode;
}

void Pop(void)
{
    struct Node* temp;

    temp = Top;
    Top = Top->next;
    free(temp);
}

int Top_of_stack(void)
{
    return(Top->data);
}

int IsEmpty()
{
    if (Top == NULL)
        return 1;
    else
        return 0;
}

void Print_stack()
{
    struct Node* temp = Top;
    while(temp)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    Push(1);
    Print_stack();
    Push(2);
    Print_stack();
    Push(10);
    Print_stack();
    Pop();
    Print_stack();
    Push(3);
    Print_stack();
    printf("\n Top of stack = %d", Top_of_stack());
}
