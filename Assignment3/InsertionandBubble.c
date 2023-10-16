#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertionsort(int arr[], int n) {
    int i, elm, j; //elm represents element to insert 
    for (i = 1; i < n; i++) { //i chooses element to insert one by one 
        elm = arr[i];
        j = i - 1; //j traverses sorted part of the array 
        while (j >= 0 && arr[j] > elm) //comparing element to be inserted with elements of the sorted array 
        { 
            arr[j + 1] = arr[j]; //swapping if element to be inserted is smaller than the element of sorted array 
            j = j - 1; //after checking with leftmost, it checks all the way till the front of the array 
        }
        arr[j + 1] = elm; //after we find the correct position for elm we place it there and move on to the next element 
    }
}

void bubblesort(int arr[], int n) {
    int i, j, temp; 
    for (i = 0; i < n-1; i++) { //number of passes to shift every element towards the end
        for (j = 0; j < n-i-1; j++) { //makes comparisons at every element
            if (arr[j] > arr[j+1]) { 
                // swap if required 
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }//by the end of this loop, the largest element in the unsorted portion is pushed to the end 
        }
    }
}

// Experimental data analysis 

int main() {
    int n = 10000; // size of the array
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++) {
        int val = rand() % n;
        arr1[i] = val;
        arr2[i] = val; // ensuring both sorts get the same data
    }

    clock_t start, end; //using a timer to compare the swaps and comparisons 
    double timetaken;

    start = clock();
    insertionsort(arr1, n);
    end = clock();
    timetaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion sort took %f seconds to execute \n", timetaken);

    start = clock();
    bubblesort(arr2, n);
    end = clock();
    timetaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort took %f seconds to execute \n", timetaken);

    return 0;
}




