/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed*/
#include <stdio.h>

int main()
{
    int p, q, i = 0, j = 0, k = 0;

    // Input size of first log
    scanf("%d", &p);
    int log1[p];

    // Input elements of first log
    for (i = 0; i < p; i++)
    {
        scanf("%d", &log1[i]);
    }

    // Input size of second log
    scanf("%d", &q);
    int log2[q];

    // Input elements of second log
    for (j = 0; j < q; j++)
    {
        scanf("%d", &log2[j]);
    }

    int merged[p + q];

    i = 0;
    j = 0;

    // Merge process
    while (i < p && j < q)
    {
        if (log1[i] < log2[j])
        {
            merged[k++] = log1[i++];
        }
        else
        {
            merged[k++] = log2[j++];
        }
    }

    // Copy remaining elements
    while (i < p)
    {
        merged[k++] = log1[i++];
    }

    while (j < q)
    {
        merged[k++] = log2[j++];
    }

    // Print merged log
    for (i = 0; i < p + q; i++)
    {
        printf("%d ", merged[i]);
    }

    return 0;
}