#include <stdio.h>
#include <stdlib.h>

struct digit
{
    int num;
    struct digit *next;
};

struct digit *readNumber(void);
struct digit *createDigit(int dig);
struct digit *append(struct digit *end, struct digit *newDigptr);
void printNumber(struct digit *start);
void freeNumber(struct digit *start);

//add your prototype(s) here
struct digit *reverseNumber(struct digit *start);

int main(void)
{
    struct digit *start, *backwards;
    start = readNumber();
    backwards = reverseNumber(start);
    printf("The reverse of ");
    printNumber(start);
    printf("is ");
    printNumber(backwards);

    freeNumber(start);
    freeNumber(backwards);
    return 0;
}

struct digit *createDigit(int dig)
{
    struct digit *ptr;
    ptr = (struct digit *)malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit *append(struct digit *end, struct digit *newDigptr)
{
    end->next = newDigptr;
    return (end->next);
}

void printNumber(struct digit *start)
{
    struct digit *ptr = start;
    while (ptr != NULL)
    {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start)
{
    struct digit *ptr = start;
    struct digit *tmp;
    while (ptr != NULL)
    {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit *readNumber(void)
{
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n')
    {
        d = c - 48;
        newptr = createDigit(d);
        if (start == NULL)
        {
            start = newptr;
            end = start;
        }
        else
        {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return (start);
}

//add your reverseNumber() function here
struct digit *reverseNumber(struct digit *start)
{
    struct digit *backwards = NULL;
    struct digit *ptr = start;
    struct digit *ref;

    // ensure that user entered number
    if (start != NULL)
    {
        // initialize new list
        backwards = createDigit(ptr->num);
        while (ptr->next != NULL)
        {
            ref = createDigit(ptr->next->num);
            ref->next = backwards;
            backwards = ref;
            ptr = ptr->next;
        }
    }
    return backwards;
}