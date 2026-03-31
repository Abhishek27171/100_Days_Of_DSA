/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
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

// find length
int length(struct Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

// find intersection
int findIntersection(struct Node *head1, struct Node *head2)
{
    int len1 = length(head1);
    int len2 = length(head2);

    int diff;

    if (len1 > len2)
    {
        diff = len1 - len2;
        while (diff--)
            head1 = head1->next;
    }
    else
    {
        diff = len2 - len1;
        while (diff--)
            head2 = head2->next;
    }

    // traverse together
    while (head1 != NULL && head2 != NULL)
    {
        if (head1 == head2)
            return head1->data;

        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}

int main()
{
    int n, m;

    scanf("%d", &n);
    struct Node *list1 = createList(n);

    scanf("%d", &m);
    struct Node *list2 = createList(m);

    int result = findIntersection(list1, list2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}