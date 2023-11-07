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




