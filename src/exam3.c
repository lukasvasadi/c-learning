#include <stdio.h>
int getSize(char *);
int isReverse(char *, char *);
int main(void)
{
    char str1[100], str2[100];
    int result;

    scanf("%s", str1);
    scanf("%s", str2);

    result = isReverse(str1, str2);

    if (result)
        printf("%s is the reverse of %s\n", str1, str2);
    else
        printf("%s is not the reverse of %s\n", str1, str2);

    return 0;
}
int getSize(char *str)
{
    int i;

    for (i = 0; i < 100; i++)
    {
        if (*(str + i) == '\0')
            return i;
    }
    return 0;
}
int isReverse(char *str1, char *str2)
{
    int i;
    int size1, size2;

    size1 = getSize(str1);
    size2 = getSize(str2);

    if (size1 == size2)
    {
        // perform character cross-reference
        for (i = 0; i < size1; i++)
        {
            if (*(str1 + i) != *(str2 + (size2 - (i + 1))))
                // strings are not reversed copies
                return 0;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}