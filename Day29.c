/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// create list
struct Node *createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int i;

    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// rotate list right by k
struct Node *rotateRight(struct Node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *temp = head;
    int n = 1;

    // count nodes
    while (temp->next != NULL)
    {
        temp = temp->next;
        n++;
    }

    // connect last node to head (circular)
    temp->next = head;

    // handle large k
    k = k % n;

    // move to (n-k)th node
    int steps = n - k;
    while (steps--)
    {
        temp = temp->next;
    }

    // new head
    head = temp->next;

    // break circular link
    temp->next = NULL;

    return head;
}

// print list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, k;

    scanf("%d", &n);

    struct Node *head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}