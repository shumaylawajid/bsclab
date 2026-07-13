#include <stdio.h>

#define N 10

void sel_sort(int a[], int n) {
    /* Fixed: Added commas, fixed 'loc_min' declaration */
    int pass, loc_min, i, temp;

    for (pass = 1; pass <= n - 1; pass++) {
        loc_min = pass - 1;
        /* Fixed: 'pas' changed to 'pass' */
        for (i = pass; i <= n - 1; i++) {
            if (a[i] < a[loc_min])
                loc_min = i;
        }
        if (loc_min != (pass - 1)) {
            temp = a[pass - 1];
            a[pass - 1] = a[loc_min];
            a[loc_min] = temp;
        }
    }
}

int main() { /* Pre-C90 prefers 'int main' over 'void main' */
    int a[N], i;

    printf("\nEnter %d integer values for sorting:\n", N);
    /* Fixed: Changed comma to semicolon in for loop */
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nArray before sorting:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]); /* Added space for readability */
    }

    sel_sort(a, N);

    printf("\n\nArray after sorting:\n");
    for (i = 0; i < N; i++) {
        /* Fixed: Added missing semicolon */
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

