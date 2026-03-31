/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/
#include <stdio.h>
#include <stdlib.h> // for abs()

int main()
{
    int n, i, j;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input array
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min_sum = abs(arr[0] + arr[1]);
    int num1 = arr[0], num2 = arr[1];

    // Check all pairs
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];

            if (abs(sum) < min_sum)
            {
                min_sum = abs(sum);
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    // Output result
    printf("%d %d", num1, num2);

    return 0;
}