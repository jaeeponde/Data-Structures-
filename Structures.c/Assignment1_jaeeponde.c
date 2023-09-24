#include <stdio.h>
#include <stdlib.h>
#define BADVAL -999

struct node{
int info;
struct node *next;
}; //Creating a structure node 

typedef struct node * NODEPTR; // Creating a pointer for the structure and then assigning the word NODEPTR to it

NODEPTR createNode(int val){ //Function to create new nodes with dynamic memory allocation 
NODEPTR p;
p = (NODEPTR) malloc(sizeof(struct node));
p->info = val;
p->next = NULL;
return p;
}

typedef struct queue{ //creating a structure queue whose elements are pointers of the data type NODEPTRS, i.e, pointers to nodepointers of nodes 
NODEPTR front, rear;
} QUEUE;

//Basically, the changes made in all the functions was simply passing the pointer *q in the parameters
//After that, within each function we use the arrow to point to the address of front and rear

//Function to insert an element from the rear end 
void insert(QUEUE *q, int elm){ 

NODEPTR temp;
temp = createNode(elm);
if (q->front == NULL){
q->front = temp;
q->rear = temp;
}
else{
(q->rear)->next = temp;
q->rear = temp;
}
}

//Function to delete an element from the front end 
int delete(QUEUE *q){
NODEPTR temp;
int val;
if (q->front == NULL) return BADVAL;
else{
temp = q->front;
(q->front) = (q->front)->next;
val = temp->info;
free(temp);
if (q->front == NULL)
q->rear = NULL;
return val;
}
}

//Function to print the queue
void printQueue(QUEUE *q){
NODEPTR temp;
if (q->front == NULL){
printf("Queue empty\n");
return;
}
printf("<- F ");
for (temp = q->front; temp!= NULL; temp = temp->next)
printf("%d ", temp->info);
printf("<- R\n");
}

//In the driver function, we pass &q in all the function parameters instead of just q
int main(){
QUEUE q;

int elm, menu;
while(1){
printf("0. exit, 1. initialize, 2. delete, 3. insert, 4. print. Input Choice: ");
scanf("%d", &menu);
switch(menu){
case 0: exit(0);
case 1: q.front = q.rear = NULL; printf("New queue has been initialised. \n"); //initialising a fresh queue by resetting front and rear values 
break;
case 2: printf("Popped Value %d\n", delete(&q));
break;
case 3: printf("Give element: ");
scanf("%d", &elm);
insert(&q, elm);
break;
case 4: printQueue(&q);
break;
default: printf("Wrong choice\n");
}
}
}


