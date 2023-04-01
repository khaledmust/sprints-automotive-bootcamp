#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int *input_array, int array_size) {
    int i;
    int j;
    for (i = 0; i < array_size; i++) {
        for (j = 0; j < array_size - i; j++) {
            if (input_array[j] > input_array[j + 1]) {
                swap(&input_array[j], &input_array[j + 1]);
            }
        }
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
    bubble_sort(user_array, 7);
    print_array(user_array, 7);
}