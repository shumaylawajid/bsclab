#include <stdio.h>
#include <string.h>

/* Function to swap two characters */
void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* Partition function: places the pivot in the correct position */
int partition(char arr[], int low, int high) {
    char pivot;
    int i, j;

    pivot = arr[high]; /* Picking the last character as pivot */
    i = (low - 1);    /* Index of smaller element */

    for (j = low; j <= high - 1; j++) {
        /* If current character is smaller than or equal to pivot */
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* Recursive Quick Sort function */
void quick_sort(char arr[], int low, int high) {
    int pi; /* Partitioning index */

    if (low < high) {
        pi = partition(arr, low, high);

        /* Separately sort elements before and after partition */
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    /* All declarations at the top for Pre-C90 */
    char str[100];
    int n;

    printf("Enter a string (no spaces): ");
    scanf("%s", str);

    n = strlen(str);

    printf("Before sorting: %s\n", str);

    /* Perform Quick Sort */
    quick_sort(str, 0, n - 1);

    printf("After sorting:  %s\n", str);

    return 0;
}

