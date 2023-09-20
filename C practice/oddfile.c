#include <stdio.h>
#include <string.h>

int main(){
FILE *fptr; 
fptr = fopen ("oddnums.txt","w");
int num; 
num = 1;
while (num <10){
fprintf(fptr, "%d\n", num);
num= num+2;

}

fclose(fptr);
return 0;




}