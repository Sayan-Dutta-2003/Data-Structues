#include <stdio.h>
#include <stdlib.h>

int *insertionSort(int *arr, int size)
{
    int key;
    int j;
    for(int i = 1; i < size; i++)
    {
        key = arr[i];
        for( j = i - 1; j >= 0; j--)
        {
            if(arr[j] > key)
            {
                arr[j + 1] = arr[j];
            }
            else{
                break;
            }
        }   
        arr[j + 1] = key;
    }

    return arr;
}

int main()
{
    
    int size;
    printf("Enter the size of array\n");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter %d elements in the array\n", size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Before Sorting:\n");

    for(int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }


    arr = insertionSort(arr, size);


    printf("\nAfter Sorting:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d\t", *(arr + i));
    }    

    return 0;
}
