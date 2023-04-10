#ifndef INTERRUPTS_LIBRARY_H_
#define INTERRUPTS_LIBRARY_H_

/**
* @brief Macro for the expansion of the declaration and definition of ISR functions.
*/
#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

/**
* @brief External interrupt request 0.
*/
#define EXT_INT0 __vector_1

/**
* @brief External interrupt request 1.
*/
#define EXT_INT1 __vector_2

/**
* @brief External interrupt request 2.
*/
#define EXT_INT2 __vector_3

#endif /* INTERRUPTS_LIBRARY_H_ */