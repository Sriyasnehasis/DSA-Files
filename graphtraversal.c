#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices
#define MAX 100

// Graph structure using an adjacency matrix
int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

// Add an edge to the graph
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // For undirected graph
}

// BFS Function
void BFS(int start, int n) {
    printf("Breadth-First Search (BFS):\n");
    front = rear = 0;
    queue[rear] = start;
    visited[start] = 1;

    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS Function
void DFS(int start, int n) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}

// Main Function
int main() {
    int n, edges, u, v, start;

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize the graph and visited arrays
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Input edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Input the starting vertex
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    // Perform BFS
    BFS(start, n);

    // Reset visited array for DFS
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform DFS
    printf("Depth-First Search (DFS):\n");
    DFS(start, n);
    printf("\n");

    return 0;
}
