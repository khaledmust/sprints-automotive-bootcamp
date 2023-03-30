#include <stdio.h>
//#include "stack.h"
#include "balanced.h"

int main() {
    /* Uncomment to test the stack implementation. */
//    __testStack();

    uint8_t user_string[50];
    printf("Enter the expression to want to check: ");
    scanf("%s", user_string);

    isBalancedParanthethes(user_string);
    return 0;
}
