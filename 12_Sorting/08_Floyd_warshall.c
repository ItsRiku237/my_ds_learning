#include <stdio.h>
#define INF 999
#define MAX 10

/*Core formula:
    distance(i → j) = min(
    direct path,
    path through k
*/
//All-Pairs Shortest Path
int main()
{
    int n;
    int dist[MAX][MAX];

    printf("Enter the number of vertices :");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &dist[i][j]);
            // Replace no edge with INF [No connection = infinite distance]
            if (i != j && dist[i][j] == 0)
            {
                dist[i][j] = INF;
            }
        }
    }

    // Outer loop (k) => Try each node as intermediate
    for (int k = 0; k < n; k++)
    {
        // Middle loop (i) => Starting node
        for (int i = 0; i < n; i++)
        {
            // Inner loop (j) => Destination node
            for (int j = 0; j < n; j++)
            {
                //Check: Is path i → k → j shorter than i → j ?
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    //IF YES then Update shortest path
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && dist[i][j] == 0)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}