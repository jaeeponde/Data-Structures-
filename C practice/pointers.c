#include <stdio.h>

/* VARIABLES AND ADDRESSES 
int age = 22;
int *pointervar = &age; pointer variable stores the address of another variable 
int _age = *ptr; _age will have the value of age while pointer will have the value of the address of age 
the type of pointer variables is the same as the variable they are pointing to 
%p and %u are placeholders for addresses and pointer variables 
to find the address of a pointer variable : &ptr 
* : when u want value 
& : when u want address 
*/

int main(){
    int x;
    int *ptr;

    ptr= &x;
    *ptr=0;//here we have accessed x through its address so x=0=*ptr while ptr = address of x

    printf(" x = %d\n",x);
    printf(" *ptr = %d\n",*ptr);
    printf(" ptr = %p\n",ptr);


    int i =5;
    int *pntr=&i;
    int **pptr = &pntr;
    printf("%d\n",**pptr);

//POINTER ARITHMETIC : 
    //increamenting and decreamenting a pointer leads to increases or decreasing a data type 
    //we can subtract one pointer from another 
    //we can also compare two pointers 
    //we can only do comparison for conpatible data type 

return 0;

//call by value : function arguments pass values of variables 
//call by reference : function argumens pass adresses of variables 
//logic : in swap and no swap 



}