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
void printNode(Node *nodetoprint){

    printf("The key values of this node are : \n");
    for (int i = 0; i < (2 * t)-1; i++) {
        printf("  %d  ", nodetoprint->keys[i]);
    }
    printf("\nThe addresses described by the pointers of this node are : \n");
    for (int i = 0; i < (2 * t); i++) {
        printf("  %p  ", nodetoprint->children[i]);
    }}


//insertion sort : to insert in a sorted list 
void insert_into_sorted_list(int sorted_list[], int size, int element) {

    int index = 0;

    // Find the correct position to insert the element
    while (index < size && sorted_list[index] < element) {
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
{ insert_into_sorted_list(node->keys,(2*t-1),k); }






int main(){

// printf("---------Student Information----------\n");
// printf("Name : Jaee Ponde \n");
// printf("Roll Number : 1020221519\n");
// printf("Course : Data Structures CS-1203-2\n");
// printf("Year : UG25\n");
// printf("Email : jaee.ponde_ug25@ashoka.edu.in\n");
// printf("Phone : 8655502529\n");
// printf("--------------------------------------\n");

}


