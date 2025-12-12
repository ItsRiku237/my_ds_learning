#include <stdio.h>

int main()
{
    int row, col;

    scanf("%d", &row);
    scanf("%d", &col);
    int matrix[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int flag = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i < j)
            {
                if (matrix[i][j] != 0)
                {
                    flag = 0;
                }
            }
        }
    }

    if (flag)
    {
        printf("The matrix is a Lower Triangular matrix .\n");
    }
    else
    {
        printf("The matrix is not a Lower Triangular matrix .\n");
    }
    return 0;
}
