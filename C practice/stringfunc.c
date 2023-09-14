#include <stdio.h>

//gets(str); v v outdated dont use 
//puts(str);
//fgets(str,n,stdin);
//strings are also pointers 
//to mutate a string u have to use it as a pointer 
//to check length for condition arr[i]!='/0'

int main(){

// char sentence[100];

// fgets(sentence,100,stdin);
// puts(sentence);


char *name = "jaee"; //u can change it using pointer
puts(name);
name = "Jaee";
puts(name);

char unchangedname[] = "ponde"; //u cannot change it using array 
puts(unchangedname);
name = "Ponde";
puts(unchangedname);
return 0; 

}


/*
STRING FUNCTIONS :
- strlen (str) : finds length without null char
- strcopy (newstr, oldstr) : value of str2 copies into str 1 
- strcat (str1, str2) : joins str1 + str2 with no added space 






*/