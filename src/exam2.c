#include <stdio.h>
int main(void)
{
    char name[51];
    int grades[30];
    int gradesSorted[30];
    int numStudents = 0;
    int i, j, swap;
    scanf("%d", &numStudents);
    for (i = 0; i < numStudents; i++)
    {
        scanf("%d", &grades[i]);     // append grade to array
        gradesSorted[i] = grades[i]; // initialize sorting array
    }
    // sort from largest to smallest using bubble method
    for (i = 0; i < numStudents - 1; i++)
    {
        for (j = 0; j < numStudents - 1; j++)
        {
            if (gradesSorted[j] < gradesSorted[j + 1])
            {
                swap = gradesSorted[j];
                gradesSorted[j] = gradesSorted[j + 1];
                gradesSorted[j + 1] = swap;
            }
        }
    }
    for (i = 0; i < numStudents; i++)
    {
        scanf("%s", name);
        for (j = 0; j < numStudents; j++)
        {
            if (gradesSorted[j] == grades[i])
            {
                printf("%s rank is %d\n", name, j + 1);
            }
        }
    }
    return 0;
}