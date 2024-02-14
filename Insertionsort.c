#include <stdio.h>

void insertionsort(int a[], int n)
{
    int keyval;

    for (int i = 0; i < n; i++)
    {
        keyval = a[i];
        int j = i - 1;
        while (keyval < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            a[j] = keyval;
            j--;
        }
        
    }
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {0,
        4,
        2,
        7,
        4,
        9,
        1,
        
    };
    int n = sizeof(A) / sizeof(A[0]);
    printf("Array before Insertion Sort\n");
    display(A, n);
    insertionsort(A, n);
    printf("Array after Insertion Sort\n");
    display(A, n);
    return 0;
}