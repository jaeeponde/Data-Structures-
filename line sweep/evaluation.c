#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// structure for points 
typedef struct Point {
    int x, y, z;
} Point;

// for nodes in the AVL tree 
typedef struct TreeNode {
    Point p;
    struct TreeNode *left, *right;
    int height;
} TreeNode;

// global operations counter
int operations = 0;


// create a new node 
TreeNode* createNode(Point p) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->p = p;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; // all leaf nodes have height 1 
    return newNode;
}

// get height of a node
int height(TreeNode* node) {
    return (node == NULL) ? 0 : node->height;
}

// calculate balance factor 
int getBalance(TreeNode* node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

// right rotate subtree rooted with y
TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    // update heights
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

// left rotate subtree rooted with x
TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    // update heights
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

// insert a new point into the AVL Tree based on y-value
/*

The root of the tree has some (y,z) 
all elements in left subtree have a lower y ---> so they must have a greater z than the root 
all elements in the right subtree have a greater y ----> so they must have a smaller z than the root 

if an element being inserted has a (y,z) such that y>rooty and z>rootz, it dominates the root
so the root must get deleted along with all the other nodes it dominates 
thus restoring the previous order of the tree 

so at every step after insertion and deletion
the tree contains elements that don't dominate each other. 

*/

TreeNode* insert(TreeNode* root, Point p) {
    operations++;
    if (root == NULL)
        return createNode(p);

    if (p.y < root->p.y)
        root->left = insert(root->left, p);
    else if (p.y > root->p.y)
        root->right = insert(root->right, p);
    else
        return root; // no duplicate y-values allowed

    // update height of this ancestor node
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    // check balance factors
    int balance = getBalance(root);

    // LL imbalance
    if (balance > 1 && p.y < root->left->p.y)
        return rightRotate(root);

    // RR imbalance
    if (balance < -1 && p.y > root->right->p.y)
        return leftRotate(root);

    // LR imbalance
    if (balance > 1 && p.y > root->left->p.y) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL imbalance
    if (balance < -1 && p.y < root->right->p.y) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// checks if a point is dominated by another point in the staircase and also outputs a witness point 
int isDominated(TreeNode* root, Point p) {
    operations++;
    while (root != NULL) {
        if (p.x < root->p.x && p.y < root->p.y && p.z < root->p.z) {
            printf("(%d, %d, %d) is dominated by (%d, %d, %d)\n", p.x, p.y, p.z, root->p.x, root->p.y, root->p.z);
            return 1;
        }
        if (p.x == root->p.x && p.y < root->p.y && p.z < root->p.z) {
            printf("(%d, %d, %d) is a maximal point\n", p.x, p.y, p.z);
            return 1;}
        if (p.y > root->p.y)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}

// when a new point is added, this function deletes all points in staircase dominated by new point.
// each deletion takes logn time 
TreeNode* deleteDominated(TreeNode* root, Point p) {
    operations++;
    if (root == NULL)
        return NULL;

    // traverse left and right subtrees first
    root->left = deleteDominated(root->left, p);
    root->right = deleteDominated(root->right, p);

    // if the current node is dominated, remove it
    if (root->p.y < p.y && root->p.z < p.z) {
        TreeNode* temp;
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: find the inorder successor (smallest in the right subtree)
        temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;

        // put inorder successor's content to this node
        root->p = temp->p;

        // remove the inorder successor
        root->right = deleteDominated(root->right, temp->p);
    }

    // update height of the current node
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    // get the balance factor of this node
    int balance = getBalance(root);

    // balance the tree if it has become unbalanced
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// comparison function for sorting points by x-coordinate 
int compare(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return p2->x - p1->x;
}

// inorder traversal of the AVL tree
void inorderTraversal(TreeNode* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("(%d, %d, %d)\n", root->p.x, root->p.y, root->p.z);
    inorderTraversal(root->right);
}

// function to check if the inorder traversal is monotone by y-coordinate
int isMonotoneByY(TreeNode* root, int* prevY) {
    if (root == NULL)
        return 1;

    // check the left subtree
    if (!isMonotoneByY(root->left, prevY))
        return 0;

    // current node's y should be greater than the previous y
    if (root->p.y < *prevY)
        return 0;

    *prevY = root->p.y;

    // check the right subtree
    return isMonotoneByY(root->right, prevY);
}

// function to find maximal points
void findMaximalPoints(Point points[], int n) {
    // sort points by x-coordinate in descending order
    qsort(points, n, sizeof(Point), compare);

    // initialize the AVL Tree and maximal points list
    TreeNode* avl = NULL;
    printf("Maximal points:\n");

    for (int i = 0; i < n; i++) {
        // check if the current point is dominated
        if (!isDominated(avl, points[i])) {

            /*
            if a point is not dominated by the previous point, 
            we add it to the staircase and output it as a maximal point. 
            
            imp to note : the reason we output it here itself is that
            even though this point may get dominated in the y-z projection
            we know that we are checking points in decreasing order of x 
            so the point is still maximal in the x,y,z space
            */ 

            printf("(%d, %d, %d) is a maximal point\n", points[i].x, points[i].y, points[i].z);
            avl = insert(avl, points[i]);
            // delete all points that are now dominated by this point
            avl = deleteDominated(avl, points[i]);
        }
    }

    // inorder traversal of the staircase
    printf("\nInorder traversal of the staircase:\n");
    inorderTraversal(avl);

    // check if the staircase is monotone by y-coordinate
    int prevY = -1; 
    if (isMonotoneByY(avl, &prevY)) {
        printf("\nThe staircase is monotone by y-coordinate.\n");
    } else {
        printf("\nThe staircase is NOT monotone by y-coordinate.\n");
    }
}

// function to input points manually
void inputPoints(Point points[], int* n) {
    int count;
    printf("Enter the number of points: ");
    scanf("%d", &count);
    *n = count;

    for (int i = 0; i < count; i++) {
        printf("Enter point %d (x y z) in the format x y z : ", i + 1);
        scanf("%d %d %d", &points[i].x, &points[i].y, &points[i].z);
    }
}

// function to show all input points
void showPoints(Point points[], int n) {
    if (n == 0) {
        printf("No points entered yet.\n");
        return;
    }
    printf("Current points:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d, %d)\n", points[i].x, points[i].y, points[i].z);
    }
}


// test the algorithm with a random set of points
int main() {

    
    int n = 0;  // number of points
    Point points[100];  // array to hold up to 100 points
    int choice;

    while (1) {
        operations=0;
        // Display menu
        printf("\nMenu:\n");
        printf("1. Enter input points\n");
        printf("2. Show all input points\n");
        printf("3. Run the algorithm and find maximal points\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Input points
                inputPoints(points, &n);
                break;
            case 2:
                // Show points
                showPoints(points, n);
                break;
            case 3:
                // Run the maximal points algorithm
                if (n == 0) {
                    printf("No points to process. Please input points first.\n");
                } else {
                    findMaximalPoints(points, n);
                    printf("\nTotal number of operations: %d\n", operations);
                }
                break;
            case 4:
                // Exit
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
