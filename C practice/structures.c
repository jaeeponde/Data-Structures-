#include <stdio.h>
#include <string.h>
//structure is a collection of different data types 

/*
struct student{

    char name[100];
    int roll;
    float cpga ;
}

- struct is a user defined data type 


*/

struct student{

    char name[100];
    int roll;
    float cgpa ;
};

int main(){
struct student s1;
s1.roll = 900;
s1.cgpa = 9.3;

strcpy(s1.name,"jaee");

puts(s1.name);
printf("%d",s1.roll);
printf("%f",s1.cgpa);

struct student s2;
s2.roll = 901;
s2.cgpa = 9.8;

strcpy(s2.name,"kaee");

puts(s2.name);
printf("%d",s2.roll);
printf("%f",s2.cgpa);

return 0;

}
