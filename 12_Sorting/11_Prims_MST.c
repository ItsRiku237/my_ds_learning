// Write a program to find Minimum Cost Spanning Tree of a 
// given connected undirected graph using Prim's algorithm
//MST(Minimum Spanning Tree)
#include <stdio.h>
#include <limits.h>
#define V 5  //number of vertices

// Connect all vertices with minimum total cost without forming a cycle.
//You want to connect 5 cities using roads such that: All cities are connected , Total cost is minimum

//Find the unvisited node with smallest key value
int minKey(int key[], int visited[])
{
    int min = INT_MAX, min_index; // INT_MAX → infinite value

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == 0 && key[v] < min)
        { //Update minimum node
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    int i;
    printf("Edge \tWeight\n");
    for (i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}
void primMST(int graph[V][V])
{
    int parent[V];  // Stores MST structure
    int key[V];     // Minimum cost to connect node
    int visited[V]; // Whether node is included

    int i, count, u, v;

    // All nodes have infinite cost
    // All are unvisited
    for (i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    //Node 0 is starting point
    key[0] = 0;
    parent[0] = -1;


    for (count = 0; count < V - 1; count++)
    {
        u = minKey(key, visited);// Pick minimum node [Select nearest node]
        visited[u] = 1; //Mark visited
        for (v = 0; v < V; v++)
        {
            //Edge exists , Not visited , Smaller weight
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;//Best parent
                key[v] = graph[u][v];//Minimum cost
            }
        }
    }

    printMST(parent, graph);
}
int main()
{
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    primMST(graph);

    return 0;
}