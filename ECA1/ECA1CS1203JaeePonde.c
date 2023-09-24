#include <stdio.h>

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){printf("%d ", arr[i]);}
    printf("\n");
}

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void allperm(int* arr, int n) {
    // initialize the placeholder array to 0
    int p[n];
    for(int i = 0; i < n; i++) {
        p[i] = 0;
    }
    
    // print the initial array
    printarray(arr, n);

    int i = 1; // index to keep track of the current position 
    while(i < n) {
        //because when the value of the helper array becomes i, we know that all possible swaps have been made 
        if (p[i] < i) {

            // if i is even we swap with the 0th position, if i is odd we swap with the p[i]th position.
            //this ensures all possible swaps
            int j ;
            if ((i%2)==0) {j=0;}
            else {j=p[i];}
            
            // swap arr[i] and arr[j]
            swap(arr, i, j);
            
            // prints the new permutation
            printarray(arr, n);
            
            // increases p[i]
            // an increase in the placeholder array denotes that the current element has been swapped. 
            p[i]++;
            i = 1;
        } else {
            // reset p[i] and increment i to move on to the next element 
            p[i] = 0;
            i++;
        }
    }
}

int main(){
    int n; //accepting a value n from the user 
    printf("Enter a number for n<=8 \n");
    scanf("%d", &n);
    int arr[n]; //creating an array 1,2,3...n 
    for(int i=0;i<n;i++){
        arr[i]=i+1;}

    //printing all permutations of the array 

    allperm(arr, n);
    }


/*

Explaining the logic of the main function allperm : (idk how to write it for 50 marks so if a more formal explaination is required pls let me know)

- first it creates a helper array called p full of zeros. this keeps track of how many times we've swapped numbers. 
- then it prints the original order of numbers as our first permutation

- we start with the second position (so if the array was 1,2,3 we start with making swaps with 2)
- keep rearranging 2 till we have exhausted all of its possible arrangements 

- for every position i we have to first check if we have exhausted all possible positions. 
this is checked by comparing i with p[i]

- if we haven't swapped this number enough we decide who to swap it with
    - if i is even swap with the first position
    - if i is an odd swap it with the position indicated by p[i]
  - then we print new permutation 
  - increase p[i] to denote that a swap has been made 
  - reset to the second position and repeat

- if we have swapped this number all the times we can, we just reset our helper array for this position and move to the next number.

this loop continues, creating all possible arrangements, until we've done this for all numbers.

*/