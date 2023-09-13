#include <stdio.h>

//this binary search only works for a sorted list 

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;//every int function has to return something, so if x is not found it returns -1 
}
int main(void)
{
    int n = 5, x = 10, result;
    int arr[] = {2, 3, 4, 15, 40};
    result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Element not present\n");
    else
        printf("Element present at index %d\n", result);
}
