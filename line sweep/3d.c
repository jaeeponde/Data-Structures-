#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y, z;
} Point;

// Comparison function for qsort to sort by x coordinate in reverse order
int compareReverse(const void* a, const void* b) {
    return ((Point*)b)->x - ((Point*)a)->x; // Reverse order
}

// Function to check if a point dominates another
int dominates(Point a, Point b) {
    return a.y > b.y && a.z > b.z;
}

// Function to find maximal points
void findMaximalPoints(Point* points, int length) {
    // Sort points by x-coordinate in reverse order
    qsort(points, length, sizeof(Point), compareReverse);

    Point* staircase = malloc(length * sizeof(Point));
    int stairLength = 0;

    Point* maximal = malloc(length * sizeof(Point));
    int maxLength = 0;

    staircase[stairLength++] = points[0];
    maximal[maxLength++] = points[0];

    int xmax = points[0].x;

    for (int i = 1; i < length; ) {
        Point current = points[i];
        if (current.x == xmax) {
            maximal[maxLength++] = current;
            i++;
            printf("Point (%d, %d, %d) is maximal\n",current.x, current.y, current.z);
        } else {
            int flag = 0;

            for (int j = 0; j < stairLength; j++) {
                if (dominates(staircase[j], current)) {
                    flag++;
                    printf("Point (%d, %d, %d) is dominated by (%d, %d, %d)\n",
                           current.x, current.y, current.z,
                           staircase[j].x, staircase[j].y, staircase[j].z);
                }
                if (dominates(current, staircase[j])) {
                    staircase[j] = staircase[--stairLength]; // Remove dominated point
                    j--; // Stay at the same index since we just replaced the current element
                }
            }

            if (flag == 0) {
                printf("Point (%d, %d, %d) is maximal\n",current.x, current.y, current.z);
                staircase[stairLength++] = current;
                maximal[maxLength++] = current;
                xmax = current.x;
            }
            i++;
        }
    }

    printf("Maximal points:\n");
    for (int k = 0; k < maxLength; k++) {
        printf("(%d, %d, %d)\n", maximal[k].x, maximal[k].y, maximal[k].z);
    }

    free(staircase);
    free(maximal);
}

int main() {
    int length = 10; // Number of random points
    Point* points = malloc(length * sizeof(Point));

    // Seed for random number generation
    srand(time(NULL));

    // Generate random points in 3D space
    for (int i = 0; i < length; i++) {
        points[i].x = rand() % 10; // Random x between 0 and 9
        points[i].y = rand() % 10; // Random y between 0 and 9
        points[i].z = rand() % 10; // Random z between 0 and 9
    }

    // Print generated points
    printf("Generated points:\n");
    for (int i = 0; i < length; i++) {
        printf("(%d, %d, %d)\n", points[i].x, points[i].y, points[i].z);
    }

    findMaximalPoints(points, length);

    free(points);
    return 0;
}
