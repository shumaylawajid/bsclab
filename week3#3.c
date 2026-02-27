#include <stdio.h>

void traverseArray(int *arr, int n);

int main()
{
    int n, i;

    
    do {
        printf("How many elements do you want to store (enter a positive number)? ");
        scanf("%d", &n);

        if (n <= 0) {
            printf("Error: Size must be greater than zero. Try again.\n\n");
        }
    } while (n <= 0);

    
    int arr[n]; 

    
    printf("\nPlease enter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nTraversing array using pointers:\n");
    traverseArray(arr, n);

    return 0;
}

void traverseArray(int *arr, int n)
{
    int i;
    int *ptr = arr;

    for (i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

