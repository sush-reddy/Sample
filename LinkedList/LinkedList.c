#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/* Insert a node at the head.
 * Can also be named as Push() to indicate Push() operation in Stack
 */
void Insert(struct Node** headref, int data)
{
    struct Node* new;

    new = malloc(sizeof(struct Node));

    if(new == NULL)
        return;

    new->data = data;

    new->next = *headref;

    *headref = new;
}

/* PrintList takes a Node pointer.
 * When head is passed, the func is dealing with a local copy of the head node.
 */
void PrintList(struct Node* headcopy)
{
    while(headcopy)
    {
        printf("%d ", headcopy->data);
        headcopy = headcopy->next;
    }
}

int Length(struct Node* headcopy)
{
    int count=0;
    while (headcopy)
    {
        headcopy = headcopy->next;
        count++;
    }
    return count;
}

void InsertAtEnd(struct Node** head, int data)
{
    struct Node *new;
    struct Node *tmp;

    new = malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
    }
    else {
        tmp = *head;
        while(tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

struct Node * Reverse_list_recurse(struct Node *head)
{
    struct Node *new_head;

    if (head->next == NULL)
        return head;
    else {
        new_head = Reverse_list_recurse(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
}

struct Node * reverse_list(struct Node *head)
{
    struct Node *prevNode, *nextNode;

    if(!head)
        return NULL;

    prevNode = NULL;

    while(head)
    {
        nextNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
    }

    return prevNode;
}

struct Node* deleteNthNode(struct Node* head, int position) {

    int i=0;
    struct Node* temp = head;

    if (position == 0)
    {
        head = head->next;
        free(temp);
        return head;
    }
    while(temp && i < position-1) {
        temp = temp->next;
        i++;
    }

    struct Node* foundNode = temp->next;
    temp->next = temp->next->next;
    free(foundNode);
    return head;
}

/*
int main()
{
    int i, num, data;

    printf("\n Enter the number of elements you wish to have in linked list\n");
    scanf("%d", &num);

    printf("\nEnter the elements\n");
    for(i=0; i<num; i++)
    {
        scanf("%d", &data);
        Insert(&head, data);
//        InsertAtEnd(&head, data);
// Alternatively, InsertAtEnd can be achieved using Insert itself.
// Insert first element using Insert() And for all other elements,
// Reach to the tail node and pass the tail node to Insert()

    }

    PrintList(head);
    printf("\n Len of list is %d", Length(head));
    head = reverse_list(head);
    printf("\n Reversed list - ");
    PrintList(head);
}
*/

