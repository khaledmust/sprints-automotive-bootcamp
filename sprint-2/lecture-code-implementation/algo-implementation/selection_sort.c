#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selection_sort(int *input_array, int array_size) {
    int minimum_element_index = 0;
    int i, j;
    for (i = 0; i < array_size; i++) {
        minimum_element_index = i;
        for (j = i; j < array_size; j++) {
            if (input_array[minimum_element_index] > input_array[j]) {
                minimum_element_index = j;
            }
        }
        swap(&input_array[minimum_element_index], &input_array[i]);
    }
}

void print_array(int *input_array, int array_size) {
    int i;
    for (i = 0; i < array_size; i++) {
        printf("%d  ", input_array[i]);
    }
    printf("\n");
}

int main(void) {
    int user_array[] = {12, 30, 1, 7, 16, 20, 15};
    print_array(user_array, 7);
    selection_sort(user_array, 7);
    print_array(user_array, 7);
}