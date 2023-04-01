#include "main.h"

int main() {

    uint8_t user_string[ARRAY_SIZE];
    printf("Enter the expression to want to check: ");
    scanf("%s", user_string);

    int8_t expression_state = isBalancedParanthethes(user_string);
    if (expression_state == BALANCED_PARENTHESES) {
        printf("The expression is balanced.\n");
    } else if (expression_state == IMBALANCED_PARENTHESES) {
        printf("The expression is not balanced.\n");
    } else if (expression_state == INVALID_PARENTHESES) {
        printf("The expression doesn't have any parentheses.");
    }

    return 0;
}
