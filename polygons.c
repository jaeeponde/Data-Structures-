#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>

//creating a structure to handle 2D points 
typedef struct {
    double x, y;
} Point;

//euclidean distance between points
double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

//function that recursively finds diagonals and prints it 
void printDiagonals(int i, int j, int n, int** split, Point* vertices, double* totalDiagonalLength) {
    if (split[i][j] == -1) return;

    int k = split[i][j];
    if (!(j == i + 1 || (i == 0 && j == n - 1))) {
        double diag_length = distance(vertices[i], vertices[j]);
        printf("Diagonal: (%.2f, %.2f) -> (%.2f, %.2f) Length: %.2f\n",
               vertices[i].x, vertices[i].y, vertices[j].x, vertices[j].y, diag_length);
        *totalDiagonalLength += diag_length;
    }

    // Recursively process the subproblems
    printDiagonals(i, k, n, split, vertices, totalDiagonalLength);
    printDiagonals(k, j, n, split, vertices, totalDiagonalLength);
}

//dp function
void triangulatePolygon(Point* vertices, int n) {
    double** dp = (double**)malloc(n * sizeof(double*));
    int** split = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (double*)calloc(n, sizeof(double));
        split[i] = (int*)calloc(n, sizeof(int));
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0.0;
            split[i][j] = -1; //initialising all costs to 0 and all diagonals to -1 
        }
    }

    //using recursion over subpolygons
    for (int len = 2; len < n; len++) {
        for (int i = 0; i + len < n; i++) {
            int j = i + len;
            dp[i][j] = INFINITY;
            for (int k = i + 1; k < j; k++) {
                double cost = dp[i][k] + dp[k][j] + distance(vertices[i], vertices[j]);
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    //find all diagonals recursively 
    double totalDiagonalLength = 0.0;
    printDiagonals(0, n - 1, n, split, vertices, &totalDiagonalLength);

    printf("Minimum Total Length of Diagonals: %.2f\n", totalDiagonalLength);

    //free memory 
    for (int i = 0; i < n; i++) {
        free(dp[i]);
        free(split[i]);
    }
    free(dp);
    free(split);
}

//file reading function
void processPolygons(const char* filename) {
    FILE* infile = fopen(filename, "r");
    if (!infile) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    int polygonCount = 1;

    while (fgets(line, sizeof(line), infile)) {
        Point vertices[100]; // Maximum of 100 vertices per polygon
        int vertexCount = 0;

        char* token = strtok(line, " ");
        while (token) {
            Point p;
            if (sscanf(token, "%lf,%lf", &p.x, &p.y) == 2) {
                vertices[vertexCount++] = p;
            }
            token = strtok(NULL, " ");
        }

        if (vertexCount >= 3) {
            printf("Processing Polygon %d\n", polygonCount++);
            triangulatePolygon(vertices, vertexCount);
        } else {
            fprintf(stderr, "Polygon must have at least 3 vertices.\n");
        }
    }

    fclose(infile);
}

int main() {
    processPolygons("input.txt"); //enter input file here 
    return 0;
}
