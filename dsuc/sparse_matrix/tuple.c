#include <stdio.h>

void create_sparsh(int rows, int cols, int mat[rows][cols])
{
    int size = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] != 0)
            {
                size++;
            }
        }
    }

    int k = 0;
    int sparsh[size][3];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] != 0)
            {
                sparsh[k][0] = i;
                sparsh[k][1] = j;
                sparsh[k][2] = mat[i][j];
                k++;
            }
        }
    }

    printf("The sparsh matrix is: ");
    printf("\nRows Coloumns Element\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d %d %d\n", sparsh[i][0], sparsh[i][1], sparsh[i][2]);
    }
}

int main()
{
    int mat[3][3];

    printf("Enter the elements as per the 3X3 matrix: ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Your entered matrix is: ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d", mat[i][j]);
        }
    }

    create_sparsh(3, 3, mat);
}