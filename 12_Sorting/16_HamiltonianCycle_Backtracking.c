#include <stdio.h>

#define MAX 20

/*
========================================================
HAMILTONIAN CYCLE USING BACKTRACKING
========================================================

GOAL:
Visit every vertex exactly once
and return back to starting vertex.

--------------------------------------------------------
Example Graph
--------------------------------------------------------

n = 4

Adjacency Matrix:

    0 1 2 3
0   0 1 1 1
1   1 0 1 0
2   1 1 0 1
3   1 0 1 0

Meaning:
0 connected to 1,2,3
1 connected to 0,2
2 connected to 0,1,3
3 connected to 0,2

Possible Hamiltonian Cycle:

0 -> 1 -> 2 -> 3 -> 0

========================================================
*/

int graph[MAX][MAX];   // stores graph
int path[MAX];         // stores current path
int n;                 // number of vertices

/*
========================================================
isSafe(v,pos)
========================================================

Checks whether vertex v can be placed at path[pos]

Conditions:
1. v must be connected to previous vertex
2. v must not already be used

Returns:
1 -> safe
0 -> not safe
*/
int isSafe(int v, int pos)
{
    /*
    Check connection with previous vertex

    Example:
    current path:
    0 1 _ _

    now trying to place 3 at pos=2

    check:
    graph[1][3]

    if 0 => not connected
    */
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    /*
    Check whether vertex already exists in path

    Example:
    path = 0 1 2 _

    trying to place 1 again

    not allowed
    */
    for (int i = 0; i < pos; i++)
    {
        if (path[i] == v)
            return 0;
    }

    return 1;
}

/*
========================================================
printSolution()
========================================================

Print Hamiltonian cycle

Example output:
0 1 2 3 0
*/
void printSolution()
{
    for (int i = 0; i < n; i++)
        printf("%d ", path[i]);

    /*
    print starting vertex again
    because cycle returns to start
    */
    printf("%d\n", path[0]);
}

/*
========================================================
hamCycleUtil(pos)
========================================================

Recursive backtracking function

pos = current position in path

Example:

path = 0 _ _ _

pos=1

Need to fill path[1]
*/
void hamCycleUtil(int pos)
{
    /*
    BASE CASE

    If all vertices placed
    */
    if (pos == n)
    {
        /*
        Check last vertex connects back to start

        Example:
        0 1 2 3

        check:
        3 -> 0 exists?
        */
        if (graph[path[pos - 1]][path[0]] == 1)
        {
            printSolution();
        }
        return;
    }

    /*
    Try all vertices except 0
    because 0 already fixed as start
    */
    for (int v = 1; v < n; v++)
    {
        /*
        If vertex safe
        */
        if (isSafe(v, pos))
        {
            /*
            Place vertex
            */
            path[pos] = v;

            /*
            Recur for next position
            */
            hamCycleUtil(pos + 1);

            /*
            BACKTRACK

            Remove vertex
            */
            path[pos] = -1;
        }
    }
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    /*
    Initialize path as empty
    */
    for (int i = 0; i < n; i++)
        path[i] = -1;

    /*
    Start from vertex 0
    */
    path[0] = 0;

    printf("Hamiltonian Cycles are:\n");

    /*
    Start filling from position 1
    because position 0 already filled
    */
    hamCycleUtil(1);

    return 0;
}

/*
========================================================
FULL DRY RUN
========================================================

Input:

4

0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0

--------------------------------------------------------

Initially:

path = [0,-1,-1,-1]

call:

hamCycleUtil(1)

--------------------------------------------------------

pos=1

Try vertices:

v=1

isSafe(1,1)

check:
graph[path[0]][1]
graph[0][1]=1

connected

check duplicate:
path[0]=0

1 not used

safe

place:

path=[0,1,-1,-1]

call:
hamCycleUtil(2)

--------------------------------------------------------

pos=2

Try:

v=1

already used -> reject

v=2

check:
graph[1][2]=1

safe

place:

path=[0,1,2,-1]

call:
hamCycleUtil(3)

--------------------------------------------------------

pos=3

Try:

v=1 used reject

v=2 used reject

v=3

check:
graph[2][3]=1

safe

place:

path=[0,1,2,3]

call:
hamCycleUtil(4)

--------------------------------------------------------

pos=4 == n

all vertices used

check last->first

graph[3][0]=1

YES

print:

0 1 2 3 0

--------------------------------------------------------

Backtrack:

path[3]=-1

return

try other vertices...

========================================================

BACKTRACKING IDEA
========================================================

Choose vertex
↓
Check safe?
↓
YES -> place it
↓
recurse next position
↓
if fail -> remove vertex

========================================================

MEMORY TRICK
========================================================

isSafe:
1. connected?
2. already used?

hamCycleUtil:
1. if all filled check cycle
2. try all vertices
3. place
4. recurse
5. backtrack

========================================================
*/



/*Design and implement a program to find all Hamiltonian Cycles in a connected
undirected Graph G of n vertices using backtracking principle.*/


/*#include <stdio.h>
#define MAX 20
int graph[MAX][MAX];
int path[MAX];
int n;
int isSafe(int v, int pos)
{
    if (graph[path[pos - 1]][v] == 0)
        return 0;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;
            return 1;
}
void printSolution()
{
    for (int i = 0; i < n; i++)
        printf("%d ", path[i]);

    printf("%d\n", path[0]); 
}

void hamCycleUtil(int pos)
{
   
    if (pos == n)
    {
    
        if (graph[path[pos - 1]][path[0]] == 1)
        {
            printSolution();
        }
        return;
    }

    for (int v = 1; v < n; v++)
    {
        if (isSafe(v, pos))
        {
            path[pos] = v;

            hamCycleUtil(pos + 1);

            path[pos] = -1;
        }
    }
}
int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    for (int i = 0; i < n; i++)
        path[i] = -1;
      path[0] = 0;
printf("Hamiltonian Cycles are:\n");
    hamCycleUtil(1); return 0;
}*/