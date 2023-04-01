
#ifndef S_ALG_SORT_H
#define S_ALG_SORT_H

#include <stdint.h>

/**
 * @brief Performs insertion sorting algorithm.
 * @param[in,out] array Address of the array to be sorted.
 * @param[in] arraySize Size of the input array.
 * @return -1 Array is empty.
 * @return -2 Array size is 0 or >10.
 * @return 0 Sorting is done without errors.
 */
int8_t insertionSort(int32_t *array, uint8_t arraySize);

#endif //S_ALG_SORT_H
