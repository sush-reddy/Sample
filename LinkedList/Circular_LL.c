#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// Circular Linked list implementation based on Single Linked list
void Print_circular_LL(struct Node *headcopy)
{
    struct Node* current = headcopy;

    if(!headcopy)
        return;

    printf("\nCircular List = ");
    while(current->next != headcopy)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d", current->data);
}

void Insert_Cir_LL(struct Node** head, int data)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    struct Node* current = *head;


    newNode->data = data;

    if(*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    while(current->next != *head)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = (*head);
    (*head) = newNode;

}
