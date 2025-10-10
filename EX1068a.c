#include <stdio.h>
#include <string.h>

int main() {
    char expr[1001]; // até 1000 caracteres + '\0'

    while (fgets(expr, sizeof(expr), stdin) != NULL) {
        int balance = 0;
        int correct = 1;

        for (int i = 0; expr[i] != '\0'; i++) {
            if (expr[i] == '(') {
                balance++;
            } else if (expr[i] == ')') {
                if (balance > 0)
                    balance--;
                else {
                    correct = 0; // encontrou ')' sem '('
                    break;
                }
            }
        }

        if (balance != 0)
            correct = 0;

        if (correct)
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}