#include <stdio.h>
#include <stdlib.h>
#define BADVAL = -999

struct node{
int info;
struct node *next;
};
typedef struct node * NODEPTR;


NODEPTR createNode(int val){
NODEPTR p;
p = (NODEPTR) malloc(sizeof(struct node));
p->info = val;
p->next = NULL;
return p;
}


int isEmpty(NODEPTR p){
if (p == NULL) return 1;
else return 0;
}
int pop(NODEPTR *ap){
NODEPTR temp;
int val;
if (isEmpty(*ap)) return 0;
else{
temp = *ap;
(*ap) = (*ap)->next;
val = temp->info;
free(temp);
return val;
}
}

void push(NODEPTR *ap, int elm){
NODEPTR temp;
temp = createNode(elm);
if (*ap == NULL)
*ap = temp;
else{
temp->next = *ap;
*ap = temp;
}
}
void printStack(NODEPTR p){
NODEPTR temp;
if (isEmpty(p)){
printf("Stack empty\n");
return;
}
for (temp = p; temp!= NULL; temp = temp->next)
printf("%d\n", temp->info);

}

int main(){
NODEPTR st;
int elm, menu;
while(1){
printf("0. exit, 1. initialize, 2. pop, 3. push, 4. print. Input Choice: ");
scanf("%d", &menu);
switch(menu){
case 0: exit(0);
case 1: st = NULL;
break;
case 2: printf("Popped Value %d\n", pop(&st));
break;
case 3: printf("Give element: ");
scanf("%d", &elm);
push(&st, elm);
break;
case 4: printStack(st);
break;
default: printf("Wrong choice\n");
}
}
}


