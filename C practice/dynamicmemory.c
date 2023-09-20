#include <stdio.h>
#include <string.h>
#include <stdlib.h> //standard librray for dynamic memory allocation 

/*

Memory allocation function : 
allocates a particular amount of memory 

malloc() : takes in number of bytes and returns a pointer of type void 
ptr = (int*)malloc(5*sizeof(int));

Continuous allocation function : 
calloc() : basically malloc but initialises with 0
the number indicates number of locations and not total number of bytes as a pointer of type void 
ptr = (int*)calloc(5*sizeof(int));

free() : used to free the memory allocated by calloc and malloc 
free(ptr);

realloc(): reallocate memory using the same pointer & size 
ptr = realloc (ptr, newSize);

*/

int main(){

int *malptr;

malptr= (int*) malloc(100*sizeof(float));
malptr[0]=1;
malptr[1]=2;
malptr[2]=3;
//malloc memory allocation is like creating an array, it allocates on runtime and not compile time

malptr = realloc(malptr,10);

float *calptr;
calptr = (float*) calloc(100 , sizeof(int));
for (int i=0; i<100;i++){
printf("%f",calptr[i]);
}

free(calptr);

return 0;
}