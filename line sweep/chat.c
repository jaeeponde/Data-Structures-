#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POINTS 100

typedef struct Point {
    int x, y, z;
} Point;

typedef struct AVLNode {
    Point point;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

// Global counter for AVL tree operations
int operations = 0;

// Utility function to create a new AVL node
AVLNode* createNode(Point point) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->point = point;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Get the height of the node
int height(AVLNode* node) {
    if (node == NULL) return 0;
    return node->height;
}

// Get the balance factor of a node
int getBalance(AVLNode* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

// Right rotate utility
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + ((height(y->left) > height(y->right)) ? height(y->left) : height(y->right));
    x->height = 1 + ((height(x->left) > height(x->right)) ? height(x->left) : height(x->right));
    return x;
}

// Left rotate utility
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + ((height(x->left) > height(x->right)) ? height(x->left) : height(x->right));
    y->height = 1 + ((height(y->left) > height(y->right)) ? height(y->left) : height(y->right));
    return y;
}

// Insert a point into the AVL tree based on y-coordinate
AVLNode* insert(AVLNode* node, Point point) {
    operations++;
    if (node == NULL) return createNode(point);

    if (point.y < node->point.y)
        node->left = insert(node->left, point);
    else if (point.y > node->point.y)
        node->right = insert(node->right, point);
    else // Duplicate y values not allowed, compare z
        if (point.z > node->point.z)
            node->right = insert(node->right, point);
        else
            node->left = insert(node->left, point);

    node->height = 1 + ((height(node->left) > height(node->right)) ? height(node->left) : height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && point.y < node->left->point.y) return rightRotate(node);
    if (balance < -1 && point.y > node->right->point.y) return leftRotate(node);
    if (balance > 1 && point.y > node->left->point.y) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && point.y < node->right->point.y) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Check if a point is dominated by any point in the AVL tree and return the dominating point
AVLNode* isDominated(AVLNode* node, Point point) {
    operations++;
    if (node == NULL) return NULL;

    if (point.y <= node->point.y && point.z <= node->point.z)
        return node;

    if (point.y < node->point.y)
        return isDominated(node->left, point);

    return isDominated(node->right, point);
}

// Comparison function for qsort (sorts by x-coordinate in descending order)
int compareX(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return p2->x - p1->x;
}

// Function to perform maximal points search
void findMaximalPoints(Point points[], int n) {
    qsort(points, n, sizeof(Point), compareX);

    AVLNode* avlRoot = NULL;
    printf("Maximal Points:\n");

    for (int i = 0; i < n; i++) {
        Point currentPoint = points[i];
        AVLNode* dominatingNode = isDominated(avlRoot, currentPoint);

        if (dominatingNode) {
            printf("Point (%d, %d, %d) is dominated by (%d, %d, %d)\n", currentPoint.x, currentPoint.y, currentPoint.z,
                   dominatingNode->point.x, dominatingNode->point.y, dominatingNode->point.z);
        } else {
            printf("Point (%d, %d, %d) is maximal.\n", currentPoint.x, currentPoint.y, currentPoint.z);
            avlRoot = insert(avlRoot, currentPoint);  // Insert into AVL tree if not dominated
        }
    }
}

// In-order traversal of AVL tree to check if it's monotone in y
int isMonotoneInY(AVLNode* root, int* prevY) {
    if (root == NULL) return 1;

    if (!isMonotoneInY(root->left, prevY)) return 0;

    if (root->point.y < *prevY) return 0;
    *prevY = root->point.y;

    return isMonotoneInY(root->right, prevY);
}

// Generate random points
void generateRandomPoints(Point points[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
        points[i].z = rand() % 100;
    }
}

int main() {
    int numPoints = 10;
    Point points[MAX_POINTS];
    
    // Test with random points
    generateRandomPoints(points, numPoints);

    findMaximalPoints(points, numPoints);

    // Check if the AVL tree (staircase) is monotone in y-coordinate
    int prevY = -1;
    AVLNode* avlRoot = NULL; // Reuse the AVL tree from findMaximalPoints for verification
    if (isMonotoneInY(avlRoot, &prevY)) {
        printf("The staircase is monotone in the y-coordinate.\n");
    } else {
        printf("The staircase is not monotone in the y-coordinate.\n");
    }

    printf("Total AVL tree operations: %d\n", operations);

    return 0;
}
