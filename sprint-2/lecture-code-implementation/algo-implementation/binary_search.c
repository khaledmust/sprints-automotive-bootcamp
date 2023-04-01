#include <stdio.h>

int main(void) {
    int data_array[] = {0, 1, 2, 3, 4, 5, 10, 20, 30, 40, 50, 100, 1000, 5000};
    int size_of_array = sizeof(data_array)/sizeof(int);

    int array_start = 0;
    int array_end = size_of_array - 1;
    int array_middle = (array_end + array_start) / 2;

    int target_element = 50;
    int index = 0;

    while(array_start <= array_end) {
        if (target_element == data_array[array_middle]) {
            index = array_middle;
            break;
        } else if (target_element > data_array[array_middle]) {
            array_start = array_middle + 1;
            array_middle = (array_end + array_start) / 2;
        } else if (target_element < data_array[array_middle]) {
            array_end = array_middle - 1;
            array_middle = (array_end + array_start) / 2;
        }
    }
    printf("The index of the target element: %d", index);
}