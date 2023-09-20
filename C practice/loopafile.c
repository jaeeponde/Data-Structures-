#include <stdio.h>
#include <string.h>

int main(){

    FILE *fptr;
    fptr = fopen ("testfile2.txt","r");
    char ch;
    ch = fgetc(fptr);

    while (ch!= EOF){
    printf("%c", ch);
    ch = fgetc(fptr);}

    fclose(fptr);
    return 0; 



}