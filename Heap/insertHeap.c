#include <stdio.h>

#define MAX 1000 // Max size of Heap

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}

// Function to heapify ith node in a Heap of size n following a Bottom-up approach

void heapify(int arr[], int n, int i)
{
    // Find parent
    int parent = (i - 1) / 2;

    if (arr[parent] > 0)
    {
        // For Max-Heap
        // If current node is greater than its parent
        // Swap both of them and call heapify again for the parent
        if (arr[i] > arr[parent])
        {
            swap(&arr[i], &arr[parent]);

            // Recursively heapify the parent node
            heapify(arr, n, parent);
        }
    }
}

// Function to insert a new node to the Heap
void insertNode(int arr[], int n, int Key)
{
    // Increase the size of Heap by 1
    n = n + 1;

    // Insert the element at end of Heap
    arr[n - 1] = Key;

    // Heapify the new node following a Bottom-up approach
    heapify(arr, n, n - 1);
}

// A utility function to print array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int arr[MAX] = {10, 5, 3, 2, 4};

    int n = 5;

    int key = 15;

    insertNode(arr, n, key);

    printArray(arr, n);

    return 0;
}
