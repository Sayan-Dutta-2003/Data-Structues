#include <stdio.h>
#include <malloc.h>

void Swap(int *arr1, int *arr2)
{
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

void selectionSort(int *arr, int size)
{
    int min, minIndex;
    for(int i = 0; i < size; i++)
    {
        min = arr[i];
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        if(arr[i] > min)
        {
            Swap(&arr[i], &arr[minIndex]);
        }
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }

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

    printf("Elemets:\t");
    printArray(arr, size);
    printf("\n");
    selectionSort(arr, size);

    printArray(arr, size);

    return 0;


}
