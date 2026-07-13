#include <stdio.h>
#include <string.h>

/* Bubble Sort function for characters */
void bubble_sort(char arr[], int n) {
    int i, j;
    char temp;

    /* Outer loop for number of passes */
    for (i = 0; i < n - 1; i++) {
        /* Inner loop for comparisons */
        for (j = 0; j < n - i - 1; j++) {
            /* Compare adjacent characters */
            if (arr[j] > arr[j + 1]) {
                /* Swap if they are in the wrong order */
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    /* Declarations must be at the top for Pre-C90 */
    char str[100];
    int len;

    printf("Enter a string to sort: ");
    /* Using scanf %s reads until the first space */
    scanf("%s", str);

    len = strlen(str);

    printf("Original string: %s\n", str);

    bubble_sort(str, len);

    printf("Sorted string:   %s\n", str);

    return 0;
}

