#include <stdio.h>

int main()
{
    int row, col;

    scanf("%d", &row);
    scanf("%d", &col);
    int matrix[row][col];

      if (row != col) {
        printf("In-place transpose requires a square matrix.\n");
        return 0;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int temp;
    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    printf("The transpose matrix is :\n");
    
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
