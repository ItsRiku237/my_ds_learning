#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MAX 15
#define INF INT_MAX

int n; // Stores number of cities.
int cost[MAX][MAX]; // Stores matrix (weight or cost from city 0 to 1) cost[0][1]=10
int dp[1 << MAX][MAX]; // minimum cost to reach city after visiting cities in mask dp[mask][city] )

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp() {
    int mask, u, v;

    // Initialize DP table
    // (1 << n) means 2^n  possible subsets.
    for (mask = 0; mask < (1 << n); mask++)
        for (u = 0; u < n; u++)
            dp[mask][u] = INF;

    // Starting from city 0
    dp[1][0] = 0;

    // Iterate over all subsets of cities
    for (mask = 1; mask < (1 << n); mask++) {
        for (u = 0; u < n; u++) {
            if (mask & (1 << u)) { // if city u is visited  [ & Bitwise AND Operator]
                for (v = 0; v < n; v++) {
                    if (!(mask & (1 << v))) { // if city NOT visited
                        int newMask = mask | (1 << v); //mark city as visited or add city v into visited set , '|' symbol represents the Bitwise OR operator.
                        dp[newMask][v] = min(dp[newMask][v],
                                             dp[mask][u] + cost[u][v]);
                                             //Minimum cost to reach city v after visiting cities in newMask,Current cost + cost to go to next city
                    }
                }
            }
        }
    }

    // Final step: return to starting city
    int ans = INF;
    for (u = 1; u < n; u++) {
        ans = min(ans, dp[(1 << n) - 1][u] + cost[u][0]);
    }//cost after visiting all cities and ending at u  +  Return from city u to city 0.

    return ans;
}

int main() {
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int result = tsp();
    printf("Minimum Travelling Cost: %d\n", result);

    return 0;
}






/*
#include <stdio.h>
#include <limits.h>

#define MAX 15
#define INF INT_MAX

/*
===========================================================
TRAVELLING SALESMAN PROBLEM (TSP) USING DYNAMIC PROGRAMMING
===========================================================

GOAL:
Start from city 0
Visit all cities exactly once
Return to city 0
Find minimum total travelling cost

-----------------------------------------------------------
EXAMPLE INPUT
-----------------------------------------------------------

n = 4

Cost Matrix:

      0   1   2   3
0     0  10  15  20
1    10   0  35  25
2    15  35   0  30
3    20  25  30   0

Meaning:
0 -> 1 = 10
0 -> 2 = 15
0 -> 3 = 20
etc.

-----------------------------------------------------------
MASK CONCEPT
-----------------------------------------------------------

Mask stores visited cities in binary.

For n=4:

0000 = no city visited
0001 = city 0 visited
0011 = city 0,1 visited
0101 = city 0,2 visited
1111 = all visited

(1 << n) = 2^n

If n=4:
1<<4 = 16

So masks go:
0 to 15

0000 to 1111

-----------------------------------------------------------
DP MEANING
-----------------------------------------------------------

dp[mask][city]

means:

Minimum cost to reach "city"
after visiting cities in "mask"

Example:

dp[5][2]

5 = 0101

Means:
visited city 0 and 2

Current city = 2

So:

Minimum cost to reach city 2
after visiting {0,2}

===========================================================


int n;
int cost[MAX][MAX];
int dp[1 << MAX][MAX];


// min(a,b)

// returns smaller value

// Example:
// min(10,5) => 5

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int tsp()
{
    int mask, u, v;

    // 
    // STEP 1: Initialize all dp values as INF

    // Means:
    // initially all paths unknown
    

    for (mask = 0; mask < (1 << n); mask++)
    {
        for (u = 0; u < n; u++)
        {
            dp[mask][u] = INF;
        }
    }

    
    // STEP 2: Start from city 0

    // mask = 0001
    // only city 0 visited

    // current city = 0
    // cost = 0
    

    dp[1][0] = 0;

    
    // STEP 3: Try all subsets
    

    for (mask = 1; mask < (1 << n); mask++)
    {
        for (u = 0; u < n; u++)
        {
            
            // Check if city u is visited

            // Example:

            // mask = 0101
            // u=2

            // 0101 & 0100 = 0100

            // true
            
            if (mask & (1 << u))
            {
                for (v = 0; v < n; v++)
                {
                    
                    // Check if city v NOT visited

                    // Example:

                    // mask=0001
                    // v=1

                    // 0001 & 0010 = 0000

                    // not visited
                    
                    if (!(mask & (1 << v)))
                    {
                        
                        // Add city v into mask

                        // Example:

                        // mask = 0001
                        // visit city 2

                        // 0001 | 0100 = 0101
                        
                        int newMask = mask | (1 << v);

                        
                        // Update minimum cost

                        // Example:

                        // dp[1][0]=0

                        // cost[0][2]=15

                        // new cost:
                        // 0+15 =15

                        // dp[5][2]=15
                        

                        dp[newMask][v] =
                            min(dp[newMask][v],
                                dp[mask][u] + cost[u][v]);
                    }
                }
            }
        }
    }

    /*
    // STEP 4: Return back to city 0

    // all visited mask:

    // n=4

    // 1<<4 =16

    // 16-1 =15

    // 15 =1111

    // all cities visited
    

    int ans = INF;

    for (u = 1; u < n; u++)
    {
        /*
        // Example:

        // dp[1111][2]=65

        // return cost:
        // cost[2][0]=15

        // total=80
        

        ans = min(ans, dp[(1 << n) - 1][u] + cost[u][0]);
    }

    return ans;
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    int result = tsp();

    printf("Minimum Travelling Cost: %d\n", result);

    return 0;
}

/*
===========================================================
FULL DRY RUN
===========================================================

INPUT:

4

0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

-----------------------------------------------------------

START:

dp[1][0]=0

mask=0001

only city 0 visited

-----------------------------------------------------------

FROM CITY 0:

go to city1

0001 |0010 =0011

dp[3][1]=10

-----------------------------------------------------------

go to city2

0001 |0100 =0101

dp[5][2]=15

-----------------------------------------------------------

go to city3

0001 |1000 =1001

dp[9][3]=20

-----------------------------------------------------------

Continue similarly...

Finally:

all visited =1111

Try return to city0

Possible tours:

0->1->3->2->0 = 80
0->2->3->1->0 = 80
0->1->2->3->0 = 95

Minimum=80

OUTPUT:

Minimum Travelling Cost: 80

===========================================================
MEMORY TRICK
===========================================================

mask = visited cities

& = check visited

| = mark visited

dp[mask][city] = min cost

Flow:

Start
Visit city
Store cost
Visit next city
Return home
Answer

===========================================================
*/