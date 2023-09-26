#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp;
    temp = *xp; *xp = *yp; *yp = temp;
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){printf("%d \n", arr[i]);}
}

void heapify(int arr[], int n, int i){

int largest, left, right, j; 
j=1; 


while(j==1){
left = (2*i)+1; right = (2*i)+2; largest = i; 
if (left<n && arr[left]>arr[largest]){
    largest = left; 
}
if (right<n && arr[right]>arr[largest]){
    largest = right; 
}
if(largest!=i){
    swap(&arr[i],&arr[largest]);
    i=largest; 
}
else {break;}}

}

int main (){

    int arr1[]= {4,6,8,67,90,2,0,44};
    int n = 8; 
    printarray(arr1,n);
    for (int i = n/2 - 1; i >= 0; i--)
    {heapify(arr1, n, i);}
    printf("The heaped array is \n");
    printarray(arr1,n); 
}









