#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define t 3 //as given in the question, the minimum degree of the tree we are constructing is 3 
#define EMPTY -9999999 //to show that some keys are free in that node 

typedef struct node{
    int level; 
    int keys[(2*t)-1];
    struct Node* children[2*t];
    int num_keys;
    bool is_leaf;
}Node;

//Program 3 : function to create a node or allocate memory for it : 
Node* create_node() {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->num_keys = 0;
    new_node->is_leaf = true;

    //initiating all pointers to null
    for (int i = 0; i < 2 * t; i++) {
        new_node->children[i] = NULL;
    }

    for (int i = 0; i < (2 * t)-1; i++) {
        new_node->keys[i] = EMPTY;
    }

    return new_node;
}

//Program 4 : function to create a node or allocate memory for it : 
void printNode(Node *nodetoprint) {

    printf("The key values of this node are : \n");
    for (int i = 0; i < (2 * t) - 1; i++) {
        printf("  %d  ", nodetoprint->keys[i]);
    }

    printf("\n The number of keys in this node : %d\n",nodetoprint->num_keys );

    printf("\nThe addresses described by the pointers of this node are : \n");
    for (int i = 0; i < (2 * t); i++) {
        printf("  %p  ", (void *)nodetoprint->children[i]);
    }

}

    


//insertion sort : to insert in a sorted list (to be used in program 5)
void insert_into_sorted_list(int sorted_list[], int size, int element) {

    int index = 0;

    // Find the correct position to insert the element
    while (index < size && sorted_list[index] < element && sorted_list[index]!=EMPTY) {
        index++;
    }

    // Shift elements to make space for the new element
    for (int i = size - 1; i >= index; i--) {
        sorted_list[i + 1] = sorted_list[i];
    }

    // Insert the element at the correct position
    sorted_list[index] = element;
}

//program 5 : insertion in a node where there is an empty key 

void insert_to_empty(int k, Node *node)
{ insert_into_sorted_list(node->keys,(2*t-1),k); node->num_keys++ ;}

// program 6 : to split tree incase of a full node 
void split_tree(Node* node, int k) {

    printf("working");

    int mid = 3;
    int mid_key = node->keys[mid];
    int new_keys[(2 * t)];

    for (int i = 0; i < (2 * t - 1); i++) {
        new_keys[i] = node->keys[i];
        printf("%d",new_keys[i]);
        
    }


    insert_into_sorted_list(new_keys, (2 * t), k);

    // Create new nodes for the split
    Node* left_node = create_node();
    Node* right_node = create_node();

    // copy keys to the left node
    for (int i = 0; i < mid; i++) {
        left_node->keys[i] = new_keys[i];
        left_node->num_keys++;
    }

    // copy keys to the right node
    for (int i = mid + 1, j = 0; i < (2 * t); i++, j++) {
        right_node->keys[j] = new_keys[i];
        right_node->num_keys++;
    }

    // copy children to the left node if node is not a leaf
    if (!node->is_leaf) {
        for (int i = 0; i <= mid; i++) {
            left_node->children[i] = node->children[i];
        }
    }

    // Copy children to the right node if node is not a leaf
    if (!node->is_leaf) {
        for (int i = mid + 1; i <= (2 * t); i++) {
            right_node->children[i - mid - 1] = node->children[i];
        }
    }

    // 2et the middle key to the parent node
    node->num_keys = 1;
    node->keys[0] = mid_key;
    node->keys[1] = EMPTY;
    node->keys[2] = EMPTY;
    node->keys[3] = EMPTY;
    node->keys[4] = EMPTY;


    // update node's children pointers
    node->children[0] = left_node;
    node->children[1] = right_node;
    node->is_leaf = false;
}


//program 6 
void insert(int k, Node *node)
{ 
    printf("\nInserting Key : %d \n",k);
    if (node->num_keys<(2*t)-1)
        {insert_to_empty(k, node);        
        printf("\n");
        printNode(node);
        printf("\n");
        
        }
    
    else{

       
        split_tree(node,k);
        printf("\n");
        printNode(node);
        printf("\n");


    }

}

//program 7 
void search(int k, Node *node) {
    int found = 0;

    for (int i = 0; i < node->num_keys; i++) {
        if (k == node->keys[i]) {
            printf("\n The key was found\n");
            found = 1;
        }
    }

    int i = 0;
    while (i < node->num_keys && k > node->keys[i]) {
        i++;
    }

    // Check if the node is a leaf before making the recursive call
    if (!node->is_leaf && found == 0) {
        search(k, node->children[i]);
    }

    if (found == 0) {
        printf("\n The key was not found\n");
    }
}




int main(){

printf("--------------Program 1----------------\n");
printf("Name : Jaee Ponde \n");
printf("Roll Number : 1020221519\n");
printf("Course : Data Structures CS-1203-2\n");
printf("Year : UG25\n");
printf("Email : jaee.ponde_ug25@ashoka.edu.in\n");
printf("Phone : 8655502529\n");
printf("----------------------------------------\n");

    //lets do Question 2 first : 
    // Program 2 
    printf("\n--------------Program 2----------------\n");
    Node *my_node = create_node(); 
    insert(70, my_node);
    insert(20, my_node);
    insert(30, my_node);
    insert(48, my_node);
    insert(52, my_node);
    printf("\n----------------------------------------\n");

    //Program 6
    printf("\n--------------Program 6---------------\n");
    insert(64, my_node);
    printf("\n----------------------------------------\n");

    //Program 7
    printf("\n--------------Program 7---------------\n");
    search(20, my_node);
    search(20, my_node);
    printf("\n----------------------------------------\n");
    


}


