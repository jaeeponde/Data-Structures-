#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 9

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) { //if vertex has no parent, the oly path to the vertex is from itself eg) source vertex
        printf("%d", j);
        return;
    }
    printPath(parent, parent[j]); //recursively prints path to the parent of the parent thus leading to the whole path 
    printf(" -> %d", j);
}

void printSolution(int dist[], int parent[]) {
    printf("Vertex \t\t Distance from Source \t\t Path\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t\t\t %d \t\t\t\t ", i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int parent[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet); 
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; //update parent of v when it becomes sure 
            }
        }
    }

    printSolution(dist, parent);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    
    dijkstra(graph, 0);

    return 0;
}
