#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
    /*
    if(a>b)
        return a;
    else
      return b;
      */
}


int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];

    printf("Enter weights of items:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter profits of items:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int dp[n+1][W+1];

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(weight[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], profit[i-1] + dp[i-1][w - weight[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    printf("Maximum Profit = %d\n", dp[n][W]);

    return 0;
}

/*
LOOP STARTS :
// for(int i = 0; i <= n; i++) {
//         for(int w = 0; w <= W; w++) {

i = 0
if(i==0 || w==0)

Since i=0, all become 0.

Fill:

      0 1 2 3 4 5 6 7 8
0     0 0 0 0 0 0 0 0 0
1
2
3
4


Condition:
w=0
So: dp[1][0]=0



w=1
Check:
weight[0]<=1
means:1<=1

TRUE.
Now:
exclude = dp[0][1]=0
Include:
10 + dp[0][1-1]
=10 + dp[0][0]
=10+0
=10

Take max:
max(0,10)=10
So: dp[1][1]=10



w=2
Check: 1<=2
TRUE.

Exclude:
dp[0][2]=0

Include:10+dp[0][1]=10

max:10

So:
dp[1][2]=10
Same logic for all.

Final row1:

      0 1 2 3 4 5 6 7 8
0     0 0 0 0 0 0 0 0 0
1     0 10 10 10 10 10 10 10 10
2
3
4

w=1
Check: m3<=1

FALSE.
Cannot fit.

So: dp[2][1]=dp[1][1]=10
w=2

Check: 3<=2
FALSE.

Copy above:ndp[2][2]=10
w=3

Check:3<=3

TRUE.
Exclude:

dp[1][3]=10

Include:40+dp[1][0]=40

Take max:40

So:
dp[2][3]=40
w=4

Check: 3<=4
TRUE.

Exclude:
10

Include:
40+dp[1][1]
=40+10
=50

Take max:
50

So:
dp[2][4]=50

Continue similarly.

Final row2:

      0 1 2 3 4 5 6 7 8
0     0 0 0 0 0 0 0 0 0
1     0 10 10 10 10 10 10 10 10
2     0 10 10 40 50 50 50 50 50
3
4
i =3

Item3:

weight=4
profit=50
w=4

Check:
4<=4

TRUE.

Exclude:

dp[2][4]=50

Include:
50+dp[2][0]
=50

max:50

So:

dp[3][4]=50
w=5

Exclude:
50

Include:
50+dp[2][1]
=50+10
=60

max:60

So:dp[3][5]=60
Continue.

Final row3:

      0 1 2 3 4 5 6 7 8
0     0 0 0 0 0 0 0 0 0
1     0 10 10 10 10 10 10 10 10
2     0 10 10 40 50 50 50 50 50
3     0 10 10 40 50 60 60 90 100
4
i=4

Item4:

weight=5
profit=70
w=5

Check:

5<=5
TRUE.

Exclude:
dp[3][5]=60

Include:
70+dp[3][0]
=70

max:70

So:
dp[4][5]=70
w=8

Check:5<=8

TRUE.

Exclude:
dp[3][8]=100

Include:70+dp[3][3]=70+40=110

Take max:110

So:dp[4][8]=110

Final table:

      0 1 2 3 4 5 6 7 8
0     0 0 0 0 0 0 0 0 0
1     0 10 10 10 10 10 10 10 10
2     0 10 10 40 50 50 50 50 50
3     0 10 10 40 50 60 60 90 100
4     0 10 10 40 50 70 80 90 110

Answer:dp[4][8]=110

Maximum profit: 110
*/