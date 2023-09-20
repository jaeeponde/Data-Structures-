#include <stdio.h>
#include <string.h>

//files are hidden structures that we can only access with pointers 
// FILE*fptr; 

int main(){

    FILE *fptr;
    
    /* fptr = fopen ("filename",mode) : opening a file
    fclose(fptr); : closing a file
    r : open to read
    rb : open to read in binary 
    w : write (overwrites)
    wb : write in binary (overwrites)
    a : append 
    to check if a file exits, open it to read and check if fptr == NULL;
    reading from a file :
    make a charcter 
    char ch;
    fscanf(fptr, "%c", &ch)
    */

    fptr = fopen ("testfile.txt","a");
    char ch;
    fprintf(fptr, "%c", 'A');
    printf("%c", ch);

    printf("%c", fgetc(fptr));
    printf("%c", fgetc(fptr));
    fputc('N',fptr);
    printf("%c", fgetc(fptr));
    fclose(fptr);

//fgetc(fptr)
//fputc('A',fptr)
//when fgetc returns EOF, the file has ended. compiler has reached the null character 

    return 0;
}