#include "sort.h"

/**
 * @brief Performs insertion sorting algorithm.
 *
 * Sorts the array in ascending order.
 *
 * @param[in,out] array Address of the array to be sorted.
 * @param[in] arraySize Size of the input array.
 * @return -1 Array is empty.
 * @return -2 Array size is 0 or >10.
 * @return 0 Sorting is done without errors.
 */
int8_t insertionSort(int32_t *array, uint8_t arraySize) {
    for (int i = 1; i < arraySize; i++) {
        int current_element = array[i];
        int sorted_array_index = i - 1;
        while (sorted_array_index >= 0 && array[sorted_array_index] > current_element) {
            array[sorted_array_index + 1] = array[sorted_array_index];
            sorted_array_index--;
        }
        array[sorted_array_index + 1] = current_element;
    }
}
