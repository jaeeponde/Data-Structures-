#include <stdio.h>
#include <string.h>

struct student {

int roll;
float gpa; 
char name [100];
};

void printinfo(struct student s1) //this is a call by value, not call by refernce 

{printf("student roll no = %d\n", s1.roll);}

int main(){

 struct student s1={400,7.8,"jaee"};
 printinfo(s1);
 return 0;

}