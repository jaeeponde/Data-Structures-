#include <stdio.h>
#include <stdlib.h>

#define V 4
#define INF 99999

void printSolution(int dist[][V], int next[][V])
{
    printf("The following matrix shows the shortest distances and paths:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else {
                printf("(%d, %d) %7d  ", i, j, dist[i][j]);
                printf("Path: %d ", i);
                int k = i;
                while (k != j) {
                    printf("-> %d ", next[k][j]);
                    k = next[k][j];
                }
                printf("\n");
            }
        }
        printf("\n");
    }
}

void floydWarshall(int dist[][V])
{
    int next[V][V];

    // Initialize next matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j || dist[i][j] == INF)
                next[i][j] = -1;
            else
                next[i][j] = j;
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    // Print the shortest distance matrix along with the path information
    printSolution(dist, next);
}

// driver's code
int main()
{
    int graph[V][V] = { {0, 5, INF, 10},
                        {INF, 0, 3, INF},
                        {INF, INF, 0, 1},
                        {INF, INF, INF, 0} };

    // Function call
    floydWarshall(graph);
    return 0;
}
