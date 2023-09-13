#include <stdio.h>
int main()
{
    int n = 8, i, min, max, temp;
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 3};

    for (i = 0; i < n/2; i++)
    if (arr[2*i] > arr[2*i+1]){
		temp = arr[2*i];
		arr[2*i] = arr[2*i+1];
		arr[2*i + 1] = temp;
    }

    //all right values (odd) are greater than all left values (even)
    //so now we only have to compare half the set to find min and max 
   
   min = arr[0]; max = arr[1];
   for (i = 1; i < n/2; i++){
      if (min > arr[2*i]) min = arr[2*i]; 
      if (max < arr[2*i+1]) max = arr[2*i+1]; 
   }
   printf("min %d, max %d\n", min, max);
}