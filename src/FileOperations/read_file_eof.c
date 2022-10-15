/*
  Read a list of grade averages from a file and 
  compare class performances
*/

#include <stdio.h>

int main(void)
{
    FILE *ifile;
    double classAvg, highestAvg;
    int n, counter;

    ifile = fopen("grade_averages.txt", "r");

    counter = 0;
    n = 0;

    // compare remaining classes
    while (fscanf(ifile, "%lf", &classAvg) != EOF)
    {
        if (!counter)
            highestAvg = classAvg;
        else
        {
            if (classAvg > highestAvg)
            {
                highestAvg = classAvg;
                n = counter;
            }
        }
        counter++;
    }

    if (n == 0)
        printf("Yes\n");
    else
        printf("No %d\n", n);

    fclose(ifile);

    return 0;
}