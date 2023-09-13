#include <stdio.h>
//shows the problem with noswap. the addresses of the variables that are swapped is different. 
void noswap(int xp, int yp)
{
    int temp;

    printf("Address in function, %x %x\n", &xp, &yp); 

    printf("xp = %d, yp = %d\n", xp, yp);
    temp = xp; xp = yp; yp = temp;
    printf("xp = %d, yp = %d\n", xp, yp);
}
  
int main(){
    int a = 5, b = 3;
    printf("Address in main %x %x\n", &a, &b); 

    printf("a = %d, b = %d\n", a, b);
    noswap(a, b);
    printf("a = %d, b = %d\n", a, b);
}
