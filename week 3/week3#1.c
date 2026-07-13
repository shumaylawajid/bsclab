#include <stdio.h>

/* Define the maximum capacity of the array */
#define SIZE 25

/* Function Prototypes */
void createArray(int arr[], int *n);
void displayArray(int arr[], int n);
void deleteAtBeginning(int arr[], int *n);
void deleteAtMiddle(int arr[], int *n);
void deleteAtEnd(int arr[], int *n);
void insertAtPosition(int arr[], int *n, int pos, int value);

int main() {
    int arr[SIZE];
    int n = 0;
    int choice, pos, value;

    /* Requirement (a): Initial creation of the array */
    createArray(arr, &n);

    while (1) {
        printf("\n=========================================\n");
        printf("  CURRENT ARRAY: ");
        displayArray(arr, n);
        printf("=========================================\n");
        printf("1. Insert at specific location\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from Middle\n");
        printf("4. Delete from End\n");
        printf("5. Display Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); /* Clear input buffer */
            continue;
        }

        if (choice == 6) break;

        switch (choice) {
            case 1: /* Requirement (c) */
                printf("Enter index (0 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtPosition(arr, &n, pos, value);
                break;

            case 2: /* Requirement (b) */
                deleteAtBeginning(arr, &n);
                break;

            case 3: /* Requirement (b) */
                deleteAtMiddle(arr, &n);
                break;

            case 4: /* Requirement (b) */
                deleteAtEnd(arr, &n);
                break;

            case 5: /* Requirement (d) */
                displayArray(arr, n);
                break;

            default:
                printf("Invalid choice! Please select 1-6.\n");
        }
    }

    return 0;
}

/* --- FUNCTION DEFINITIONS --- */

/* a. Create an array and insert elements of your choice */
void createArray(int arr[], int *n) {
    int i, count;
    printf("How many elements do you want to start with? (Max %d): ", SIZE);
    scanf("%d", &count);
    
    if (count > SIZE) count = SIZE;
    *n = count;

    for (i = 0; i < *n; i++) {
        printf("Enter element for index %d: ", i);
        scanf("%d", &arr[i]);
    }
}

/* d. Display all the elements */
void displayArray(int arr[], int n) {
    int i;
    if (n == 0) {
        printf("[ Array is Empty ]\n");
        return;
    }
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* b. Delete at Beginning */
void deleteAtBeginning(int arr[], int *n) {
    int i;
    if (*n <= 0) {
        printf("Error: Array underflow!\n");
        return;
    }
    printf("Deleted %d from the beginning.\n", arr[0]);
    for (i = 1; i < *n; i++) {
        arr[i - 1] = arr[i];
    }
    (*n)--;
}

/* b. Delete at Middle (Standard Middle Logic) */
void deleteAtMiddle(int arr[], int *n) {
    int i, mid;
    if (*n <= 0) {
        printf("Error: Array underflow!\n");
        return;
    }
    /* For 4 elements, (4-1)/2 = 1. Index 1 is the lower middle. */
    mid = (*n - 1) / 2;
    printf("Deleted %d from middle (Index %d).\n", arr[mid], mid);
    for (i = mid + 1; i < *n; i++) {
        arr[i - 1] = arr[i];
    }
    (*n)--;
}

/* b. Delete at End */
void deleteAtEnd(int arr[], int *n) {
    if (*n <= 0) {
        printf("Error: Array underflow!\n");
        return;
    }
    printf("Deleted %d from the end.\n", arr[*n - 1]);
    (*n)--;
}

/* c. Insert the element at particular locations */
void insertAtPosition(int arr[], int *n, int pos, int value) {
    int i;
    if (*n >= SIZE) {
        printf("Error: Array overflow (Capacity %d reached)!\n", SIZE);
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Error: Invalid position %d!\n", pos);
        return;
    }
    /* Shift elements to the right to make room */
    for (i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
    printf("Successfully inserted %d at index %d.\n", value, pos);
}

