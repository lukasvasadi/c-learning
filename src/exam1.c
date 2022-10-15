#include <stdio.h>

int main(void)
{
    int i;
    int rolls;
    int red;
    int yellow;
    int green;
    int sum;
    int sumTotal = 0;
    double avg;

    scanf("%d", &rolls);

    for (i = 1; i < rolls + 1; i++)
    {
        scanf("%d %d %d", &red, &yellow, &green);

        sum = red + yellow * 10 + green * 100;
        sumTotal += sum;
        avg = (double)sumTotal / (double)i;

        printf("%d. you rolled: %d, current average: %.1lf\n", i, sum, avg);
    }

    return 0;
}