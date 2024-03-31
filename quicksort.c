#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to display elements of an array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr1[] = {10, 7, 8, 9, 1, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Array before sorting: ");
    display(arr1, n1);
    quickSort(arr1, 0, n1 - 1);
    printf("Array after sorting: ");
    display(arr1, n1);

    int arr2[] = {5, 3, 8, 10, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("\nArray before sorting: ");
    display(arr2, n2);
    quickSort(arr2, 0, n2 - 1);
    printf("Array after sorting: ");
    display(arr2, n2);

    return 0;
}
