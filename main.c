#include <stdio.h>
#include <string.h>   // <-- REQUIRED for strlen()

int main()
{
    char name[100];

    printf("Enter a string: ");
    scanf("%s", name);

    printf("You entered: %s\n", name);

    int length = strlen(name);

    printf("Length of the string: %d\n", length);

    return 0;
}

