/*Write a program to find shortest paths to other
vertices from a given vertex in a weighted connected graph, using Dijkstra's algorithm.*/
//It finds: Shortest distance from one source vertex → all other vertices
#include <stdio.h>

#define MAX 10
#define INF 999

int main()
{
    /*cost[][] =>	Distance between nodes
    dist[]	=> Shortest distance from source
    visited[]	=> Track visited nodes*/
    int cost[MAX][MAX], dist[MAX], visited[MAX], n, source, min, u;

    /*Input graph
        Take n
        Take cost matrix
        Replace 0 with INF*/
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    printf("Enter cost matrix : ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
            {
                cost[i][j] = INF;
            }
        }
    }
    printf("Enter source vertex : ");
    scanf("%d", &source);

    /*Initialize
    Set dist[] from source
    Mark visited[] = 0
    Set source = visited*/
    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }
    dist[source] = 0;
    visited[source] = 1;


    /*Repeat n-1 times
        Find minimum distance node
        Mark it visited
        Update all neighbors*/
    for (int i = 1; i < n; i++)
    {
        min = INF;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("\nShortest distances from vertex %d :\n", source);
    for (int i = 0; i < n; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}


//Example (5 Nodes) [ From Chat Gpt]

/*Let nodes = 0,1,2,3,4
Cost Matrix:
    0   1   2   3   4
0 [ 0   10  3   0   0 ]
1 [ 0   0   1   2   0 ]
2 [ 0   4   0   8   2 ]
3 [ 0   0   0   0   7 ]
4 [ 0   0   0   9   0 ] 

Replace 0 (no edge) with INF:

    0   1   2   3   4
0 [ 0  10   3  INF INF ]
1 [INF  0   1   2  INF ]
2 [INF  4   0   8   2 ]
3 [INF INF INF  0   7 ]
4 [INF INF INF  9   0 ]

2. Source Node = 0

3. Initialization
dist[]    = [0, 10, 3, INF, INF]
visited[] = [1,  0, 0,  0,   0]
Source (0) is visited

4. Iteration 1 
Find minimum unvisited
Check all:
Node	dist	visited	Action
0	      0	    visited	ignore
1	    10	    no	    min=10
2	    3	    no	    min=3 ✅
3	    INF	    no	    ignore
4	    INF	    no	    ignore

Loop:
j	dist[j]	visited	min	    u
0	0	    visited	ignore	
1	10	    no	    10	    1
2	3	    no	    3	    2 ✅
3	INF	    no	    ignore	
4	INF	    no	    ignore

u = 2
Mark visited : visited[2] = 1

Update distances
From node 2:
To 1: 3 + 4 = 7 < 10 → update
To 3: 3 + 8 = 11 → update
To 4: 3 + 2 = 5 → update
Updated:
dist = [0, 7, 3, 11, 5]
visited = [1, 0, 1, 0, 0]

5. Iteration 2
Find minimum
Node	dist	visited	Action
1	    7	    no	    min=7
3	    11	    no	    ignore
4	    5	    no	    min=5 ✅

u = 4

Mark visited : visited[4] = 1
Update distances: From node 4:
To 3: 5 + 9 = 14 > 11 → no update
Updated:
dist = [0, 7, 3, 11, 5]
visited = [1, 0, 1, 0, 1]

6. Iteration 3 
Find minimum
Node	dist	visited	Action
1	    7	    no  	min=7 ✅
3	    11	    no  	ignore

u = 1
Mark visited
visited[1] = 1 : Update distances

From node 1:
To 3: 7 + 2 = 9 < 11 → update
Updated:
dist = [0, 7, 3, 9, 5]
visited = [1, 1, 1, 0, 1]

7. Iteration 4
Find minimum
Node	dist	visited	Action
3	    9       no	    min=9 ✅

u = 3

Mark visited
visited[3] = 1
No more updates

8. Final Answer 
Shortest distances from node 0:

0 → 0 = 0
0 → 1 = 7
0 → 2 = 3
0 → 3 = 9
0 → 4 = 5

*/