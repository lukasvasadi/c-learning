/*
  Read a list of grades from a text file. Prompt user for 
  a grade to compare with the last entry. If grades are not 
  equal, append the grade to the list. Print all grade entries.
*/

#include <stdio.h>

int main(void)
{
    FILE *file;
    char filename[] = "grades.txt";
    int grade, recordedGrade;

    // prompt user for grade to compare
    scanf("%d", &grade);

    file = fopen(filename, "r");

    // this will leave the last grade stored in the variable
    while (fscanf(file, "%d", &recordedGrade) != EOF)
        ;
    fclose(file);

    if (grade != recordedGrade)
    {
        file = fopen(filename, "a");
        fprintf(file, " %d", grade);
        fclose(file);
    }

    file = fopen(filename, "r");
    while (fscanf(file, "%d", &recordedGrade) != EOF)
    {
        printf("%d ", recordedGrade);
    }
    printf("\n");

    return 0;
}