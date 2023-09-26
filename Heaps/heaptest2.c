#include <stdio.h>

void swap(int *xp, int *yp)
{   
    int temp;
    temp = *xp; *xp = *yp; *yp = temp;
}

void printArray(int arr[], int size)
{   
    int i; 
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void checkIfSorted(int arr[], int size){

    int i;
    for (i = 0; i < size-1; i++)
       if (arr[i] > arr[i+1]){
          printf("Error in sorting\n");
       }
}

void heapInsert(int arr[], int n, int elm, int *c1, int *c2)
{
     int i, parent; 

     *c1 = 0; *c2 = 0;
     arr[n] = elm;
     i = n;

     if (i == 0) return;
   
     while (i != 0){
         parent = (i-1)/2;
         (*c1)++;
         if (arr[parent] < arr[i]){ 
           swap(&arr[i], &arr[parent]);
           (*c2)++;
         }
         else break;
         i = parent;
    }
}

void heapify(int arr[], int n, int i, int *c1, int *c2){

    int largest, left, right, j;

    *c1 = 0; *c2 = 0;

    while(1){
      left = 2*i+1; right = 2*i+2; largest = i;
      if (left < n && arr[left] > arr[largest]){ largest = left; (*c1)++; }
      if (right < n && arr[right] > arr[largest]) { largest = right; (*c1)++; }
      if (largest != i){
        swap(&arr[i], &arr[largest]);
        (*c2)++;
        i = largest;
      }
      else break;
    }
}

int heapDelete(int arr[], int n, int *c1, int *c2)
{
     int i, left, right, largest, val, flag = 1;

     *c1 = 0; *c2 = 0;
     if (n == 0) return -9999;
     val = arr[0];
     arr[0] = arr[n-1];
     i = 0;

     while (flag == 1){
        flag = 0; largest = i;
        left = 2*i+1; right = 2*i+2;
         (*c1)++;
        if (left <= n-1 && arr[left] > arr[largest]){
                largest = left; flag = 1;
        }
         (*c1)++;
        if (right <= n-1 && arr[right] > arr[largest]){
                largest = right; flag = 1;
        }
        if (flag == 1){
                 (*c2)++;
                 swap(&arr[i], &arr[largest]); i = largest;
        }
     }
     return val;
}

int main(){
    int arr[] = {110, 37, 73, 92, 19, 53, 77, 81, 99, 3}, arr1[10];
    int n = 10, i, comparisonCount, swapCount, t;
    int comparisonCount1, swapCount1, elm;
    double cc, sc;
    double cc1, sc1;
    double xc, yc;
    double xc1, yc1;

    
      cc = 0.0, sc = 0.0; cc1 = 0.0, sc1 = 0.0;
      xc = 0.0, yc = 0.0; xc1 = 0.0, yc1 = 0.0;

        for (i = 0; i < n; i++) arr1[i] = arr[i];

        printf("Initial data: ");
	printArray(arr, n);

        for(i = 0; i < n; i++){
            heapInsert(arr, i, arr[i], &comparisonCount, &swapCount);
	    cc += (double) comparisonCount;
	    sc += (double) swapCount;
        }

        printf("First Heap: ");
	printArray(arr, n);

        for(i = n; i > 0; i--){
            elm = heapDelete(arr, i, &comparisonCount1, &swapCount1);
            arr[i-1] = elm;
	    cc1 += (double) comparisonCount1;
	    sc1 += (double) swapCount1;
        }

        printf("First Sorted: ");
	printArray(arr, n);
        checkIfSorted(arr, n);

        printf("n = %6d, %.0lf %.0lf\n", n, cc, sc);
        printf("            %.0lf %.0lf\n", cc1, sc1);

        for (int i = n/2 - 1; i >= 0; i--){
            heapify(arr1, n, i, &comparisonCount, &swapCount);
            xc += (double) comparisonCount;
            yc += (double) swapCount;
        }

        printf("Second Heap: ");
	printArray(arr1, n);

        for(i = n; i > 0; i--){
            elm = heapDelete(arr1, i, &comparisonCount1, &swapCount1);
            arr1[i-1] = elm;
	    xc1 += (double) comparisonCount1;
	    yc1 += (double) swapCount1;
        }

        printf("Second Sorted: ");
	printArray(arr1, n);
        checkIfSorted(arr1, n);

        printf("n = %6d, %.0lf %.0lf\n", n, xc, yc);
        printf("            %.0lf %.0lf\n", xc1, yc1);
}