#include <stdio.h>

#define SIZE 8

int main()
{
    int arr[SIZE];
    int i, index;

    /* Example initialization */
    for (i = 0; i < SIZE; i++)
    {
        arr[i] = (i + 1) * 2;
    }

    printf("Enter index (0 to %d): ", SIZE - 1);
    scanf("%d", &index);

    if (index >= 0 && index < SIZE)
    {
        printf("Element at index %d is: %d\n", index, *(arr + index));
    }
    else
    {
        printf("Invalid index!\n");
    }

    return 0;
}

