#include <stdio.h>

//recursive way to perform binsearch
//lots of overhead as function keeps calling itself

int bs(int arr[], int l, int r, int x){
    if (r >= l){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return bs(arr, l, mid - 1, x);
        return bs(arr, mid + 1, r, x);
    }
    return -1;
}
int main(void)
{
    int n = 5, x = 11, result;
    int arr[] = {2, 3, 4, 11, 40};
    result = bs(arr, 0, n - 1, x);
    if (result == -1) printf("Element not present\n");
    else printf("Element present at index %d\n", result);
}
