#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void Preorder(struct Node* root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(struct Node* root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void Postorder(struct Node* root)
{
    if (root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

struct Node* GetNewNode(int data)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Insert for a BST
struct Node* Insert(struct Node* root, int data)
{
    struct Node* newNode = GetNewNode(data);

    if (root == NULL)
    {
        root = newNode;
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
};

int main() {

    struct Node* root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 25);
    root = Insert(root, 12);

    printf("\n Preorder traversal - ");
    Preorder(root);
    printf("\n Inorder traversal - ");
    Inorder(root);
    printf("\n Postorder traversal - ");
    Postorder(root);

    return 0;
}

