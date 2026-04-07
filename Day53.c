/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7*/
#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Queue node (stores tree node + horizontal distance)
struct QNode
{
    struct Node *treeNode;
    int hd;
};

// Create new tree node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order array
struct Node *buildTree(int arr[], int n, int i)
{
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node *root = newNode(arr[i]);

    root->left = buildTree(arr, n, 2 * i + 1);
    root->right = buildTree(arr, n, 2 * i + 2);

    return root;
}

// Vertical order traversal
void verticalOrder(struct Node *root)
{
    if (root == NULL)
        return;

    struct QNode queue[100];
    int front = 0, rear = 0;

    int hd_nodes[200][100]; // store nodes for each HD
    int count[200] = {0};

    int min_hd = 0, max_hd = 0;

    queue[rear++] = (struct QNode){root, 0};

    while (front < rear)
    {
        struct QNode temp = queue[front++];
        struct Node *curr = temp.treeNode;
        int hd = temp.hd + 100; // shift index to avoid negative

        hd_nodes[hd][count[hd]++] = curr->data;

        if (temp.hd < min_hd)
            min_hd = temp.hd;
        if (temp.hd > max_hd)
            max_hd = temp.hd;

        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, temp.hd - 1};

        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, temp.hd + 1};
    }

    // Print vertical order
    for (int i = min_hd; i <= max_hd; i++)
    {
        int idx = i + 100;
        for (int j = 0; j < count[idx]; j++)
            printf("%d ", hd_nodes[idx][j]);
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *root = buildTree(arr, n, 0);

    verticalOrder(root);

    return 0;
}