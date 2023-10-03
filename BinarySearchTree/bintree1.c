#include <stdio.h>
#include <stdlib.h>
 
struct node{
    int key;
    struct node *left, *right;
};

struct node * createNode(int k){
    struct node *temp;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

void displayNode(struct node *temp){

	if (temp == NULL)
		printf("Node does not exist\n");
	else
    		printf("%x %d\n", (unsigned int) temp, temp->key);

}

struct node * search(struct node * anode, int k){

    struct node *temp, *parent;
     
    if (anode == NULL) return NULL;
    
    temp = anode;
    while (temp != NULL){
	if (temp->key == k){
	   return temp;
        }

    	if (k < temp->key){
            temp = temp->left;
        }
        else{
	    temp = temp->right;
        }
    }
    return NULL;
}
        
struct node * insert(struct node * anode, int k){

    struct node *temp, *parent;
    int direction;
     
    if (anode == NULL){
        anode = createNode(k);
	return anode;
    }
    
    temp = anode;
    while (temp != NULL){
	if (temp->key == k){
	   printf("node with value %d exists\n", k);
	   return temp;
        }

    	if (k < temp->key){
	    parent = temp;
            temp = temp->left;
            direction = 0;
        }
        else{
	    parent = temp;
	    temp = temp->right;
            direction = 1;
        }
    }
    temp = createNode(k);
    if (direction == 0)
        parent->left = temp;
    else
        parent->right = temp;
        
   return temp; 
}

void inorder(struct node * anode){
    if (anode != NULL) {
        inorder(anode->left);
        printf("%d ", anode->key);
        inorder(anode->right);
    }
}

int main()
{
    struct node * root = NULL, *temp;
    int elm, menu;

    while(1){
          printf("0. exit, 1. initialize, 2. search, 3. insert, 4. inorder. Input Choice: ");
          scanf("%d", &menu);

          switch(menu){
           case 0: exit(0);

           case 1: root = NULL;
                   break;

           case 2: printf("Give element to search: ");
                   scanf("%d", &elm);
		   temp = search(root, elm);
		   displayNode(temp);
                   break;

           case 3: printf("Give element to insert: ");
                   scanf("%d", &elm);
		   if (root == NULL)
		   	temp = root = insert(root, elm);
		   else
		   	temp = insert(root, elm);
		   displayNode(temp);
                   break;

           case 4: inorder(root);
		   printf("\n");
                   break;

           default: printf("Wrong choice\n");
         }
        }

    return 0;
}
