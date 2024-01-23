#include "sandpiles.h"

int is_stable(int grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return (0);
        }
    }
    return (1);
}

void topple(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                grid[i][j] -= 4;

                if (i - 1 >= 0)
                    grid[i - 1][j]++;
                if (i + 1 < 3)
                    grid[i + 1][j]++;
                if (j - 1 >= 0)
                    grid[i][j - 1]++;
                if (j + 1 < 3)
                    grid[i][j + 1]++;
            }
        }
    }
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }
    while (!is_stable(grid1))
    {
        printf("=\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j)
                    printf(" ");
                printf("%d", grid1[i][j]);
            }
            printf("\n");
        }
        topple(grid1);
    }
}
