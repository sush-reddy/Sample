#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void PrintListDLL(struct DLLNode* headcopy)
{
    while(headcopy)
    {
        printf("%d ", headcopy->data);
        headcopy = headcopy->next;
    }
}

void InsertDLL(struct DLLNode** head, int data)
{
     struct DLLNode* newNode = malloc(sizeof(struct DLLNode));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void InsertNth_DLL(struct DLLNode** head, int pos, int data)
{
    struct DLLNode* newNode = malloc(sizeof(struct DLLNode));
    struct DLLNode* current;
    int i=0;

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(pos == 0)
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    else {
        current = *head;
        for(i=0;i<pos; i++)
            current = current->next;

        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
}


struct DLLNode * Reverse_DLL(struct DLLNode* head)
{
    struct DLLNode* temp = head;

    while(temp)
    {
        temp = head->next;
        head->next = head->prev;
        head->prev = temp;
        if(temp)
            head = temp;
    }

    return head;
}


struct DLLNode* sortedInsert_DLL(struct DLLNode* head, int data) {

    struct DLLNode* current = head;
    struct DLLNode* newNode = new struct DLLNode;

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

//    cout << "new is " << newNode->data;
    if(head == NULL || newNode->data < head->data)
    {
        newNode->next = head;
        if(head)
            head->prev = newNode;
        return newNode;
    }

    while(current->next && (newNode->data > current->next->data))
    {
        current = current->next;
    }

//    cout << " current is " << current->data;
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next)
        current->next->prev = newNode;
    current->next = newNode;

    return head;
}
