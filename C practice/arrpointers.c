#include <stdio.h>

//arrays are POINTERS

int main()
{
int aadhaar[5];

int *ptr= &aadhaar[0];

//input 
for (int i=0; i<6; i++)
{
    printf("%d INDEX : ", i);
    scanf("%d", (ptr+i));

}

//output 
for (int i=0; i<6; i++)
{
    printf("%d array element : \n", aadhaar[i]);

}

return 0;


}