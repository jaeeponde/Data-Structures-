#include <stdio.h>
#include <stdlib.h>

// Structure for the binary search tree node
struct node {
    int key;
    struct node *left, *right;
};

// Structure for the stack of nodes
struct stacknodes {
    struct node* n;
    struct stacknodes* next;
};

//initialising a binary search tree 
struct node* createNode(int k) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

//function to insert values in a binary search tree 
struct node* insert(struct node * anode, int k) {
    struct node *temp, *parent;
    int direction;
    if (anode == NULL) return createNode(k);

    temp = anode;
    while (temp != NULL) {
        if (temp->key == k) {
            printf("node with value %d exists\n", k);
            return temp;
        }
        if (k < temp->key) {
            parent = temp;
            temp = temp->left;
            direction = 0;
        } else {
            parent = temp;
            temp = temp->right;
            direction = 1;
        }
    }
    temp = createNode(k);
    if (direction == 0) parent->left = temp;
    else parent->right = temp;
    return temp;
}


//function to push nodes in the stack 
void push(struct stacknodes** s, struct node* n) {
    struct stacknodes* newnode = (struct stacknodes*)malloc(sizeof(struct stacknodes));
    newnode->n = n;
    newnode->next = *s;
    *s = newnode;
}

//function to pop nodes from the stack 
struct node* pop(struct stacknodes** s) {
    struct node* res;
    struct stacknodes* temp;
    if (*s == NULL) return NULL;

    temp = *s;
    res = temp->n;
    *s = (*s)->next;
    free(temp);
    return res;
}

//inorder traversal 
void inorder(struct node* root) {
    struct stacknodes* s = NULL;
    struct node* current = root;
    while (current != NULL || s != NULL) {

        while (current != NULL) {
            push(&s, current);
            current = current->left; //keep going left till you reach the leaf
        }
        current = pop(&s); //pop the leftmost value 
        printf("%d ", current->key);
        current = current->right; //turn direction to right and then go left from that node
    }
}

void displayNode(struct node* n) {
    if(n) printf("Node value: %d\n", n->key);
}

int main() {
    struct node* root = NULL;
    int elm, menu;
    while(1) {
        printf("0. exit, 1. initialize, 2. insert, 3. inorder. Input Choice: ");
        scanf("%d", &menu);
        switch(menu) {
           case 0: exit(0);
           case 1: root = NULL; break;
           case 2: 
               printf("Give element to insert: ");
               scanf("%d", &elm);
               if (root == NULL) root = insert(root, elm);
               else insert(root, elm);
               break;
           case 3: inorder(root); printf("\n"); break;
           default: printf("Wrong choice\n");
        }
    }
    return 0;
}
