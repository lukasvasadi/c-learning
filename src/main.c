/*
  To compile and run:
    gcc -o binaryfile sourcefile.c
    ./binaryfile (or .\binaryfile for Windows)
*/

#include <stdio.h>

// every c-program needs a main function
int main(void)
{
    int i; // declare integer variable
    int x;

    printf("Please enter a number: ");
    scanf("%d", &x);

    for (i = 0; i < 10; i++)
    {
        printf("%d\n", i * x); // print int var
    }

    char a; // declare character variable
    char b;
    char c;

    a = 'a'; // define/initialize/assign character var with single quotations

    printf("The first letter of the alphabet is %c\n", a); // print char var

    printf("Please enter two characters separated by a space: ");
    scanf("%c %c", &b, &c);
    printf("Your input was %c and %c", b, c);

    double h; // declare floating point variable

    printf("Please input your height in meters: ");
    scanf("%lf", h);
    printf("My height is %.2lf meters\n", h); // print with two decimal points

    // read ints and doubles with one scanf statement
    int age;
    double height;

    printf("What is your age and height (please separate input with a space)? ");
    scanf("%d %lf", &age, &height);
    printf("You are %d years old and %.2lf meters tall", age, height);

    // casting
    printf("Your age as a double is %lf", (double)age);

    return 0;
}