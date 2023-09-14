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

    fptr = fopen ("testfile.txt","w");
    char ch;
    fscanf(fptr, "%c\n", &ch);
    printf("%c", ch);
    fclose(fptr);



    return 0;
}