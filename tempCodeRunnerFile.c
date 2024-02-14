#include <stdio.h>
//
void insertionsort(int a[], int n)
{
    int keyval;

    for (int i = 0; i < n; i++)
    {
        keyval = a[i];