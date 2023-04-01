#include "lcs.h"

/**
 * @brief Prints all the elements of input array.
 * @param array[in] Reference to an array of integers to be printed.
 * @param arraySize[in] Size of the reference array.
 */
void printArray(int32_t *array, uint8_t arraySize) {
    int i;
    for (i = 0; i < arraySize; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

/**
 * @brief Prompts the user to enter the array size and then allocates the array.
 * @param array[out] Reference to a reference of an array.
 * @param arraySize[out] Reference to the size of the array.
 * @return -1 Array is empty.
 * @return -2 Array size is 0 or >10.
 * @return 0 Prompting and allocation is done without errors.
 */
int8_t promptUser(int32_t **array, uint8_t *arraySize) {
    /* Get the size of the array. */
    int tmp_user_input;
    printf("Enter the array size: ");
    scanf("%d", &tmp_user_input);
    *arraySize = tmp_user_input;
    if (*arraySize == 0 || *arraySize > 10) {
        printf("Error! Array size could only be greater than 0 and less than 10.\n");
        return INVALID_ARRAY_SIZE;
    }

    /* Allocating the required array on the heap. */
    *array = (int32_t*) malloc(sizeof (uint32_t) * (*arraySize));

    /* Get the content of the array. */
    printf("Enter your array: ");
    for (uint8_t i = 0; i < *arraySize; i++) {
        scanf("%d", (*array + i));

        if (array[0] == '\n') {
            printf("Error! Element can't be empty.\n");
            return EMPTY_ARRAY;
        }
    }
    return SUCCESS;
}

/**\
 * @brief Takes a reference to an array and calculates the longest consecutive subsequence.
 * @param array[in] Reference the input array.
 * @param arraySize[in] Size of the array.
 * @param sizeofLCS[out] Reference to store the longest consecutive subsequence.
 * @return -1 The array is empty
 * @return -2 The array size is 0 or >10
 * @return -3 There is no LCS,
 */
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS) {
    if (arraySize == NULL) {
        return EMPTY_ARRAY;
    } else if (arraySize == 0 || arraySize > 10) {
        return INVALID_ARRAY_SIZE;
    } else {
        uint8_t length = 1;
        /* Iterating over every element and comparing it with the one after, if it's equal then the two elements
         * are considered consecutive.
         */
        for (int i = 0; i < arraySize; i++) {
            if (array[i] == array[i + 1]) {
                continue;
            } else if (i > 0 && array[i] == array[i - 1] + 1) {
                length++;
            } else {
                length = 1;
            }
            /* Preserve the current consecutive length. */
            if (*sizeofLCS < length) {
                *sizeofLCS = length;
            }
        }
        /* There is no consecutive elements. */
        if (*sizeofLCS == 1) {
            return NO_LCS;
        } else {
            return SUCCESS;
        }
    }
}