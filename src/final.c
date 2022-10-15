#include <stdio.h>
//add additional header files here
#include <math.h>

struct star
{
    char name[50];
    int temperature;
    double luminosity;
    double radius;
    char classification;
};

void printStars(struct star mystars[], int N);
//add your propotypes here
int readStars(struct star *);
void computeRadii(struct star *, int);
void classifyStars(struct star *, int);

// Do not modify the main() function!
int main(void)
{
    struct star mystars[50];
    int N;

    N = readStars(mystars);
    computeRadii(mystars, N);
    classifyStars(mystars, N);
    printStars(mystars, N);

    return 0;
}

// Do not modify the printStars() function!
void printStars(struct star mystars[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%s is a ", mystars[i].name);
        if (mystars[i].classification == 'M')
        {
            printf("Main Sequence Star\n");
        }
        else if (mystars[i].classification == 'G')
        {
            printf("Giant\n");
        }
        else if (mystars[i].classification == 'S')
        {
            printf("Supergiant\n");
        }
        else if (mystars[i].classification == 'W')
        {
            printf("White Dwarf\n");
        }
        else if (mystars[i].classification == 'N')
        {
            printf("Unclassified Star\n");
        }
        else
        {
            printf(" !!! Warning: '%c' not a valid classification code!!!\n", mystars[i].classification);
        }
        printf("Temp = %d Kelvin, Lum = %.4lf Sol, Rad = %.2lf * R_Sun\n\n", mystars[i].temperature, mystars[i].luminosity, mystars[i].radius);
    }
}

//add the functions readStars(), computeRadii() and classifyStars() here.
int readStars(struct star *star)
{
    FILE *ifile;
    char filename[] = "stardata.txt";
    int completed, counter, n;

    ifile = fopen(filename, "r");

    completed = 0;
    counter = 0;
    n = 0;

    while (completed != EOF)
    {
        if (counter == 0)
        {
            completed = fscanf(ifile, "%s", star[n].name);
            counter++;
        }
        else if (counter == 1)
        {
            completed = fscanf(ifile, "%d", &star[n].temperature);
            counter++;
        }
        else if (counter == 2)
        {
            completed = fscanf(ifile, "%lf", &star[n].luminosity);
            counter = 0;
            n++;
        }
    }

    // remember to close file access
    fclose(ifile);

    return n;
}

void computeRadii(struct star *star, int N)
{
    double Ts = 3500.0;
    int i;

    for (i = 0; i < N; i++)
    {
        star[i].radius = pow((Ts / star[i].temperature), 2) * pow(star[i].luminosity, 0.5);
    }
}

void classifyStars(struct star *star, int N)
{
    int i;

    for (i = 0; i < N; i++)
    {
        if ((star[i].luminosity >= pow(10, -2) && star[i].luminosity < pow(10, 6)) && (star[i].radius >= 0.1 && star[i].radius < 10))
            star[i].classification = 'M';
        else if ((star[i].luminosity >= pow(10, 3) && star[i].luminosity < pow(10, 5)) && (star[i].radius >= 10 && star[i].radius < 100))
            star[i].classification = 'G';
        else if ((star[i].luminosity >= pow(10, 5) && star[i].luminosity < pow(10, 6)) && (star[i].radius > 100))
            star[i].classification = 'S';
        else if (star[i].radius < 0.01)
            star[i].classification = 'W';
        else
            star[i].classification = 'N';
    }
}