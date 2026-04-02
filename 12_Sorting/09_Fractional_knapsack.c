/*This uses Fractional Knapsack
Goal: Maximize profit within a limited bag capacity*/
// It use greedy algorithm (we choose the best immediate option and it lead to global optimum solution.)
#include <stdio.h>

//Write a program to solve Knapsack problem using Greedy method usualy solved useing fractional knapsack approach.
struct item
{
    int weight;
    int profit;
    float ratio;
};

void sort(struct item items[], int n)
{
    struct item temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (items[i].ratio < items[j].ratio)
            {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    float capacity, total_profit = 0;

    printf("Enter number of items : ");
    scanf("%d", &n);

    struct item items[n];

    /*for each item:
    if full item fits → take it
    else take fraction*/
    for (int i = 0; i < n; i++)
    {
        printf("Enter weight and profit of item %d : ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    sort(items, n);//Sort items in descending order of ratio [So we pick most profitable item first]

    printf("Enter Knapsack capacity : ");
    scanf("%f", &capacity);

    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= capacity)
        {
            capacity -= items[i].weight;
            total_profit += items[i].profit;
        }
        else
        {
            total_profit += items[i].profit * (capacity / items[i].weight);
            break;
        }
    }

    printf("Maximum profit : %.2f\n", total_profit);

    return 0;
}