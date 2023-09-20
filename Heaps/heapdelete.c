#include<stdio.h>

//time complexity : O(logn)

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

void heapdelete(int arr[], int n)
{
    //program to extract the first element of the array 
    int value, Lchild, Rchild, largest, flag,i;
    value = arr[0];
    arr[0]=arr[n-1];
    flag=1;
    i=0;

    if(n==0){printf("The array has no elements");}

    while (flag==1){
        flag = 0;
        largest=i;
        Lchild = (2*i)+1;
        Rchild = (2*i)+2;
        //the two loops find the largest of the 3, parents and two children
        if(Lchild<=n-1 && arr[Lchild]>arr[largest])
        {
            largest = Lchild;
            flag = 1; 
        }
        if(Rchild<=n-1 && arr[Rchild]>arr[largest])
        {
            largest = Rchild;
            flag = 1; 
        }
        //now, if one of the childrens is greater than the parent it swaps and largest value switches to the next parent and children set 
        if (flag==1)
        {swap(&arr[largest],&arr[i]);
        i=largest;}}

        printf("The extracted value is %d \n", value);
}


int main(){

    int myheap[]={50,40,12,13,3,4,10};
    heapdelete(myheap, 7);
    printf("The new heap is : \n");
    printarray(myheap,6);
    return 0; }
