#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <assert.h>
#include <string.h>

/* Write a Count() function that counts the number of times a given int occurs in a list. */

int count(struct Node *head, int num)
{
    struct Node * current = head;
    int count =0;

    while (current)
    {
        if (current->data == num)
            count++;
        current = current->next;
    }
    return count;
}

/* Write a GetNth() function that takes a linked list and an integer index and returns the data
   value stored in the node at that index position. Indexing starts at 0*/

int GetNth(struct Node *head, int index)
{
    struct Node* current = head;
    int i;

    for (i=0;current != NULL && i < index; current = current->next, i++ );

    assert(current);
    return current->data;

}

/* Write a function DeleteList() that takes a list, deallocates all of its memory and sets its
head pointer to NULL (the empty list). */

void DeleteList(struct Node** headref)
{
    struct Node* current = *headref;

    while(current)
    {
        current = current->next;
        free(*headref);
        *headref = current;
    }
    *headref = NULL;
}

/* Write a Pop() function that is the inverse of Push(). Pop() takes a non-empty list, deletes
 * the head node, and returns the head node's data.
 */

int Pop(struct Node ** headref)
{
    assert(*headref);
    int n;
    struct Node *tmp;

    tmp = *headref;
    n = tmp->data;
    *headref = (*headref)->next;

    free(tmp);
    return n;
}

/* Write a function InsertNth() which can insert a new node at
 * any index within a list.
 * Indexing starts at 0.
 */

void insertNth(struct Node **headref, int pos, int data)
{
    int i = 0;
    struct Node *prevNode;
    struct Node *newNode;

    newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (pos == 0)
    {
        newNode->next = *headref;
        *headref = newNode;
        return;
    }

    prevNode = *headref;

    while(i < pos-1 && prevNode != NULL)
    {
        prevNode = prevNode->next;
        i++;
    }
    assert(prevNode != NULL);

    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return;
}

/* Approach 2 */

struct Node* InsertNth_2(struct Node *head, struct Node *newNode, int pos)
{
    int i;
    /* Holds a pointer to the 'next' field that we have to link to the new node.
     By initializing it to &head we handle the case of insertion at the beginning. */
    struct Node** NodeatPos = &head;

    for (i=0; i < pos && (*NodeatPos != NULL); i++)
        NodeatPos = &((*NodeatPos)->next);

    newNode->next = (*NodeatPos);
    (*NodeatPos) = newNode;

    return head;
};

/* Write a SortedInsert() function which given a list that is sorted in increasing order, and a
 * single node, inserts the node into the correct sorted position in the list.
 */

 void SortedInsert(struct Node** headref, struct Node *newNode)
 {
     struct Node* current = *headref;

     if (current == NULL || newNode->data <= current->data)
     {
         newNode->next = *headref;
         *headref = newNode;
         return;
     }

     while(current->next != NULL && (newNode->data <= current->next->data))
     {
         current = current->next;
     }
             newNode->next = current->next;
             current->next = newNode;
 }

 void Print_recursive(struct Node *head)
 {
     printf("%d ", head->data);
     if (head->next == NULL)
        return;
     else
        Print_recursive(head->next);
 }

 void Print_reverse(struct Node *head)
 {
     if (head == NULL)
        return;
     else
     {
        Print_reverse(head->next);
        printf("%d ", head->data);
     }

 }

 void deleteNodeWithoutHead(struct Node** node)
 {
    struct Node* current = *node;

    *node = current->next;      // change the pointer to point to the next node and free the current node.
     free (current);

// OR copy contents of next node to the given node and free the next node.

     return;
 }
