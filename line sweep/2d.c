#include <stdio.h>
#include <stdlib.h>

// create structure to hold the points 
typedef struct {
    int x, y;
} Point;

// to compare the values of 2 points 
int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->x - p2->x);
}

Point* findResult(Point points[], int n, int *resultSize) {
    
    qsort(points, n, sizeof(Point), compare); //takes (nlogn) time and uses our comparison function

    // memory allocation for result array 
    Point *result = (Point *)malloc(n * sizeof(Point));
    
    // set point with maximum x value as the maximal point and then compare backwards 
    int idx = 0;
    Point maxPoint = points[n - 1]; 
    result[idx++] = maxPoint;
    
    // iterate backwards in the array and check the y coordinates 
    int maxY = maxPoint.y;

    
    for (int i = n - 2; i >= 0; i--) {
        // If the x value is the same as maxPoint, add it to the result
        if (points[i].x == maxPoint.x) {
            result[idx++] = points[i];
            // Set maxPoint to the one with greater y value
            if (points[i].y > maxY) {
                maxPoint = points[i];
                maxY = points[i].y;
            }
        }
        // If the x value is different, add the point only if y >= maxY
        else if (points[i].y >= maxY) {
            result[idx++] = points[i];
            maxPoint = points[i];  // Set this point as the new max point
            maxY = points[i].y;    // Update maxY
        }
    }

    *resultSize = idx;  
    return result;
}

int main() {
    // Example input
    Point points[] = {{1, 2}, {2, 5}, {3, 1},{7, 10}, {4, 6}, {5, 3},{5, 4},{5, 1}};
    int n = sizeof(points) / sizeof(points[0]);

    // Find result
    int resultSize;
    Point *result = findResult(points, n, &resultSize);

    // Print the result
    printf("Result:\n");
    for (int i = resultSize - 1; i >= 0; i--) {  // Reverse print the result array
        printf("(%d, %d)\n", result[i].x, result[i].y);
    }

    // Free the allocated memory
    free(result);

    return 0;
}
