#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;

    // Input from user
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Performing operations
    printf("\n--- Results ---\n");
    printf("Addition: %d\n", num1 + num2);
    printf("Subtraction: %d\n", num1 - num2);
    printf("Multiplication: %d\n", num1 * num2);

    // Handling division and modulus safely
    if (num2 != 0) {
        printf("Division: %d\n", num1 / num2);
        printf("Modulus: %d\n", num1 % num2);
    } else {
        printf("Division: Undefined (division by zero)\n");
        printf("Modulus: Undefined (modulus by zero)\n");
    }

    return 0;
}
