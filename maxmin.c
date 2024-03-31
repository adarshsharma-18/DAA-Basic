#include <stdio.h>

// Function to find the maximum and minimum elements in an array
void findMaxMin(int arr[], int n, int* max, int* min) {
    if (n == 1) {
        *max = arr[0];
        *min = arr[0];
    } else if (n == 2) {
        if (arr[0] > arr[1]) {
            *max = arr[0];
            *min = arr[1];
        } else {
            *max = arr[1];
            *min = arr[0];
        }
    } else {
        int mid = n / 2;
        int max1, min1, max2, min2;
        findMaxMin(arr, mid, &max1, &min1);
        findMaxMin(arr + mid, n - mid, &max2, &min2);
        *max = (max1 > max2) ? max1 : max2;
        *min = (min1 < min2) ? min1 : min2;
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max, min;
    findMaxMin(arr, n, &max, &min);

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}
