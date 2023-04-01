#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertion_sort(int *input_array, int array_size) {
    for (int i = 1; i < array_size; i++) {
        int current_element = input_array[i];
        int sorted_array_index = i - 1;
        while (sorted_array_index >= 0 && input_array[sorted_array_index] > current_element) {
            input_array[sorted_array_index + 1] = input_array[sorted_array_index];
            sorted_array_index--;
        }
        input_array[sorted_array_index + 1] = current_element;
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
    insertion_sort(user_array, 7);
    print_array(user_array, 7);
}