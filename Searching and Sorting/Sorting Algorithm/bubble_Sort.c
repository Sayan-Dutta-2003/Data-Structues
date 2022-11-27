#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n ; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

void bubbleSort(int *arr, int n)
{
    int temp;
    int isSorted;
    for (int i = 0; i < n - 1; i++) // For number of Pass
    {
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each Pass
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
            
        }
        if (isSorted)
        {
            return;
        } 
    }
    
}


int main()
{
    
    int *arr, size;
    printf("Enter the size of array\n");
    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int) * size);
    printf("Enter the elements\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nPrinting the array before sorting\n");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("\nPrinting the array after sorting\n");
    printArray(arr, size);
    return 0;
}
