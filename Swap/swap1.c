#include <stdio.h>
void noswap(int xp, int yp)
{
    int temp;
    temp = xp; xp = yp; yp = temp;
}
  
void swap(int *xp, int *yp)
{
    int temp;
    temp = *xp; *xp = *yp; *yp = temp;
}
int main(){
int a = 5, b = 3;
noswap(a, b);
printf("a = %d, b = %d\n", a, b);
swap(&a, &b); //passing address instead of value 
printf("a = %d, b = %d\n", a, b);
}
