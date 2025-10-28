#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));  // ✅ Allocate memory first
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i; // sorted array
    }

    key = -1; // element not present → worst case

    clock_t start = clock();

    // Run multiple times to get an average
    for (int i = 0; i < 1000; i++) {
        linearSearch(arr, n, key);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000;

    printf("Time taken for linear search with %d elements: %f seconds\n",
           n, time_taken);

    free(arr);
    return 0;  // ✅ Fixed missing semicolon
}
