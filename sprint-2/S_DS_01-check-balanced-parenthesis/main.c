#include <stdio.h>
//#include "stack.h"
#include "balanced.h"

int main() {
//    __testStack();
    uint8_t myString[50] = "{(2+3)/(<3+3>*(15-10))}";
    isBalancedParanthethes(myString);
    return 0;
}
