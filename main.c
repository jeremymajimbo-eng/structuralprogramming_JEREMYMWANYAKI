#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 1234;
    int y ;
    int choice;


    printf("enter pin: ");
    scanf("%d", &y);

     if (x==y){
        printf("Access granted\n");

        printf("Select an action below:\n");
        printf("1 - Open door\n");
        printf("2 - Change username\n");
        printf("3 - Change Pin\n");
        printf("4 - Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);


    switch (choice) {
    case 1:
        printf( "Door is opening...");
        break;

    case 2:
        printf("Username change selected");
        break;

    case 3:
        printf("Pin change selected");
        break;

    case 4:
        printf("Existing system");
        break;

    default:
        printf("Invalid option");
    }

    }else {
       printf("Wrong pin! Access denied");

    }
          return 0;
}
