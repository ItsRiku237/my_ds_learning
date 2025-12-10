#include <stdio.h>
// WAP to emplement a sparse matrix of dimension
// given by the provided by the user in the sparse matrix.
// Compact matrix
int main()
{
    int row, col;

    printf("Enter number of row : ");
    scanf("%d", &row);
    printf("Enter number of column : ");
    scanf("%d", &col);
    int matrix[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter element %d%d : ",i,j);
            scanf("%d", &matrix[i][j]);
        }
    }
    int zeroCount = 0;
    int nonZeroCount = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                zeroCount++;
            }
            else
            {
                nonZeroCount++;
            }
        }
    }
    if (zeroCount > nonZeroCount)
    {
        printf("The matrix is a sparse matrix.\n");
    }
    else
    {
        printf("The matrix is not a sparse matrix.\n");
    }
    printf("\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != 0)
            {
                printf("%d      ", matrix[i][j]);
            }
        }
    }
        printf("\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != 0)
            {
                printf("%d      ", i);
            }
        }
    }
        printf("\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != 0)
            {
                printf("%d      ", j);
            }
        }
    }
    return 0;
}