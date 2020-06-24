#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

struct DLLNode {
    int data;
    struct DLLNode *prev;
    struct DLLNode *next;
};

void Insert(struct Node** headref, int data);
void PrintList(struct Node* headcopy);
int Length(struct Node* headcopy);
void InsertAtEnd(struct Node** head, int data);
struct Node * Reverse_list_recurse(struct Node *head);
struct Node * reverse_list(struct Node *head);
struct Node* deleteNthNode(struct Node* head, int position);
int count(struct Node *head, int num);
int GetNth(struct Node *head, int index);
void DeleteList(struct Node** head);
int Pop(struct Node ** headref);
void insertNth(struct Node **headref, int pos, int data);
struct Node * InsertNth_2(struct Node *head, struct Node *newNode, int pos);
void SortedInsert(struct Node** headref, struct Node *newNode);
void Print_reverse(struct Node *head);
void Print_recursive(struct Node *head);
void deleteNodeWithoutHead(struct Node** node);
int getNth_node_from_end(struct Node* head, int n);
void printNthFromLast(struct Node* head, int n);
void printNthFromLast_2(struct Node* head, int n);
void deleteNthNodeFromLast(struct Node **headref, int n);

void PrintListDLL(struct DLLNode* headcopy);
void InsertDLL(struct DLLNode** head, int data);
void InsertNth_DLL(struct DLLNode** head, int pos, int data);
void Insert_Cir_LL(struct Node** head, int data);
void Print_circular_LL(struct Node *headcopy);
int Detect_loop_in_LL(struct Node* head);
void remove_duplicates(struct Node* head);
