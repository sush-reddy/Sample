#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int IsEmpty()
{
    if (front == NULL)
        return 1;
}

void Enqueue(int data)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(front == NULL && rear == NULL)
    {
        front = newNode;
        rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void Dequeue()
{
    struct Node* temp = front;

    if(front == NULL)
        return;
    if(front == rear) {
        front = rear = NULL;
    }

    front = front->next;
    free(temp);
    return;
}

int Front()
{
    if(front)
        return (front->data);
    else
        printf("\nQueue is empty");
}

int main()
{
    Enqueue(5);
    Enqueue(10);
    Enqueue(15);
    Enqueue(20);

    printf("\n Element at front - %d, at rear - %d", front->data, rear->data);
    printf("\n Front = %d", Front());
    Dequeue();
    printf("\n After 1 Dequeue, Element at front - %d, at rear - %d", front->data, rear->data);

    Enqueue(25);
    printf("\n Element at front - %d, at rear - %d", front->data, rear->data);
}
