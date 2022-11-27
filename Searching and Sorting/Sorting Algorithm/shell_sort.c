#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n ; i++)
    {
        printf("%d ", arr[i]);
    }  
}

void swap(int *arr1, int *arr2)
{
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

void shellSort(int *arr, int size)
{
    int gap;
    for(gap = size/2; gap >= 1; gap = gap/2)
    {
        for(int j = gap; j < size; j++)
        {
            for(int i = j - gap; i >= 0; i - gap)
            {
                if(arr[i + gap] < arr[i])
                {
                    swap(&arr[i + gap], &arr[i]);
                }
                else
                {
                    break;
                }
            }
        }
    }
}

int main(){
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

    shellSort(arr, size);

    printf("\nPrinting the array after sorting\n");
    printArray(arr, size);
    return 0;
}
