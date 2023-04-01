#include <stdio.h>
#include <math.h>

int jmp_search(int *input_array, int target_element, int array_size);

int main(void) {
    int data_array[] = {0, 1, 2, 3, 4, 5, 10, 20, 30, 40, 50, 100, 1000, 5000};
    jmp_search(data_array, 40, 13);
}

int jmp_search(int *input_array, int target_element, int array_size) {
    int start_index = 0;
    int end_index = array_size - 1;
    int jmp_index = sqrt((double)array_size) - 1;
    int target_index = 0;

    while (start_index < end_index) {

    printf("The index is: %d", target_element);
}