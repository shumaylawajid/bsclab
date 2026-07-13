#include <stdio.h>

#define SIZE 50   /* maximum size for arrays */

void merge(int a[], int m, int b[], int n, int r[]);

int main(void)
{
    int a1[SIZE], a2[SIZE], r[SIZE];
    int m, n;
    int i;

    /* Input for first array */
    printf("Enter size of first array: ");
    scanf("%d", &m);
    printf("Enter %d elements (sorted):\n", m);
    for (i = 0; i < m; i++)
        scanf("%d", &a1[i]);

    /* Input for second array */
    printf("Enter size of second array: ");
    scanf("%d", &n);
    printf("Enter %d elements (sorted):\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a2[i]);

    /* Merge arrays */
    merge(a1, m, a2, n, r);

    /* Display merged array */
    printf("Merged array:\n");
    for (i = 0; i < m + n; i++)
        printf("%d ", r[i]);
    printf("\n");

    return 0;
}

void merge(int a[], int m, int b[], int n, int r[])
{
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            r[k] = a[i];
            k++;
            i++;
        }
        else
        {
            r[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < m)
    {
        r[k] = a[i];
        k++;
        i++;
    }

    while (j < n)
    {
        r[k] = b[j];
        k++;
        j++;
    }
}

