#include <stdio.h>  
#include <stdlib.h>  


//CODE SHARED BY PROFESSOR : 
//------------------------------------------------------------------------------------- 
struct Node  
{  
    int key;  
    struct Node *left;  
    struct Node *right;  
    int height;  
};  
   
int getHeight(struct Node *n){  
    if(n==NULL)  
        return 0;  
    return n->height;  
}  
   
struct Node *createNode(int key){  
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));  
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;  
    return node;  
}  

void displayTree(struct Node* root, int space)
{
    int i;

    if (root == NULL) return;

    space += 10;

    // Process right child first
    displayTree(root->right, space);

    // Print current node after space count
    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    displayTree(root->left, space);
}
   
int max (int a, int b){  
    return (a>b)?a:b;  
}  
   
int getBalanceFactor(struct Node * n){  
    if(n==NULL){  
        return 0;  
    }  
    return getHeight(n->left) - getHeight(n->right);  
}  
   
struct Node* rightRotate(struct Node* y){  
    struct Node* x = y->left;  
    struct Node* T2 = x->right;  
   
    x->right = y;  
    y->left = T2;  
   
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  
   
    return x;  
}  
   
struct Node* leftRotate(struct Node* x){  
    struct Node* y = x->right;  
    struct Node* T2 = y->left;  
   
    y->left = x;  
    x->right = T2;  
   
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  
   
    return y;  
}  
   
struct Node *insert(struct Node* node, int key){  
    if (node == NULL)  
        return  createNode(key);  
   
    if (key < node->key)  
        node->left  = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
   
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));  
    int bf = getBalanceFactor(node);  
   
    // Left Left Case  
        if(bf>1 && key < node->left->key){  
            return rightRotate(node);  
        }  
    // Right Right Case  
        if(bf<-1 && key > node->right->key){  
            return leftRotate(node);  
        }  
    // Left Right Case  
    if(bf>1 && key > node->left->key){  
            node->left = leftRotate(node->left);  
            return rightRotate(node);  
        }  
    // Right Left Case  
    if(bf<-1 && key < node->right->key){  
            node->right = rightRotate(node->right);  
            return leftRotate(node);  
        }  
    return node;  
}  
   
void preOrder(struct Node *root)  
{  
    if(root != NULL)  
    {  
        printf("%d ", root->key);  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  

void inOrder(struct Node *root)  
{  
    if(root != NULL)  
    {  
        preOrder(root->left);  
        printf("%d ", root->key);  
        preOrder(root->right);  
    }  
}  

//-------------------------------------------------------------------------------------
//IMPLEMENTING DELETION

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // traverse to the leftmost leaf
    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    

    if (root == NULL) return root; //if tree is empty 

    //move to left if key is smaller than node 
    if (key < root->key) root->left = deleteNode(root->left, key); //recursively unwinds the tree

    //move to right if key is bigger than node 
    if (key > root->key) root->right = deleteNode(root->right, key); //recursively unwinds the tree

    //key found
    else {
        //node with one child or leaf node 
        if ((root->left == NULL) || (root->right == NULL)) 
            {
            //set temp to null or the child that exists 
            struct Node* temp = root->left ? root->left : root->right;

            //if it was a leaf node, assign root to temp and make the root null 
            if (!temp) {
                temp = root;
                root = NULL;

            } 
            
            //if it had only one child, replace the deleted node with the child 
            else { 
                *root = *temp; 
            }

            free(temp); //empty memory 
            } 
        
        //if node had 2 children
        else {
            // getting inorder succesor
            struct Node* temp = minValueNode(root->right);

            // replacing that node with inorder succesory 
            root->key = temp->key;

            // remove inorder succesor
            root->right = deleteNode(root->right, temp->key);
             }
          }

    //tree with only root 
    if (!root) return root;

    //update height 
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    //get balance factor 
    int balance = getBalanceFactor(root);

    //balancing the tree : 

    //LL imbalance 
    if (balance > 1 && getBalanceFactor(root->left) >= 0) return rightRotate(root);

    //LR imbalance 
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //RR imbalance 
    if (balance < -1 && getBalanceFactor(root->right) <= 0) return leftRotate(root);

    //RL imbalance 
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, key;

    while (choice !=6 ) {
        printf("Options:\n");
        printf("1. Insert a key\n");
        printf("2. Delete a key\n");
        printf("3. Display tree in Pre-order\n");
        printf("4. Display tree in In-order\n");
        printf("5. Display tree visually\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;

            case 3:
                printf("Pre-order traversal: ");
                preOrder(root);
                printf("\n");
                break;

            case 4:
                printf("In-order traversal: ");
                inOrder(root);
                printf("\n");
                break;

            case 5:
                displayTree(root, 10);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


