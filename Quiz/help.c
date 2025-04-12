#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define t 3
#define EMPTY -9999999

typedef struct Node {
    int level;
    int keys[(2 * t) - 1];
    struct Node* children[2 * t];
    int num_keys;
    bool is_leaf;
} Node;

Node* create_node() {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->num_keys = 0;
    new_node->is_leaf = true;

    for (int i = 0; i < 2 * t; i++) {
        new_node->children[i] = NULL;
    }

    for (int i = 0; i < (2 * t) - 1; i++) {
        new_node->keys[i] = EMPTY;
    }

    return new_node;
}

void printNode(Node* nodetoprint) {
    printf("The key values of this node are : \n");
    for (int i = 0; i < (2 * t) - 1; i++) {
        printf("  %d  ", nodetoprint->keys[i]);
    }

    printf("\n The number of keys in this node : %d\n", nodetoprint->num_keys);

    printf("\nThe addresses described by the pointers of this node are : \n");
    for (int i = 0; i < (2 * t); i++) {
        if (nodetoprint->children[i] != NULL) {
            printf("  %p  ", (void*)nodetoprint->children[i]);
        } else {
            printf("  NULL  ");
        }
    }
}

void insert_into_sorted_list(int sorted_list[], int size, int element) {
    int index = 0;

    while (index < size && sorted_list[index] < element && sorted_list[index] != EMPTY) {
        index++;
    }

    for (int i = size - 1; i >= index; i--) {
        sorted_list[i + 1] = sorted_list[i];
    }

    sorted_list[index] = element;
}

void insert_to_empty(int k, Node* node) {
    insert_into_sorted_list(node->keys, (2 * t - 1), k);
    node->num_keys++;
}

void split_tree(Node* node, int k) {
    int mid = (2 * t - 1) / 2;
    int mid_key = node->keys[mid];
    int new_keys[(2 * t)];

    for (int i = 0; i < (2 * t - 1); i++) {
        new_keys[i] = node->keys[i];
    }

    insert_into_sorted_list(new_keys, (2 * t) - 1, k);

    Node* left_node = create_node();
    Node* right_node = create_node();

    int i, j;

    // copy keys to the left node
    for (i = 0; i < mid; i++) {
        left_node->keys[i] = new_keys[i];
        left_node->num_keys++;
    }

    // copy keys to the right node
    for (i = mid + 1, j = 0; i < (2 * t); i++, j++) {
        right_node->keys[j] = new_keys[i];
        right_node->num_keys++;
    }

    // copy children to the left node if node is not a leaf
    if (!node->is_leaf) {
        for (i = 0; i <= mid; i++) {
            left_node->children[i] = node->children[i];
        }
    }

    // Copy children to the right node if node is not a leaf
    if (!node->is_leaf) {
        for (i = mid + 1; i <= (2 * t); i++) {
            right_node->children[i - mid - 1] = node->children[i];
        }
    }

    // set the middle key to the parent node
    node->num_keys = 1;
    node->keys[0] = mid_key;
    node->keys[1] = EMPTY;

    // update node's children pointers
    node->children[0] = left_node;
    node->children[1] = right_node;
    node->is_leaf = false;
}

void insert(int k, Node* node) {
    printf("\nInserting Key : %d \n", k);
    if (node->num_keys < (2 * t) - 1) {
        insert_to_empty(k, node);
        printf("\n");
        printNode(node);
        printf("\n");
    } else {
        split_tree(node, k);
        printf("\n");
        printNode(node);
        printf("\n");
    }
}

void search(int k, Node* node) {
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

    if (!node->is_leaf && found == 0) {
        search(k, node->children[i]);
    }

    if (found == 0) {
        printf("\n The key was not found\n");
    }
}

int main() {
    Node* root = create_node();

    // Insert keys into the B-tree
    insert(10, root);
    insert(20, root);
    insert(5, root);
    insert(6, root);
    insert(12, root);

    // Insert the key that caused the issue
    insert(64, root);

    // Search for a key in the B-tree
    search(6, root);

    return 0;
}




