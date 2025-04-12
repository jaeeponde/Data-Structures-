#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define BADVAL -9999

struct stack{
    int sp; //sp stands for stack pointer, it tells us where in the array the top of the stack is 
    int arr[SIZE];};

typedef struct stack STACK;

//initialising 
void init (STACK *s)
{
    s->sp=-1;//set stack pointer to -1
}

int empty(STACK *s)
{
    if(s->sp==-1){return 1;}
    else{return 0;}
}

int full (STACK *s)
{
    if(s->sp==SIZE-1){return 1;}
    else{return 0;}
}

int top (STACK *s)
{
    if (empty(s)==1) return BADVAL;
    else return (s->arr[s->sp]);
    
}

int pop (STACK *s)
{
    if (empty(s)==1) return BADVAL;
    else return (s->arr[(s->sp)--]);
    
}

int push (STACK *s,int elm)
{

    if (full(s)==1) return BADVAL;
    else s->arr[++(s->sp)]=elm;
    return 1;
}

void print(STACK *s)
{
    int i ;
    if (empty(s)==1){printf("\n stack is empty \n");}
    printf ("\nTOP\n");

    for (i=s->sp;i>=0;i--){
        printf("%d \n",s->arr[i]);}}

int main(){
    STACK st;
    int elm, menu;
    while (1){
        printf("0. exit, 1. initialize, 2. pop, 3. push, 4. print. Input Choice: "); 
        scanf("%d", &menu);
    
    switch(menu){
        case 0: exit(0);
        case 1: init(&st); break;
        case 2: printf("Popped Value %d\n", pop(&st));break;
        case 3: printf("Give element: ");scanf("%d", &elm);printf("Pushed Flag %d\n", push(&st, elm)); break;
        case 4:print(&st);break;
        deault:printf("wrong choice ");
    }}}






