#include <stdio.h>

int main()
{
    int row = 3, col = 3;

    int matrix[row][col];

    if (row != col)
    {
        printf("In-place transpose requires a square matrix.\n");
        return 0;
    }
    int x = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = x;
            x++;
        }
    }

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         if ((i+j)%2==0)
    //         {
    //             matrix[i][j]=matrix[i][j]+1;
    //         }

    //     }
    // }

    int y = 1;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if ((i + j) % 2 == 0)
            {
                matrix[i][j] = y;
                y += 2;
            }
        }
    }
    printf("The final matrix is :\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
