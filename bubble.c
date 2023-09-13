#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp;
    temp = *xp; *xp = *yp; *yp = temp;
}
//function for swapping 2 variables 

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
//to print the sorted array 

void bubbleSort(int arr[], int n)
{
    int i, j, flag, comparisonCnt = 0, swapCnt = 0;

    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) //the upper limit of the array keeps reducing as the list keeps getting sorted by 1 element
         {
	    comparisonCnt++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
		swapCnt++;
            }//keeps pushing the greatest number to the left 
        }
        if (flag == 0)
            break;
    }
printf("No. of comparisons %d, no. of swaps %d\n", comparisonCnt, swapCnt);
}

int main()
{
    int n = 7;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    //int arr[] = {34, 64, 25, 12, 22, 11, 90};

    printf("Initial array: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
