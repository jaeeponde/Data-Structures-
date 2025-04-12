#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

typedef struct Point {
    double x, y;
} Point;

// Function to calculate the Euclidean distance between two points
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to compute the minimum triangulation cost using dynamic programming
double minTriangulation(Point *points, int n, int diagonals[n][n][2]) {
    if (n < 3) return 0; // No triangulation possible for fewer than 3 points

    double dp[n][n];

    // Initialize DP table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = (i + 1 == j) ? 0 : DBL_MAX; // Adjacent vertices have zero cost
            diagonals[i][j][0] = diagonals[i][j][1] = -1; // No diagonals initially
        }
    }

    // Fill DP table
    for (int length = 2; length < n; length++) { // Length of sub-polygon
        for (int i = 0; i < n - length; i++) {
            int j = i + length;
            for (int k = i + 1; k < j; k++) {
                double cost = dp[i][k] + dp[k][j] + distance(points[i], points[j]);
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    diagonals[i][j][0] = i;
                    diagonals[i][j][1] = j;
                }
            }
        }
    }

    return dp[0][n - 1];
}

// Function to parse a polygon from a line of input
int parsePolygon(const char *line, Point **points) {
    int count = 0;
    const char *ptr = line;
    char *end;
    Point *temp = NULL;

    while (*ptr) {
        double x = strtod(ptr, &end);
        if (ptr == end) break; // No valid conversion
        ptr = end;

        double y = strtod(ptr, &end);
        if (ptr == end) break; // No valid conversion
        ptr = end;

        temp = realloc(temp, (count + 1) * sizeof(Point));
        temp[count++] = (Point){x, y};
    }

    *points = temp;
    return count;
}

int main() {
    char filename[256];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file '%s'\n", filename);
        return 1;
    }

    char line[1024];
    int line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;
        Point *points = NULL;
        int num_points = parsePolygon(line, &points);
        if (num_points < 3) {
            printf("Polygon %d has less than 3 points. Skipping...\n", line_number);
            free(points);
            continue;
        }

        printf("\nProcessing Polygon %d:\n", line_number);

        int diagonals[num_points][num_points][2];
        double cost = minTriangulation(points, num_points, diagonals);
        printf("Minimum triangulation cost: %.2lf\n", cost);

        printf("Diagonals used:\n");
        for (int i = 0; i < num_points; i++) {
            for (int j = 0; j < num_points; j++) {
                if (diagonals[i][j][0] != -1) {
                    printf("(%d, %d) -> (%d, %d)\n", 
                           diagonals[i][j][0] + 1, diagonals[i][j][1] + 1, 
                           diagonals[i][j][1] + 1, i + 1);
                }
            }
        }

        free(points);
    }

    fclose(file);
    return 0;
}
