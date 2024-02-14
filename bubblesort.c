#include <stdio.h>

void bubblesort(int a[], int n)
{
    int keyval;

    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j<n-i-1; j++)
        {
            if (a[j]<a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }

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
    printf("Array before Bubble Sort\n");
    display(A, n);
    bubblesort(A, n);
    printf("Array after Bubble Sort\n");
    display(A, n);
    
    return 0;
}