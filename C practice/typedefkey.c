#include <stdio.h>
#include <string.h>

//typedef keyword creates an alias for data types 
/*
example :

typedef struct compscistudent {

    int roll;
    char name[100];

} compsci; 

now to call, we just say compsci.cs1 

*/


struct address {
    int houseno;
    int block;
    char city [100];
};

void printadd(struct address adds){
    printf("address is %d, %d, %s\n", adds.houseno, adds.block, adds.city);

};

int main(){
struct address adds[2];

printf("enter data for person 1:");
scanf("%d", &adds[0].houseno);
scanf("%d", &adds[0].block);
scanf("%s", adds[0].city);

printf("enter data for person 2:");
scanf("%d", &adds[1].houseno);
scanf("%d", &adds[1].block);
scanf("%s", adds[1].city);

printadd(adds[0]);

printadd(adds[1]);
}

