#include <stdio.h>

int main() {
    int arr[100], n, i, count = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    printf("Number of even elements: %d", count);
    return 0;
}

