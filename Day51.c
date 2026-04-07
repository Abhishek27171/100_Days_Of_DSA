/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/
#include <stdio.h>
#include <stdlib.h>

// Structure of BST node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert node in BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to find LCA
struct Node *findLCA(struct Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    // If both nodes are smaller, go left
    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    // If both nodes are greater, go right
    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    // Otherwise this is LCA
    return root;
}

int main()
{
    int n, i, val, n1, n2;
    struct Node *root = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input BST values
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input two nodes
    scanf("%d %d", &n1, &n2);

    // Find LCA
    struct Node *lca = findLCA(root, n1, n2);

    // Output result
    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}