// DFS algorithm in C

#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int v);

struct Graph {
  int numVertices;
  int* visited;

  // We need int** to store a two dimensional array.
  // Similary, we need struct node** to store an array of Linked lists
  struct node** adjLists;
};

// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
}

// DFS algo
void DFS(struct Graph* graph, int vertex, struct node** topolist) {
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex,topolist);
    }
  
  temp = temp->next;
  }
  struct node* latest = createNode(vertex);
  latest->next = *topolist;
  *topolist = latest;
}

void topologicalSort(struct Graph* graph) {
  int vertices = graph->numVertices;
  struct node* toposortlist = NULL;

  for (int i = 0; i < vertices; i++) {
    if (graph->visited[i] == 0) {
      DFS(graph, i, &toposortlist);
    }
  }

  printf("Topological sorted order is: ");
  struct node* temp;
  for (temp = toposortlist; temp != NULL; temp = temp->next) {
    printf("%d ", temp->vertex);
  }
  printf("\n");
}


int main() {
  struct Graph* graph = createGraph(7);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 5);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 5);
  addEdge(graph, 6, 5);
  addEdge(graph, 6, 3);
  addEdge(graph, 6, 4);


  topologicalSort(graph);

  return 0;
}