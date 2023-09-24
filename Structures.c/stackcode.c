#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
#define BADVAL -9999

struct stack{
    int sp;
    int arr[SIZE];    
};

typedef struct stack STACK;

void init(STACK *s){
	s->sp = -1;
}

int isEmpty(STACK *s){
	if (s->sp == -1) return 1;
	else return 0;
}

int isFull(STACK *s){
	if (s->sp == SIZE-1) return 1;
	else return 0;
}

int top(STACK *s){

	if (isEmpty(s)) return BADVAL;
	else return(s->arr[s->sp]);
}

int pop(STACK *s){

	if (isEmpty(s)) return BADVAL;
	else return(s->arr[(s->sp)--]);
}

int push(STACK *s, int elm){

	if (isFull(s)) return 0;
	else{
	   s->arr[++(s->sp)] = elm;
	   return 1;
	}
}
void printStack(STACK *s){

	int i;
	if (isEmpty(s)){ 
		printf("Stack empty\n");
		return;
	}
	for (i = s->sp; i >= 0; i--)
		printf("%d\n", s->arr[i]);
}

int main(){

        STACK st;
	int elm, menu;

	while(1){
          printf("0. exit, 1. initialize, 2. pop, 3. push, 4. print. Input Choice: ");
	  scanf("%d", &menu);

	  switch(menu){
	   case 0: exit(0);
           case 1: init(&st); 
                   break;
           case 2: printf("Popped Value %d\n", pop(&st)); 
                   break;
           case 3: printf("Give element: "); 
                   scanf("%d", &elm); 
                   printf("Pushed Flag %d\n", push(&st, elm)); break;
           case 4: printStack(&st); 
                   break;
	   default: printf("Wrong choice\n");
         }
        }
}