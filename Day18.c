/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/
#include <stdio.h>

int main()
{
    int n, i, k;

    // Input size
    scanf("%d", &n);

    int arr[n], temp[n];

    // Input array
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input k
    scanf("%d", &k);

    // Handle k greater than n
    k = k % n;

    // Rotate array
    for (i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }

    // Print rotated array
    for (i = 0; i < n; i++)
    {
        printf("%d ", temp[i]);
    }

    return 0;
}