#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{

    int i, num, data;
    struct Node* head = NULL;

//    printf("\n Enter the number of elements you wish to have in linked list\n");
//    scanf("%d", &num);

//    printf("\nEnter the elements\n");
/*    for(i=0; i<num; i++)
    {
        scanf("%d", &data);
//        Insert(&head, data);
//        InsertDLL(&head, data);
        Insert_Cir_LL(&head, data);
    }
    printf("\n List = ");
*/

//    PrintList(head);
//    PrintListDLL(head);
 //   Print_circular_LL(head);
//    printf("\n Len of list is %d", Length(head));
/*    head = reverse_list(head);
 *    printf("\n Reversed list - ");
 *    PrintList(head);
 */

//    printf("\nNumber of times %d occurs in List is %d", 5, count(head, 5));

/*    int x;
    printf("\n Enter index whose element needs to be accessed");
    scanf("%d", &x);

    printf("\n Data at index %d is %d", x, GetNth(head, x));
*/

/*    DeleteList(&head);
    printf("\n List deleted");
*/
/*    printf("\nPopping element in LinkedList = %d\n",Pop(&head));
    PrintList(head);
    printf("\nPopping element in LinkedList = %d\n",Pop(&head));
    PrintList(head);
*/
/*    insertNth(&head, 1, 200);
    printf("\nList after inserting 200 at 1 = ");
    PrintList(head);
    insertNth(&head, 0, 100);
    printf("\nList after inserting 100 at 0 = ");
    PrintList(head);
*/
/*
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = 2020;
    newNode->next = NULL;

    head = InsertNth_2(head, newNode, 2);
    printf("\nList after inserting newNode at position 2 = ");
    PrintList(head);
*/

/*    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = 22;
    newNode->next = NULL;

    SortedInsert(&head, newNode);

    printf("\n New list is - ");
    PrintList(head);
*/
/*    printf("\nList = ");
    Print_recursive(head);
    printf("\n Reversed List = ");
    Print_reverse(head);
*/
//    deleteNodeWithoutHead(&(head->next));
//    printf("\n new list = ");
//    PrintList(head);

//    int x =  getNth_node_from_end(head, 6);
//    printf("6th node from end is %d", x);

/*    printf("\n Inserting 500 at 4");
    InsertNth_DLL(&head, 4, 500);
    printf("\n List = ");
    PrintListDLL(head);
*/


    Insert(&head, 5);
    Insert(&head, 5);
    Insert(&head, 20);
    Insert(&head, 20);

    PrintList(head);
    remove_duplicates(head);
    printf("\n list after removing duplicates: ");
    PrintList(head);

    return 0;
}
