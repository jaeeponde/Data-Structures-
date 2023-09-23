#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
          exit(0);
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

int main()
{
    int arr[100000], arr1[100000];
    int n = 100, i, comparisonCount, swapCount, t;
    int comparisonCount1, swapCount1, elm;
    double cc, sc;
    double cc1, sc1;
    double xc, yc;
    double xc1, yc1;

    srand(time(NULL));
    
    for (n = 10000; n <= 100000; n = n+10000){
      cc = 0.0, sc = 0.0; cc1 = 0.0, sc1 = 0.0;
      xc = 0.0, yc = 0.0; xc1 = 0.0, yc1 = 0.0;

      for (t = 0; t < 100; t++){
        for (i = 0; i < n; i++){
	    arr[i] = rand()%10000; arr1[i] = arr[i];
        }

        for(i = 0; i < n; i++){
            heapInsert(arr, i, arr[i], &comparisonCount, &swapCount);
	    cc += (double) comparisonCount;
	    sc += (double) swapCount;
        }

        for(i = n; i > 0; i--){
            elm = heapDelete(arr, i, &comparisonCount1, &swapCount1);
            arr[i-1] = elm;
	    cc1 += (double) comparisonCount1;
	    sc1 += (double) swapCount1;
        }

        for (int i = n/2 - 1; i >= 0; i--){
            heapify(arr1, n, i, &comparisonCount, &swapCount);
            xc += (double) comparisonCount;
            yc += (double) swapCount;
        }

        for(i = n; i > 0; i--){
            elm = heapDelete(arr1, i, &comparisonCount1, &swapCount1);
            arr1[i-1] = elm;
	    xc1 += (double) comparisonCount1;
	    yc1 += (double) swapCount1;
        }

      }
      checkIfSorted(arr, n);
      checkIfSorted(arr1, n);

      printf("n = %6d, %lf %lf\n", n, cc/(n*100.0), sc/(n*100.0));
      printf("            %lf %lf\n", cc1/(n*((log(n)/log(2)))*100.0), sc1/(n*((log(n)/log(2)))*100.0));
      printf("n = %6d, %lf %lf\n", n, xc/(n*100.0), yc/(n*100.0));
      printf("            %lf %lf\n", xc1/(n*((log(n)/log(2)))*100.0), yc1/(n*((log(n)/log(2)))*100.0));
      printf("----\n");
     }
}