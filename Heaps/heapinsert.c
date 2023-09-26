#include<stdio.h>

//time complexity trivially : O(nlogn)
//actual time complexity : O(n)

void swap(int *xp, int *yp){
int temp; 
temp = *xp;
*xp=*yp;
*yp=temp;
}

void printarray(int arr[], int size){
int i;
for (i=0;i<size;i++){printf("   %d   ",arr[i]);}
printf("\n");
}

void heapinsert(int heaparr[], int element, int n){

    int i, parent;
    heaparr[n]=element;
    i=n;
    if (i==0){return ;}

    while (i!=0){
        parent = (i-1)/2;
        //condition of the heap : parent must awlays be greater than the child
        if (heaparr[parent]<heaparr[i]){
            swap(&heaparr[i],&heaparr[parent]);}
        else{break;}
        i=parent; 
        }}

int main(){

    int myheap[]={50,40,12,13,3,4,10};
    int toinsert = 90;
    heapinsert(myheap, toinsert, 7);
    printarray(myheap,8);
    return 0; 

}


