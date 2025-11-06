#include <stdio.h>

/**
 * @brief Performs Bubble Sort on an integer array in ascending order.
 * * Bubble Sort repeatedly steps through the list, compares adjacent elements,
 * and swaps them if they are in the wrong order. The largest element "bubbles up"
 * to its correct position at the end of each pass.
 *
 * @param arr The array of integers to be sorted.
 * @param n The number of elements in the array.
 */
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // Outer loop for the number of passes
    for (i = 0; i < n - 1; i++) {
        // Inner loop for comparison and swapping in the current pass
        // The last i elements are already in place (sorted), so we only check up to n-1-i
        for (j = 0; j < n - 1 - i; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1] if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief Utility function to print the elements of an array.
 * * @param arr The array of integers to be printed.
 * @param n The number of elements in the array.
 */
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

/**
 * @brief Main function to initialize the array and demonstrate sorting.
 */
int main() {
    // 1. Initialize the array with the given elements: 1, 9, 2, 5
    int data[] = {1, 9, 2, 5};
    // 2. Calculate the number of elements in the array
    int n = sizeof(data) / sizeof(data[0]);

    printf("Original array elements: ");
    printArray(data, n); // Output: 1, 9, 2, 5

    // 3. Call the sorting function
    bubbleSort(data, n);

    // 4. Print the sorted array
    printf("Array elements in ascending order: ");
    printArray(data, n); // Output: 1, 2, 5, 9

    return 0;
}
