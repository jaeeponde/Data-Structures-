#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

void mergearrays(int arr[], int l, int m, int h) 
{ 
	int i, j, k; 
	int half1 = m - l + 1; 
	int half2 = h - m; 

	// create arrays to store left and right side of main arrays 
	int leftarray[half1], rightarray[half2]; 

	// copy data into temp arrays 
	for (i = 0; i < half1; i++) 
		leftarray[i] = arr[l + i]; 
	for (j = 0; j < half2; j++) 
		rightarray[j] = arr[m + 1 + j]; 

	i = 0; 
	j = 0; 
	k = l; 
    //merging the sorted arrays 
	while (i < half1 && j < half2) { 
		if (leftarray[i] <= rightarray[j]) { 
			arr[k] = leftarray[i]; 
			i++; 
		} 
		else { 
			arr[k] = rightarray[j]; 
			j++; 
		} 
		k++; 
	} 
    //inserting any leftover elements of the sorted array incase leftarray>rightarray or vice versa 
	while (i < half1) { 
		arr[k] = leftarray[i]; 
		i++; 
		k++; 
	} 

	while (j < half2) { 
		arr[k] = rightarray[j]; 
		j++; 
		k++; 
	} 
} 

void mergesortdriver(int arr[], int l, int r) 
{ 
	if (l < r) {
		int m = (l + r) / 2; 

		// recursively keeps splitting array 
		mergesortdriver(arr, l, m); 
		mergesortdriver(arr, m + 1 , r); 
        //merging all sorted pairs back together 
		mergearrays(arr, l, m, r); 
	} 
} 

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // first element 
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quicksortdriver(int arr[], int low, int high) {
    if (low < high) {
        int part = partition(arr, low, high);
        quicksortdriver(arr, low, part - 1);
        quicksortdriver(arr, part + 1, high);
    }
}

void heapify(int arr[], int n, int i) { //heapify algorithm that constructs heap bottom up

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        heapify(arr, n, largest);
    }
}

void heapsortdriver(int arr[], int n) {
    //sorting the array as a heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    //extracting the largest element and reheaping
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}



//expermimental analysis 

int main() {
    int n = 10000; 
    int arr1[n], arr2[n], arr3[n];
    for (int i = 0; i < n; i++) {
        int val = rand() % n;
        arr1[i] = val;
        arr2[i] = val;
        arr3[i] = val;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    mergesortdriver(arr1, 0, n-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Merge sort took %f seconds to execute \n", cpu_time_used);

    start = clock();
    quicksortdriver(arr2, 0, n-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick sort took %f seconds to execute \n", cpu_time_used);

    start = clock();
    heapsortdriver(arr3, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Heap sort took %f seconds to execute \n", cpu_time_used);

    return 0;
}



