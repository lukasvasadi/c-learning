#include <stdio.h>
#include <stdlib.h>

int *allocateIntArray(int);
int **allocateIntStarArray(int);

int main(void)
{
    int i, j;
    int length, width;
    int **temps;

    // query the length and width of the zone
    scanf("%d", &length);
    scanf("%d", &width);

    temps = allocateIntStarArray(width);

    for (i = 0; i < width; i++)
    {
        temps[i] = allocateIntArray(length);
        for (j = 0; j < length; j++)
        {
            scanf("%d", &temps[i][j]);
        }
    }

    // print visual of fire/risk zones
    for (i = 0; i < width; i++)
    {
        for (j = 0; j < length; j++)
        {
            if (temps[i][j] > 1000)
                printf("[X]");
            else if (temps[i][j] >= 100 && temps[i][j] <= 1000)
                printf("[*]");
            else
                printf("[ ]");
        }
        printf("\n");
    }

    // free all memory usage
    for (i = 0; i < width; i++)
    {
        free(temps[i]);
    }
    free(temps);

    return 0;
}

int *allocateIntArray(int num)
{
    int *ptr = (int *)malloc(num * sizeof(int));
    return ptr;
}

int **allocateIntStarArray(int num)
{
    int **ptr = (int **)malloc(num * sizeof(int *));
    return ptr;
}
