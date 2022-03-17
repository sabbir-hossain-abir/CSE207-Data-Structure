#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{

    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    printf("\nAfter insertion sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n, i, val, find;
    int *arr = (int *)malloc(sizeof(int) * n);

    printf("Enter the array size\n");
    scanf("%d", &n);
    printf("Enter the array element\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Before insertion sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // insertion
    insertionSort(arr, n);

    free(arr);

    return 0;
}
