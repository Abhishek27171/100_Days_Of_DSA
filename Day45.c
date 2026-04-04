/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Queue for tree construction
struct Node *queue[MAX];
int front = 0, rear = -1;

// create node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// enqueue
void enqueue(struct Node *node)
{
    queue[++rear] = node;
}

// dequeue
struct Node *dequeue()
{
    return queue[front++];
}

// build tree from level order
struct Node *buildTree(int arr[], int n)
{

    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node *root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n)
    {

        struct Node *current = dequeue();

        // left child
        if (i < n && arr[i] != -1)
        {
            current->left = createNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        // right child
        if (i < n && arr[i] != -1)
        {
            current->right = createNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    return root;
}

// function to find height
int height(struct Node *root)
{

    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main()
{

    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *root = buildTree(arr, n);

    printf("%d", height(root));

    return 0;
}