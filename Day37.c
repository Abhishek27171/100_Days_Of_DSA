/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/
#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// insert element
void insert(int x)
{
    if (size < MAX)
    {
        pq[size++] = x;
    }
}

// find index of smallest element
int findMinIndex()
{
    if (size == 0)
        return -1;

    int minIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (pq[i] < pq[minIndex])
        {
            minIndex = i;
        }
    }

    return minIndex;
}

// delete highest priority (smallest value)
void deleteElement()
{
    int minIndex = findMinIndex();

    if (minIndex == -1)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[minIndex]);

    // shift elements left
    for (int i = minIndex; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}

// peek highest priority
void peek()
{
    int minIndex = findMinIndex();

    if (minIndex == -1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", pq[minIndex]);
    }
}

int main()
{
    int N, value;
    char operation[10];

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", operation);

        if (operation[0] == 'i')
        { // insert
            scanf("%d", &value);
            insert(value);
        }
        else if (operation[0] == 'd')
        { // delete
            deleteElement();
        }
        else if (operation[0] == 'p')
        { // peek
            peek();
        }
    }

    return 0;
}