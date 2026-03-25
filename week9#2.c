#include <stdio.h>

/* Linear Search: Non-Recursive */
int linear_search(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

/* Linear Search: Recursive */
int linear_search_rec(int arr[], int n, int key, int index) {
    if (index >= n) return -1;
    if (arr[index] == key) return index;
    return linear_search_rec(arr, n, key, index + 1);
}

/* Binary Search: Non-Recursive */
int binary_search(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

/* Binary Search: Recursive */
int binary_search_rec(int arr[], int low, int high, int key) {
    int mid;
    if (low > high) return -1;
    mid = (low + high) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] < key) return binary_search_rec(arr, mid + 1, high, key);
    return binary_search_rec(arr, low, mid - 1, key);
}

int main() {
    /* Fixed: Added array size and kept all declarations at the top */
    int arr[100]; 
    int n, key, i, choice, result;

    printf("Enter number of elements (max 100): ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter %d integers (Sorted if using Binary Search):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key value to search: ");
    scanf("%d", &key);

    printf("\nChoose Search Method:\n");
    printf("1. Linear Search (Non-Recursive)\n");
    printf("2. Linear Search (Recursive)\n");
    printf("3. Binary Search (Non-Recursive)\n");
    printf("4. Binary Search (Recursive)\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    result = -1; /* Default value */

    switch(choice) {
        case 1: 
            result = linear_search(arr, n, key); 
            break;
        case 2: 
            result = linear_search_rec(arr, n, key, 0); 
            break;
        case 3: 
            result = binary_search(arr, n, key); 
            break;
        case 4: 
            result = binary_search_rec(arr, 0, n - 1, key); 
            break;
        default: 
            printf("Invalid choice!\n"); 
            return 1;
    }

    if (result != -1) {
        printf("\nSuccess: Key %d found at index %d.\n", key, result);
    } else {
        printf("\nFailure: Key %d not found in the list.\n", key);
    }

    return 0;
}

