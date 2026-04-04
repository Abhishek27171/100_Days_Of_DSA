/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// queue for level order
struct Node *queue[MAX];
int front = 0, rear = -1;

// create new node
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

// build tree from level order input
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

// level order traversal
void levelOrder(struct Node *root)
{

    if (root == NULL)
        return;

    front = 0;
    rear = -1;

    enqueue(root);

    while (front <= rear)
    {

        struct Node *temp = dequeue();

        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(temp->left);

        if (temp->right != NULL)
            enqueue(temp->right);
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}