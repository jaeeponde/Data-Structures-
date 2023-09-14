#include <stdio.h>
#include <string.h>

/*
 
 struct student SCS[100];
 struct student CS[100];
 struct student IT[100];

 to assign a valie =>
 ECE

 
 
 */
struct student {

    int roll;
    float gpa;
    char name[100];
};


int main(){
struct student ece[100];
ece[0].roll = 100;
ece[0].gpa=4.3;
strcpy(ece[0].name, "jaee");
printf("name =%s\n", ece[0].name);

return 0;


}
