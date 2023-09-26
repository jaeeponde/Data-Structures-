#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
#define BADVAL -9999

struct queue{
    int front, rear;
    int arr[SIZE];    
};

typedef struct queue QUEUE;

void init(QUEUE *q){
	q->front = q->rear = -1;
}

int isEmpty(QUEUE *q){
	if (q->front == -1) return 1;
	else return 0;
}

int isFull(QUEUE *q){
	int i, j = 0;
	if ((q->front == 0) && (q->rear == SIZE-1)) return 1;
        else if ((q->front > 0) && (q->rear == SIZE-1)){
		for(i=q->front; i < SIZE-1; i++)
			q->arr[j++] = q->arr[i];
		return 0;
        }
	return 0;
}

int front(QUEUE *q){

	if (isEmpty(q)) return BADVAL;
	else return(q->arr[q->front]);
}

int delete(QUEUE *q){

	int elm;
	if (isEmpty(q)) return BADVAL;
	else{ 
		elm = q->arr[(q->front)++];
		if (q->front > q->rear)
			init(q);
		return elm;
	}
}

int insert(QUEUE *q, int elm){

	if (isFull(q)) return 0;
	else{
	   if (isEmpty(q)) (q->front)++;
	   q->arr[++(q->rear)] = elm;
	   return 1;
	}
}
void printQueue(QUEUE *q){

	int i;
	if (isEmpty(q)){ 
		printf("Queue empty\n");
		return;
	}
        printf("<- F ");
	for (i = q->front; i <= q->rear; i++)
		printf("%d ", q->arr[i]);
        printf("<- R\n");
}

int main(){

        QUEUE qq;
	int elm, menu;

	while(1){
          printf("0. exit, 1. initialize, 2. delete, 3. insert, 4. print. Input Choice: ");
	  scanf("%d", &menu);

	  switch(menu){
	   case 0: exit(0);
           case 1: init(&qq); 
                   break;
           case 2: printf("Deleted Value %d\n", 
                   delete(&qq)); 
                   break;
           case 3: printf("Give element: "); 
                   scanf("%d", &elm); 
                   printf("Insert Flag %d\n", insert(&qq, elm)); 
                   break;
           case 4: printQueue(&qq); 
                   break;
	   default: printf("Wrong choice\n");
         }
        }
}