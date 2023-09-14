#include <stdio.h>

//the square brackets denote dimenions of an array 
// int arr[][] = {{1,2},{3,4}};
//access : arr[1][0]

int main(){
int marks[2][3];
marks [0][0]=90;
marks [0][1]=97;
marks [0][2]=95;

marks [1][0]=90;
marks [1][1]=94;
marks [1][2]=98;

printf("%d", marks[0][2]);
return 0;
}