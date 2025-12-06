#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int login() {
        const char stored_pin[] = "1234";
        char entered_pin[10];
        int max_attempts = 3;

        for (int attempt = 1; attempt <= max_attempts; attempt++) {

            printf("Enter your PIN: ");
            scanf("%s", entered_pin);

            if (strcmp(entered_pin, stored_pin) == 0) {
                printf("login successful!\n");
                return 1;
            } else {
                printf("Incorrect PIN. Attempts remaining: %d\n", max_attempts - attempt);

            }
        }

        printf("Maximum attempts exceeded. Access denied.\n");
        return 0;
}

int main() {
    login();
    return 0;
}
