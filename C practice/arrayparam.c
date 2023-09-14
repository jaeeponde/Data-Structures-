#include <stdio.h>

void printnum(int arr[],int n){


for (int i=0;i<n;i++)
{
    printf("%d\n",arr[i]);


}
}

int main (){

int arr1[] = {9,7,4,2};

printnum(arr1,4);

return 0 ;
}