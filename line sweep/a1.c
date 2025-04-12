#include <stdio.h>
#include <stdlib.h>

//structure point for the points formatted as (x,y,z)
typedef struct {
    int x, y, z;
} Point;

// Use a binary search tree to represent a staircase 
typedef struct Node {
    Point point;
    struct Node *left, *right;
} Node;

// creating a new BST 
Node* newNode(Point p) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->point = p;
    node->left = node->right = NULL;
    return node;
}

// insertion function on BST 
// BST is sorted by the y coordinates (ordering of the tree)
Node* insert(Node* root, Point p) {
    if (root == NULL) return newNode(p);
    
    if (p.y > root->point.y)
        root->left = insert(root->left, p);
    else
        root->right = insert(root->right, p);
    
    return root;
}

// check if a point is dominated by the current staircase 
int isDominated(Node* root, Point p) {
    while (root != NULL) {
        // check if points have different x-values before checking dominance
        if (root->point.x != p.x && root->point.y > p.y && root->point.z > p.z)
            return 1;  // point is below staircase
        
        // traverse the BST based on the y-value
        if (p.y > root->point.y)
            root = root->left;
        else
            root = root->right;
    }
    return 0;  // point is not dominated by staircase, so we should add it to BST
}

// Collect the maximal points in an array for later sorting and monotonicity check
void collectMaximalPoints(Node* root, Point* maximalPoints, int* count) {
    if (root != NULL) {
        collectMaximalPoints(root->left, maximalPoints, count);
        maximalPoints[(*count)++] = root->point;
        collectMaximalPoints(root->right, maximalPoints, count);
    }
}

// compare function for sorting points by x-value in descending order
int compareX(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p2->x - p1->x);  // descending order
}

// check monotonicity of y and z after sorting by x
int checkMonotonicity(Point* maximalPoints, int count) {
    for (int i = 1; i < count; i++) {
        if (maximalPoints[i].y < maximalPoints[i - 1].y || maximalPoints[i].z < maximalPoints[i - 1].z) {
            return 0;  // Monotonicity violated
        }
    }
    return 1;  // Monotonic
}

// plane sweep and find maximal points
void findMaximalPoints(Point points[], int n) {
    // use quicksort to sort points by x in descending order (nlogn time)
    qsort(points, n, sizeof(Point), compareX);

    // initialise BST to store the current staircase (maximal points in the y-z plane)
    Node* staircase = NULL;

    // sweep through the points in descending order of x
    for (int i = 0; i < n; i++) {
        if (!isDominated(staircase, points[i])) {
            // if a point is NOT dominated by points in staircase, add it to BST 
            staircase = insert(staircase, points[i]);
        }
    }

    // Collect maximal points from the staircase
    Point maximalPoints[n];
    int count = 0;
    collectMaximalPoints(staircase, maximalPoints, &count);

    // Sort maximal points by x-values again (just in case)
    qsort(maximalPoints, count, sizeof(Point), compareX);

    // Print maximal points
    printf("Maximal Points:\n");
    for (int i = 0; i < count; i++) {
        printf("(%d, %d, %d)\n", maximalPoints[i].x, maximalPoints[i].y, maximalPoints[i].z);
    }

    // Check for monotonicity in the staircase
    if (checkMonotonicity(maximalPoints, count)) {
        printf("The staircase is monotone.\n");
    } else {
        printf("The staircase is NOT monotone.\n");
    }
}

int main() {
    // Example input points
    Point points[] = {
        {1, 2, 3}, {4, 5, 6}, {4, 2, 1}, {3, 5, 6}, {2, 6, 5}, {5, 3, 8}
    };
    int n = sizeof(points) / sizeof(points[0]);

    // Find and output the maximal points
    findMaximalPoints(points, n);

    return 0;
}



