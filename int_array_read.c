/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

void int_array_read(int *array, int size) {

	// your code here
	int count = 0;
	char input[STRING_SMALL];

	printf("Enter %d values for an array of int.\n", size);
	while (count < size) {
		printf("Value for index %d: ", count);
		if (fgets(input, STRING_SMALL, stdin)) {
			if (sscanf(input, "%d", &array[count]) == 1) {
				count++;
			} else {
				printf("Not a valid integer\n");
			}
		}
	}
}
