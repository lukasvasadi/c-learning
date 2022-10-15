#include <stdio.h>

int main(void)
{
    FILE *ifile;
    int i, n, grade;
    double avg;

    // open text file for read access
    ifile = fopen("data_file.txt", "r");

    // store the first number in n
    fscanf(ifile, "%d", &n);

    // initialize grade avg
    avg = 0;

    // record each grade and calculate avg
    for (i = 0; i < n; i++)
    {
        fscanf(ifile, "%d", &grade);
        avg += (double)grade;
    }
    avg = avg / (double)n;
    printf("%.2lf", avg);

    fclose(ifile);

    return 0;
}