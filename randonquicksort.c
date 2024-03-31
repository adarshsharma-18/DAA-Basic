#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array using a random pivot
int partition(int arr[], int low, int high) {
    // Choose a random pivot index
    srand(time(NULL));
    int pivotIndex = low + rand() % (high - low + 1);

    // Swap the pivot element with the last element
    swap(&arr[pivotIndex], &arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    // Perform partitioning similar to the standard quicksort algorithm
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Place the pivot element at its correct position
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform randomized quicksort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array using random pivot
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays
        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting: ");
    printArray(arr, n);

    // Perform randomized quicksort
    randomizedQuickSort(arr, 0, n - 1);

    printf("Array after sorting: ");
    printArray(arr, n);

    return 0;
}
