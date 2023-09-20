#include <stdio.h>
#include <string.h>

int main(){
FILE *fptr; 
fptr = fopen ("studentdata.txt","w");
char name[100];
int age; 

printf("entername");
scanf("%s", name);
printf("enterage");
scanf("%d", &age);

fprintf(fptr, "student name : %s\n", name);
fprintf(fptr, "student age : %d\n", age);

fclose(fptr);
return 0;




}