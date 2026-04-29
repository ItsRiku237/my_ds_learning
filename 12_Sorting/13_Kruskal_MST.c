#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Edge {
    int u, v, weight;
};
// starting node u
// ending node v
// cost weight


//Track connected components
int parent[MAX];


// Find root parent of node
int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}
// Suppose: 0 → 1 → 2
// Means:parent[0]=1
//         parent[1]=2
//         parent[2]=2
// Now: find(0)

// Check: parent[0] != 0
// Yes.
// So: find(parent[0])
// means: find(1)

// Again: find(2)
// Now: parent[2]==2
// Stop.

// Return 2.
// So: find(0)=2
// Meaning:Root of 0 is 2


//Connect two components
void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU] = rootV;
}
// Before: 0    1   Separate.

// After: unionSet(0,1)
// Now: 0 → 1 Connected.

// Why? -> After selecting edge, connect them.



//Used by qsort().
int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}


int main() {
    int V, E; //V = vertices , E = edges
    struct Edge edges[MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    //Sort all edges.
    //qsort(array, number_of_elements, size_of_one_element, compare_function);
    qsort(edges, E, sizeof(edges[0]), compare);
    
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }
    //Initially:  0 1 2 3   Everyone own parent.(Initially all separate.)

    int count = 0; //How many edges selected
    int cost = 0;// Total MST cost

    printf("\nEdges in MST:\n");

    //Stop when: count = V-1  Because MST needs V-1 edges.
    for (int i = 0; i < E && count < V - 1; i++) {
        //Take current edge.
        int u = edges[i].u;
        int v = edges[i].v;

        //Find roots/components
        int setU = find(u);
        int setV = find(v);

        if (setU != setV) {//Different components? YES → safe. (Not cycle)
            printf("%d -- %d == %d\n", u, v, edges[i].weight);
            cost += edges[i].weight;
            unionSet(u, v);//Connect components
            count++;
        }
    }

    if (count != V - 1) {
    printf("MST not possible. Graph is disconnected.\n");
    return 0;
}

    printf("\nMinimum Cost = %d\n", cost);

    return 0;
}