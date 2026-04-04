/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/
#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// heapify up
void heapifyUp(int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (heap[parent] > heap[index])
        {
            swap(&heap[parent], &heap[index]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

// heapify down
void heapifyDown(int index)
{
    while (2 * index + 1 < size)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index)
        {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        }
        else
        {
            break;
        }
    }
}

// insert element
void insert(int value)
{
    if (size == MAX)
        return;

    heap[size] = value;
    heapifyUp(size);
    size++;
}

// peek minimum
void peek()
{
    if (size == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

// extract minimum
void extractMin()
{
    if (size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

int main()
{
    int N, value;
    char op[20];

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", op);

        if (op[0] == 'i')
        { // insert
            scanf("%d", &value);
            insert(value);
        }
        else if (op[0] == 'p')
        { // peek
            peek();
        }
        else
        { // extractMin
            extractMin();
        }
    }

    return 0;
}