#include <stdio.h>
#include <string.h>

struct student {


    int roll;
    float gpa;
    char name[100];
};

int main(){
struct student s1={1000,9.1,"jaee"};
printf("student roll = %d\n", s1.roll);

struct student *ptr = &s1;//pointer to s1
printf("student roll = %d\n", (*ptr).roll);//referencing structure through it's pointer

// we can also use arrow instead of dot -> 
// s1->roll


}