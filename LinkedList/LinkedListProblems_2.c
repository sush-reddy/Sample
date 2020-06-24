#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <assert.h>

/* Find nth node from the end of linked list */
// TODO
// Nth node from end of list = (N-n+1)th node from beginning, where N is length of list
// This is indexing starts from 1. if indexing starts from 0 then N-n

int getNth_node_from_end(struct Node* head, int n)
{
    int N = Length(head);
    int i=1;
    struct Node * current = head;

    while(i < (N-n+1))
    {
       current = current->next;
       i++;
    }

    return current->data;
}

// Recursive approach
void printNthFromLast(struct Node* head, int n)
{
    static int i = 0;
    if (head == NULL)
        return;
    printNthFromLast(head->next, n);
    if (++i == n)
        printf("%d", head->data);
}

// Two pointers approach. Without knowing the length of the list.
void printNthFromLast_2(struct Node* head, int n)
{
    struct Node* first = head;
    struct Node* second = head;
    int i;

    for(i = 0; i<n; i++)
        first = first->next;

    while(first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    printf("element = %d", second->data);
}


void deleteNthNodeFromLast(struct Node **headref, int n)
{
    struct Node* first = *headref;
    struct Node* second = *headref;
    struct Node* temp;
    int i;


    for(i = 0; i<n; i++) {
        if (!first) {
            printf("\n Invalid position");
            return;
        }
        first = first->next;
    }

    if (!first)
    {
        // Node to be deleted is head.
        temp = *headref;
        *headref = (*headref)->next;
        free(temp);
        return;
    }

    while(first->next != NULL)
    {
        first = first->next;
        second = second->next;
    }

    temp = second->next;    // Node to be deleted is next of second ptr.
    second->next = second->next->next;

    free(temp);
}

/* Write a program to find the node at which the intersection of two singly linked lists begins. */
// Returns the node at which intersection begins.
// This is brute force. Time complexity O(m*n)

struct Node* Find_intersection(struct Node* headptr1, struct Node* headptr2)
{
    int i,j;
    struct Node* L1current;
    struct Node* L2current;

    L1current = headptr1;
    for(i=0;L1current != NULL; i++)
    {
        L2current = headptr2;
        for(j=0; L2current != NULL; j++)
        {
            if (L1current == L2current)
            {
                return L1current;
            }
            L2current = L2current->next;
        }
        L1current = L1current->next;
    }
    printf("\n Intersection not found");
    return NULL;

}

//finds the intersection of the given linked lists version3
//The best approach to solve
/* Approach: Find larger list traverse till the difference between Len1 and Len2.
 * After that, in a single loop traverse both the Lists while checking if any node is common.
 * Return the node if common node is found.
 */

struct Node* Find_intersection_2(struct Node *A, struct Node *B) {
    int m = Length(A);
    int n = Length(B);
    int d = n - m;
    if(m > n) {
        struct Node* temp = A;
        A = B;
        B = temp;
        d = m - n;
    }
    int i;
    for(i=0;i<d;i++) {
        B = B->next;
    }
    while(A != NULL && B != NULL) {
        if(A == B) {
            return A;
        }
        A = A->next;
        B = B->next;
    }
    return NULL;
}

/* Detect loop in singly Linked List
 * One method is to use a hash table and traverse the LL putting the address of each node in hash table.
 * If any address is dubplicate, it means there is a loop.
 *
 *
 * In another method implemented here, uses 2 pointer. Slow ptr and fast ptr
 * Slow ptr moves 1 node at a time, Fast ptr moves 2 nodes at a time.
 * If both pointers meet, it means there is a loop.
 *
 */

int Detect_loop_in_LL(struct Node* head)
{
    struct Node* slow = head;
    struct Node* fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return 1;
    }
    return 0;
}

/*
 * Remove a loop in a singly Linked list
 * The above algorithm can be used to remove the loop.
 * Once loop is detected, the node at which slow and fast ptrs meet is a node within the loop.
 * Save this node as loop node.
 * Have a ptr to traverse the linked list from head.
 * Another ptr to traverse the loop from the loop node.
 * Keep checking if the pointer traversing the loop node reaches the list node, if it does, then the pointer to last node forming the loop is found.
 * Assign its next to NULL to delete the loop.
 */


void remove_loop_LL(struct Node* loop_node, struct Node* head)
{
    struct Node* looper;
    struct Node* listptr;

    listptr = head;
    while(1)
    {
        looper = loop_node;
        while(looper->next != loop_node && looper->next != listptr)
            looper = looper->next;

        if(looper->next == listptr)
            break;
        listptr = listptr->next;
    }
    looper->next = NULL;
}


/* Remove duplicates from a sorted LinkedList */

void remove_duplicates(struct Node* head)
{
    if (head == NULL)
        return;

    struct Node* ptr = head;
    struct Node* tmp;

    while(ptr)
    {
        if (ptr->next && ptr->next->data == ptr->data)
        {
            tmp = ptr->next;
            ptr->next = ptr->next->next;
            free(tmp);
        }
        else
            ptr = ptr->next;
    }
}
