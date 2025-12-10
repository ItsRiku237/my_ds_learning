// Sparse Matrix-1:
// WAP to check whether a given matrix is sparse or not.
// (Hint: A sparse matrix contains most elements which are zero with a few non elements)
#include <stdio.h>
int main()
{
    int row, col;
    int count = 0;
    printf("Enter number of row : ");
    scanf("%d", &row);
    printf("Enter number of column : ");
    scanf("%d", &col);
    int matrix[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter element : ");
            scanf("%d", &matrix[i][j]);
        }
    }
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         if (matrix[i][j]==0)
    //         {
    //             count++;
    //         }

    //     }

    // }
    // if (count>(row*col)/2)
    // {     printf("The matrix is a sparse matrix.\n");
    //     } else {
    //         printf("The matrix is not a sparse matrix.\n");
    //     }
    int zeroCount = 0, nonZeroCount = 0;

    // Count zero and non-zero elements
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
                zeroCount++;
            else
                nonZeroCount++;
        }
    }

    // Check if sparse
    if (zeroCount > nonZeroCount)
    {
        printf("The matrix is a sparse matrix.\n");
    }
    else
    {
        printf("The matrix is not a sparse matrix.\n");
    }
    return 0;
}
