#include <stdio.h>

int main()
{
int arr[]={1,2,3,4,5};
int n=5;
for (int i=0; i<n/2;i++){

    int f1 = arr[i];
    int f2 = arr[n-i-1];
    arr[i]=f2;
    arr[n-i-1]=f1;
}
for (int i=0; i<n;i++){

    printf("%d\n",arr[i]);
}

return 0;

}
//arrays are always called by reference 